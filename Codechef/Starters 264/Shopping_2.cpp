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
        ll n, d;
        cin >> n >> d;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        ll sum = 0, sum1 = 0, sum2 = 0, x, y, z;

        for (int i = 0; i < n; i++)
        {
            sum1 = sum1+a[i];
            sum2 = sum2+ b[i];

            if (a[i] < b[i])
                sum += a[i];
            else
                sum += b[i];
        }

        x = d + sum1;
        y = d + sum2;
        z = (2 * d) + sum;
        ll m= min(y,z);
        ll ans = min(x, m);

        cout << ans << endl;
    }

    return 0;
}