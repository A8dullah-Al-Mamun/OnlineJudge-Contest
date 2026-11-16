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
        ll n, k = 0;
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];

        sort(h.begin(), h.end()); //inscsing order sort
        vector<int> l, r;
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && h[j] == h[i])
                j++;

            int cnt = j - i;

            k = k + min(cnt, 2);
            l.push_back(h[i]);

            for (int p = i + 1; p < j; p++)
                r.push_back(h[i]);

            i = j;
        }

        cout << k << endl;
        reverse(r.begin(), r.end()); // reverse r to dcrs

        for (int i = 0; i < l.size(); i++)
            cout << l[i] << " ";

        for (int i = 0; i < r.size(); i++)
            cout << r[i] << " ";

        cout << endl;
    }

    return 0;
}