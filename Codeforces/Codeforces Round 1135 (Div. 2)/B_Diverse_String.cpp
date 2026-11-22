#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll diversity(ll n, ll ones)
{
    ll zrs, a, b, x, y, p, q;

    zrs = n - ones;
    a = ones + 1;
    b = zrs + 1;
    x = ones * a;
    y = zrs * b;
    p = x / 2;
    q = y / 2;

    ll ans = 1 + p + q;

    return ans;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, ones = 0, a, b, ans, l, h;
        cin >> n >> k;

        string s;
        cin >> s;

        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1')
                ones++;
        }
        // total one ekbr komano ba baranor jnnee..
        l = ones - k;
        if (l < 0)
            l = 0;

        h = ones + k;
        if (h > n)
            h = n;
        // for get the highest value of two sides driversity
        a = diversity(n, l);
        b = diversity(n, h);
        ans = max(a, b);

        cout << ans << endl;
    }

    return 0;
}