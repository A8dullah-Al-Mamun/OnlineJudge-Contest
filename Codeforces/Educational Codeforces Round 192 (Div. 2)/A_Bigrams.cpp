#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;

        int count = 0;
        bool ok = false;
        
        for (int i = 0; i < k; i++)
        {
            int c;
            cin >> c;
            if (c >= 3)
                ok = true;
            else if (c == 2)
                count++;
        }
        if (ok || count >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}