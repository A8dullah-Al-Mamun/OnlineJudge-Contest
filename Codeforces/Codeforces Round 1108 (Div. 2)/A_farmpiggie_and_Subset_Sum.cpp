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
        vector<int> x(n);
        for (int i = 0; i < n; i += 2)
        {
            x[i] = i + 2;
            x[i + 1] = i + 1;
        }
        for (int i = 0; i < n; ++i)
            cout << x[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}