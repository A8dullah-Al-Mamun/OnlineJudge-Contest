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
        string a, b;
        cin >> a >> b;

        int cnta = count(a.begin(), a.end(), 'a');
        int cntb = count(b.begin(), b.end(), 'a');

        if (cnta + cntb == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}