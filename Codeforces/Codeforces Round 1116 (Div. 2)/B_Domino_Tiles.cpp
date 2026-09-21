#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int ans = 0;

        for (int a = 0; a <= 1; a++)
        {
            for (int b = 0; b <= 1; b++)
            {
                bool ok = true;

                for (int i = 0; i < n; i++)
                {
                    if (s[i] == '?')
                        continue;

                    int x;

                    if (i % 4 == 0)
                        x = a;
                    else if (i % 4 == 1)
                        x = b;
                    else if (i % 4 == 2)
                        x = 1 - a;
                    else
                        x = 1 - b;

                    if (s[i] - '0' != x)
                    {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}