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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int l = n - k;

        vector<int> p(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            p[i + 1] = p[i] + a[i];
        }

        int ans = 0;

        for (int i = 0; i + l <= n; i++)
        {
            int sum = p[i + l] - p[i];
            ans = max(ans, sum);
        }

        cout << ans << endl ;
    }

    return 0;
}