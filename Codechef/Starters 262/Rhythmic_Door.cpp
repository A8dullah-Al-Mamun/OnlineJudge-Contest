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
        ll n;
        string s;
        cin >> n >> s;

        ll open = 0, streak = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || s[i] != s[i - 1]) streak = 1;
            else streak++;

            if (streak == 3)
            {
                open++;
                streak = 0;
            }
        }

        cout << open << endl;
    }

    return 0;
}
