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
        cin >> n >> m;

        string p, q;
        cin >> p >> q;

        int cnt[26] = {};
        for (int i = 0; i < n; i++)
            cnt[p[i] - 'a']++;

        for (int i = 0; i < m; i++)
            cnt[q[i] - 'a']--;

        bool ok = true;
        for (char c = 'a'; c <= 'z'; c++)
        {
            int x = 0;
            if (c == 's' || c == 'i' || c == 'x')
                x = 1;

            if (cnt[c - 'a'] != x)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}