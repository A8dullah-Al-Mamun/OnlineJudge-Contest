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
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = a[i] - i;
        }

        sort(a.begin(), a.end());

        int mx = 1,cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
             cnt++;
            else
            {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }

        mx = max(mx, cnt);

        cout << (n - mx) << endl;
    }

    return 0;
}