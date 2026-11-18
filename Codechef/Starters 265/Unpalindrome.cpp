#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<bool> present(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            present[a[i]] = true;
        }

        bool same = true;
        for (int i = 0; i < n / 2; i++)
        {
            if (a[i] != a[n - 1 - i])
            {
                same = false;
                break;
            }
        }
        if (same)
        {
            cout << "NO" << endl;
            continue;
        }

        int x = 1;
        while (x <= n && present[x])
            x++;

        if (x > n)
            x = 1;

        cout << "YES " << x << endl;
    }
    // eibar thiikacheee
    return 0;
}