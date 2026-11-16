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
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];

        ll s = k + 1, ans = 0;

        for (ll i = 1; i <= n; i += s)
        {
            if (a[i] % 2 == 1)
                ans = 1 - ans;
        }

        if (ans == 1)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }

    return 0;
}