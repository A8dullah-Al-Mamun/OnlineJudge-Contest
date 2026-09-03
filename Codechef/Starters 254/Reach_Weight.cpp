#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int ans;
        if (n % 2 == 0)
        {
            ans = (n / 2) * 30;
        }
        else
        {
            ans = (n / 2) * 30 + 20;
        }

        cout << ans << "\n";
    }

    return 0;
}