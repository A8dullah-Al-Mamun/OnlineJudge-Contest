#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll x = 1;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            x++;
        }
    }

    ll ans = x;
    for (ll i = 1; i < n - 1; i++)
    {
        ll old = 0;
        if (s[i - 1] != s[i])
        {
            old += 1;
        }
        if (s[i] != s[i + 1])
        {
            old += 1;
        }

        ll new_sz = 0;
        if (s[i - 1] != s[i + 1])
        {
            new_sz = 1;
        }

        ll curr = x + new_sz - old;

        if (curr < ans)
        {
            ans = curr;
        }
    }

    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}