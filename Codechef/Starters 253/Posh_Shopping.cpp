#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, c[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (c[i] <= c[j])
                {
                    ans = max(ans, c[i] + c[j]);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}