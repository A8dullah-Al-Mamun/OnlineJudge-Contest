#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;

        cin >> n >> k;
        string s;
        cin >> s;

        int z = count(s.begin(), s.end(), '0');
        int one = n - z;

        if (z < k || one < k)
        {
            cout << s << '\n';
            continue;
        }

        if (z == k && one == k)
        {
            string change = s;

            for (char &c : change)
            {
                c = (c == '0') ? '1' : '0';
            }

            cout << min(s, change) << '\n';
            continue;
        }

        string ans(z, '0');
        ans += string(one, '1');

        cout << ans << '\n';
    }

    return 0;
}