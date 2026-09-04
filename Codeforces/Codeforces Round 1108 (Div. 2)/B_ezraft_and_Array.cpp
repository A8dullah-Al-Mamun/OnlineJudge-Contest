#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }

        if (n == 2) {
            cout << -1 << '\n';
            continue;
        }

        vector<long long> a = {1, 2, 3};
        long long sum = 6;

        for (int i = 4; i <= n; i++) {
            a.push_back(sum);
            sum += sum;
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }

    return 0;
}