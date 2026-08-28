#include <bits/stdc++.h>
using namespace std;

int nxtmul(int n)
{
    if (n % 5 == 0)
        return n + 5;

    return n + (5 - n % 5);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n % 3 == 0)
        {
            cout << 0 << '\n';
            continue;
        }

        bool temp = false;

        if ((n + 1) % 3 == 0)
            temp = true;

        if (nxtmul(n) % 3 == 0)
            temp = true;

        if (temp)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 2 << '\n';
        }
    }

    return 0;
}