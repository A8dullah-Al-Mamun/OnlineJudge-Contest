#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int n;
        string a, b;
        cin >> n >> a >> b;

        int count = 0, count_2 = 0;
        int even = 0, even_2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                count++;
                if (i % 2 == 0)

                    even++;
            }
            if (b[i] == '1')
            {
                count_2++;
                if (i % 2 == 0)
                    even_2++;
            }
        }

        if (count == count_2 && even == even_2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}