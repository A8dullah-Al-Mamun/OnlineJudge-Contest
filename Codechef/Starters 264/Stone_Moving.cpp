#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, ans = 0, cur = 0;
        cin >> n;

        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];

        vector<ll> b(n + 3, 0);

        for (ll i = 1; i <= n; i++)
        {
            ll st = 0, m;

            cur += b[i];
            st = a[i] + cur;
            m = min(st, n - i);

            ans += m;
            if (m > 0)
            {
                b[i + 1]++;
                b[i + m + 1]--;
            }
        }

        cout << ans << endl;
    }

    return 0;
}