#include <bits/stdc++.h>
using namespace std;

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
        vector<long long> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int max_freq = 0, repeat = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[i - 1] || i == 0)
            {
                repeat++;
                max_freq = max(max_freq, repeat);
            }
            else
            {
                repeat = 1;
                max_freq = max(max_freq, repeat);
            }
        }

        cout << (max_freq + 1) / 2 << endl;
    }
    return 0;
}
