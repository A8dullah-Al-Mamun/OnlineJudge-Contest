#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int p = n, x = 0;

        for (int i = 1; i <= n; i++)
        {
            x = a[i] - x;
            if (x < 0)
            {
                p = i - 1;
                break;
            }
        }

        int s = 1, y = 0;

        for (int i = n; i >= 1; i--)
        {
            y = a[i] - y;
            if (y < 0)
            {
                s = i + 1;
                break;
            }
        }

        int l = max(1, s - 1);
        int r = min(n, p + 1);

        cout << max(0, r - l + 1) << '\n';
    }

    return 0;
}