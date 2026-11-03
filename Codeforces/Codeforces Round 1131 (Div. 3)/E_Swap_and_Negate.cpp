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
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
    // Check
            if (i % 2 == 0)
                a[i] = x;
            else
                a[i] = -x;
        }

        sort(a.begin(), a.end());
        ll positive = (n + 1) / 2, neg = n / 2, ans = 0;
        int l_i = n - positive;

        for (int i = l_i; i < n; i++)
            ans += a[i];

        for (int i = 0; i < neg; i++)
            ans = ans - a[i];

        cout << ans << endl;
    }

    return 0;
}