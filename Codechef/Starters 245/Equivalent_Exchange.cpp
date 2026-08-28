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

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        bool possible = false;

        for (int x = 0; x <= k; ++x)
        {
            int red = x;
            int blue = k - x;
            bool ok = true;

            for (int i = 0; i < n; i++)
            {
                red += a[i];
                blue -= a[i];

                if (red < 0 || blue < 0)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                possible = true;
                break;
            }
        }

        if (possible)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}