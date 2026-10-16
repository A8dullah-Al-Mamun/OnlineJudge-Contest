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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    ll ans = 0;
    if (k >= n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            ans += a[i];
        }
    }
    else
    {
        for (int i = 0; i <= k; i++)
        {
            ans += a[i];
        }
    }
    cout << ans << endl;
}
return 0;

}