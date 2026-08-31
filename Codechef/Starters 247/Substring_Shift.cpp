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
        cin >> n;
        cin >> s;

        int pos = -1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'z')
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            cout << s << '\n';
            continue;
        }

        int j = pos;
        while (j < n && s[j] == 'z')
        {
            j++;
        }

        for (int i = pos; i < j; i++)
        {
            s[i] = 'a';
        }

        cout << s << '\n';
    }

    return 0;
}