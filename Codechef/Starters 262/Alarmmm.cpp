
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
        ll n, k, alarms = 0, i = 0;
        cin >> n >> k;
        
        string s;
        cin >> s;

        while (i < n)
        {
            if (s[i] == '1')
            {
                alarms++;
                i = i + k + 1;
            }
            else
                i++;
        }

        cout << alarms << endl;
    }

    return 0;
}
