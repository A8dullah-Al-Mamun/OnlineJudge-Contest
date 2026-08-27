#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        long long n, k;
        cin >> n >> k;

        long long sum = 0, max_num = 0;
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;

            sum += x;
            max_num = max(max_num, x);

            if (sum - max_num <= k)
            {
                ans = i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}