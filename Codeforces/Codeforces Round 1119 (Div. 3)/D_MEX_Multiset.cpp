#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] == 0)
                cnt++;
        }

        if (cnt == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        string s(n, 'A');

        int seen_zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                seen_zero++;

                if (seen_zero == 1)
                    s[i] = 'A';
                else if (seen_zero == 2)
                    s[i] = 'B';
                else
                    s[i] = 'A';
            }
            else
            {
                s[i] = 'C';
            }
        }

        cout << s << endl;
    }

    return 0;
}
