#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        
        int p, q, r;
        cin >> p >> q >> r;

        int ans = INT_MAX;

        for (int i = 0; i <= min(a, b); i++)
        {
            int right = (a - i + 1) / 2;
            int up = (b - i + 1) / 2;

            int cost = i * r + right * p + up * q;

            ans = min(ans, cost);
        }

        cout << ans << endl;
    }

    return 0;
}