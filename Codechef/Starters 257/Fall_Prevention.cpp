#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n + 1), pfx(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pfx[i] = pfx[i - 1] + a[i];
        }

        int f1 = 0;

        for (int i = 1; i <= n; i++)
        {
            if (pfx[i] < 0)
            {
                f1 = i;
                break;
            }
        }

        if (f1 == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        vector<long long> sfx(n + 2, LLONG_MAX);
        for (int i = n; i >= 1; i--)
        {
            sfx[i] = min(pfx[i], sfx[i + 1]);
        }

        bool ok = false;
        for (int j = 1; j <= f1; j++)
        {
            long long mn = sfx[j + 1];

            if (a[j] <= mn)
            {
                ok = true;
                break;
            }
        }

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}