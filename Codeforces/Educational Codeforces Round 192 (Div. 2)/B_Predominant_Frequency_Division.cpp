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
        }

        vector<int> v1(n + 1), v2(n + 1), v3(n + 1);
        for (int i = 0; i < n; i++)
        {
            v1[i + 1] = v1[i] + (a[i] == 1);
            v2[i + 1] = v2[i] + (a[i] == 2);
            v3[i + 1] = v3[i] + (a[i] == 3);
        }

        vector<int> F(n + 1);
        for (int i = 0; i <= n; i++)
        {
            F[i] = v1[i] + v2[i] - v3[i];
        }

        vector<int> suf(n + 2, INT_MIN);
        for (int i = n - 1; i >= 1; i--)
        {
            suf[i] = max(F[i], suf[i + 1]);
        }

        bool ok = false;
        for (int i = 1; i <= n - 2; i++)
        {
            if (2 * v1[i] >= i && suf[i + 1] >= F[i])
            {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}