#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        int zeros = 0, ones = 0;
        for (char c : s) {
            if (c == '0') zeros++;
            else ones++;
        }

        vector<int> run;
        run.reserve(n);

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            run.push_back(s[i] - '0');
            i = j;
        }

        int delta = zeros - ones;

        if (delta > 2 || delta < -2) {
            cout << -1 << '\n';
            continue;
        }

        const int NEG = -1e9;

   
        int dp[2][2][2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    dp[i][j][k] = NEG;

        for (int i = 0; i < (int)run.size(); i++) {
            int p = i & 1;
            int v = run[i];

            dp[p][v][1] = max(dp[p][v][1], 1);

            for (int sv = 0; sv < 2; sv++) {
                for (int lenPar = 0; lenPar < 2; lenPar++) {
                    if (dp[1 - p][sv][lenPar] > 0) {
                        dp[p][sv][lenPar ^ 1] = max(
                            dp[p][sv][lenPar ^ 1],
                            dp[1 - p][sv][lenPar] + 1
                        );
                    }
                }
            }
        }

        int ans[2][2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                ans[i][j] = NEG;

        for (int p = 0; p < 2; p++)
            for (int sv = 0; sv < 2; sv++)
                for (int lenPar = 0; lenPar < 2; lenPar++)
                    ans[sv][lenPar] = max(ans[sv][lenPar], dp[p][sv][lenPar]);

        int best = 0;


        if (abs(delta) <= 1) {
            best = max(best, ans[0][0]);
            best = max(best, ans[1][0]);
        }

        if (delta >= 0 && delta <= 2) {
            best = max(best, ans[0][1]);
        }

        if (delta <= 0 && delta >= -2) {
            best = max(best, ans[1][1]);
        }

        cout << n - best << '\n';
    }

    return 0;
}