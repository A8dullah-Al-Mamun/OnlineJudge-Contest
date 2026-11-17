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

        for (int i = 0; i < n; i++)
        {
            int p = i - 1;
            if (p < 0)
                p = n - 1;

            int a = s[p] - '0', b = s[i] - '0';
            int x = a * 10 + b;

            if (x % 4 == 0)
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}