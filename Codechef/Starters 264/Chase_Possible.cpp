#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll r, b, oponent_dfnd;
    cin >> r >> b;

    oponent_dfnd = 6 * b;

    if (r <= oponent_dfnd)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}