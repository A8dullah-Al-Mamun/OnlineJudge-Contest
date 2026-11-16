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
        char c = 'R';
        for (int i = 0; i < n; i++)
        {
            if (c != s[i])
            {
                ans++;
                // blue
                c = s[i];
            }

            if (c == 'R')
                c = 'B';
            else
                c = 'R';
        }
        cout << ans << endl;
    }

    return 0;
}