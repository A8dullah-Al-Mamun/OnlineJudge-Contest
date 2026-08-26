#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, j;
        cin >> x >> j;

        long long ans = 0;
        for (int i = j + 1; i <= x; ++i)
        {
            ans += (i + 9) / 10;
        }

        cout << ans << '\n';
    }

    return 0;
}