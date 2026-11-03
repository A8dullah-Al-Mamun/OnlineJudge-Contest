#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        ll mid = a[n / 2], cost = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > mid)
                cost += a[i] - mid;
            else
                cost += mid - a[i];
        }

        ll s = a[n - 1] - a[0];
        cout << cost << " " << s << endl;
    }

    return 0;
}