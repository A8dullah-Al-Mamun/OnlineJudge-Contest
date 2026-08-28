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
        int n, k;
        cin >> n >> k;

        vector<long long> x(n), s(n);

        for (int i = 0; i < n; i++)
            cin >> x[i];

        for (int i = 0; i < n; i++)
            cin >> s[i];

        int limit = min(k, n);

        vector<bool> unhappy(n, false);
        vector<long long> pos = x;

        for (int step = 0; step < limit; step++)
        {
            vector<long long> new_pos(n);

            new_pos[n - 1] = pos[n - 1] + s[n - 1];

            for (int i = n - 2; i >= 0; i--)
            {
                new_pos[i] = min(pos[i] + s[i], pos[i + 1] - 1);
            }

            for (int i = 0; i < n; i++)
            {
                if (new_pos[i] == pos[i])
                {
                    unhappy[i] = true;
                }
            }

            pos = new_pos;
        }

        int ans = 0;

        for (bool i : unhappy)
        {
            if (i)
            {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}