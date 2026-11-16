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
        ll a, b, c, x, y;
        cin >> a >> b >> c;

        x = a + 1;
        y = b + 1;

        if (b == x && c == y)
            cout << "yes" << endl;

        else
            cout << "NO" << endl;
    }

    return 0;
}