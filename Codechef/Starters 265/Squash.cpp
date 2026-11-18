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
        ll n, k, i, ans = 1;
        cin >> n >> k;

        string s;
        cin >> s;

        for (i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
                ans++;
        }
        if (k >= ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
// easy 
    return 0;
}