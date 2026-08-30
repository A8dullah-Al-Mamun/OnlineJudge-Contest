#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, p;
        cin >> n >> p;

        string s;
        cin >> s;

        int left = 0;

        for (int i = 0; i < p; i++)
        {
            if (s[i] == 'R')
            {
                left++;
            }
        }

        int right = 0;
        
        for (int i = p - 1; i < n; i++)
        {
            if (s[i] == 'L')
            {
                right++;
            }
        }

        cout << min(left, right) << '\n';
    }

    return 0;
}