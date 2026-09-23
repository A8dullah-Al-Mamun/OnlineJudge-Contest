#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> c(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> c[i];
        }

        int ans = INT_MAX;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                bool possible = true;

                for (int pos = 1; pos <= n; pos++)
                {
                    if (abs(pos - i) > k && abs(pos - j) > k)
                    {
                        possible = false;
                        break;
                    }
                }

                if (possible)
                {
                    ans = min(ans, c[i] + c[j]);
                }
            }
        }

        if (ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}