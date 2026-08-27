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

        int max_beauty = 0;
        int zero_one = 0;
        int one_zero = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                max_beauty++;
            }
            else
            {
                if (s[i] == '0')
                    zero_one++;
                else
                    one_zero++;
            }
        }

        if (zero_one >= 2 || one_zero >= 2)
            max_beauty += 2;
            
        else if (zero_one >= 1 && one_zero >= 1)
            max_beauty++;

        cout << max_beauty << endl;
    }

    return 0;
}