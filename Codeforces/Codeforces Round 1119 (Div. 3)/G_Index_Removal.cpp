#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        ll k;
        cin >> n;
        cin >> k;

        vector<ll> a(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<ll> b(n + 1);
        for (int i = 1; i <= n; i++)
            b[i] = a[i] - i * k;

        vector<ll> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + b[i];

        vector<ll> answer(n + 1, 0);
        for (int i = 2; i < n; i++)
        {
            ll limit = b[i - 1] - k;
            int left = i + 1;
            int right = n + 1;

            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (b[mid] > limit)
                    left = mid + 1;
                else
                    right = mid;
            }

            int last = left - 1;
            if (last >= i + 1)
            {
                ll sum = prefix[last] - prefix[i];
                ll count = last - i;

                answer[i] = sum - count * limit;
            }
        }

        for (int i = 1; i <= n; i++)
            cout << answer[i] << " ";

        cout << endl;
    }

    return 0;
}