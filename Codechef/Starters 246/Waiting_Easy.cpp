#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector <ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        ll cur = 0, total_wait = 0;
        for (int i = 0; i < n; ++i)
        {
            if (cur < a[i])
            {
                cur = a[i];
            }
            total_wait += cur - a[i];
        }
        cout << total_wait << "\n";
    }
    return 0;
}