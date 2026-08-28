#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, y;
        cin >> r >> y;

        int extra = max(0, y - r);

        int ans = r + extra / 2;
        
        cout << ans << "\n";
    }
    return 0;
}