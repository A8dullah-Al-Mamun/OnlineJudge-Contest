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
        int n, m;
        cin >> n;
        cin >> m;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int k = m - 1;
        priority_queue<long long> pq;

        long long sum = 0;
        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++)
        {
            if (i >= m - 1)
            {

                long long x = m * a[i] - sum;
                ans = max(ans, x);
            }

            if (k > 0)
            {
                if (pq.size() < k)
                {
                    pq.push(a[i]);
                    sum += a[i];
                }
                else if (a[i] < pq.top())
                {
                    sum += a[i] - pq.top();

                    pq.pop();
                    pq.push(a[i]);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}