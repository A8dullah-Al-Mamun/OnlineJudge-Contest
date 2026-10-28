
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll l = 1, r = 2000000000, ans = r;

        while (l <= r)
        {
            ll mid = l + (r - l) / 2;

            vector<ll> b;
            for (int i = 0; i < n; i++)
            {
                bool left = (i > 0 && a[i] - a[i - 1] <= mid);
                bool right = (i < n - 1 && a[i + 1] - a[i] <= mid);

                if (!left && !right)
                    b.push_back(i);
            }

            ll m = b.size(), cnt = 0, i = 0;

            while (i < m - 1)
            {
                if (b[i + 1] == b[i] + 1 && a[b[i + 1]] - a[b[i]] <= 2 * mid)
                {
                    cnt++;
                    i += 2;
                }
                else
                    i++;
            }

            if (m - cnt <= x)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        cout << ans << endl;
    }

    return 0;
}
