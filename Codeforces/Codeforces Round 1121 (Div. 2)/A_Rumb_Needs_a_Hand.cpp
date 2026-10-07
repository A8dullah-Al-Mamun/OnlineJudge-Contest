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

        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
        }

        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            if (p[i] != i)
                a.push_back(i);
        }

        bool ok = true;
        for (int i = 0; i < a.size(); i++)
        {
            if (p[a[i]] != a[a.size() - 1 - i])
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