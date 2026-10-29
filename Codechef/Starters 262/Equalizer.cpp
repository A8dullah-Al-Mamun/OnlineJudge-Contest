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
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll b = 0;
        for (int i = 0; i < n - 1; i++)
            if (a[i] == a[i + 1])
                b++;

        ll max_f = 0, dfrnc = 0;

        for (int r = 0; r < n; r++)
        {
            ll f = 0, g = 0;

            if (r > 0)
            {
                if (a[r - 1] == a[r])
                    f = -1;
                else if (a[r - 1] == a[r] + 1)
                    f = 1;
            }

            max_f = max(max_f, f);

            if (r + 1 < n)
            {
                if (a[r] == a[r + 1])
                    g = -1;
                else if (a[r] + 1 == a[r + 1])
                    g = 1;
            }

            ll x = max_f + g;
            dfrnc = max(dfrnc, x);
        }

        ll ans = dfrnc + b;
        cout << ans << endl;
    }

    return 0;
}