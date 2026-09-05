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

        int maxTime = 0;
        int count = 0;
        for (char c : s)
        {
            if (c == '#')
            {
                count++;
            }
            else
            {
                if (count > 0)
                {
                    maxTime = max(maxTime, (count + 1) / 2);
                    count = 0;
                }
            }
        }
        if (count > 0)
        {
            maxTime = max(maxTime, (count + 1) / 2);
        }

        cout << maxTime << '\n';
    }

    return 0;
}