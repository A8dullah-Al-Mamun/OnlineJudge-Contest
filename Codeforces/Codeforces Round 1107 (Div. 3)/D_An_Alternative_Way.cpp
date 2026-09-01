#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int64> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int64> B(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int64 d = b[i - 1] - a[i - 1];
            if (i & 1)
                B[i] = -d;
            else
                B[i] = d;
        }

        int64 low = 0, high = 0;
        int64 prev_B = 0;
        bool ok = true;

        for (int i = 1; i <= n && ok; i++)
        {
            int64 cur_B = B[i];
            if (i & 1)
            {
                int64 need = max(0LL, cur_B);
                if (high < need)
                    ok = false;
                else
                {
                    low = need;
                    high = high;
                }
            }
            else
            {
                int64 need = prev_B + max(0LL, -cur_B);
                if (high < need)
                    ok = false;
                else
                {
                    low = max(0LL, cur_B);
                    high = high + (cur_B - prev_B);
                }
            }
            prev_B = cur_B;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}