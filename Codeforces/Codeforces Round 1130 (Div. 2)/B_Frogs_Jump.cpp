#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

        string top, btm;
        cin >> top;
        cin >> btm;

        ll single = 0;
        for (int i = 0; i < n; i++)
        {
            int f = (top[i] == 'f') + (btm[i] == 'f');
            if (f == 1)
                single++;
        }

        ll ans = single % 2;
        cout << ans << endl;
    }

    return 0;
}
