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
        int n, x;
        cin >> n >> x;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<long long> candidates;
        for (int i = 0; i < n; i++)
        {
            candidates.push_back(a[i]);
            if (a[i] - 1 >= 0)
                candidates.push_back(a[i] - 1);
        }

        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        long long ans = LLONG_MIN;

        for (long long T : candidates)
        {

            int above = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] > T)
                    above++;
            }

            if (above > x)
                continue;

            int need = x + 1 - above;

            vector<long long> costs;
            costs.reserve(n);

            for (int i = 0; i < n; i++)
            {
                if (a[i] <= T)
                {
                    costs.push_back(b[i] * (T - a[i]));
                }
            }

            if ((int)costs.size() < need)
                continue;

            sort(costs.begin(), costs.end());

            long long totalCost = 0;
            for (int i = 0; i < need; i++)
            {
                totalCost += costs[i];
            }

            long long profit = 1LL * x * T - totalCost;
            ans = max(ans, profit);
        }

        cout << ans << '\n';
    }

    return 0;
}