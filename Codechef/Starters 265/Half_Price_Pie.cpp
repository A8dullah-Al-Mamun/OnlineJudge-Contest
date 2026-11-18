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
        ll n, i;
        cin >> n;

        vector<int> a(n);
        ll total = 0, mn = LLONG_MAX;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            total += a[i];
        }

        for (i = 0; i < n - 1; i++)
        {
            ll loss = (a[i] + a[i + 1]) / 2;
            mn = min(mn, loss);
        }

        cout << total - mn << endl;
    }

    return 0;
}