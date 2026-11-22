#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n < 4)
        {
            cout << -1 << endl;
            continue;
        }

        vector<ll> v(n + 1);
        for (ll j = 0; j <= n; j++)
            v[j] = j;

        swap(v[1], v[4]);

        for (ll i = 1; i <= n; i++)
            cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}