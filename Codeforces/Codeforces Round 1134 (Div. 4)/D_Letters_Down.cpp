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
        ll n, ans = 0;
        string s;
        cin >> n >> s;

        bool leter[26] = {false};

        for (ll i = 0; i < n / 2; i++)
        {
            ll a , b ;
            a = s[i] - 'a';
            b = s[n - 1 - i] - 'a';

            if (a > b)
            {
                swap(a, b);
            }

            for (ll j = a + 1; j <= b; j++)
                leter[j] = true;
        }

        for (ll i = 1; i < 26; i++)
        {
            if (leter[i])
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}