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
        ll n, k, o = 0;
        cin >> n >> k;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<ll> f(n);

        set<ll> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(a[i]);
            while (s.count(o))
                o++;
            f[i] = o;
        }

        sort(f.begin(), f.end(), greater<ll>());

        ll best = f[k - 1], x = -1, y = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(a[i], a[j]);

                set<ll> s;
                vector<ll> b(n);
                ll mex = 0;

                for (int p = 0; p < n; p++)
                {
                    s.insert(a[p]);
                    while (s.count(mex))
                        mex++;
                    b[p] = mex;
                }

                sort(b.begin(), b.end(), greater<ll>());

                if (b[k - 1] > best)
                {
                    best = b[k - 1];
                    x = i + 1;
                    y = j + 1;
                }

                swap(a[i], a[j]);
            }
        }

        if (x == -1)
            cout << -1 << endl;
        else
            cout << x << " " << y << endl;
    }

    return 0;
}
