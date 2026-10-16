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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = min(a[n - 1] - a[1], a[n - 2] - a[0]);
    cout << ans << endl;
}
return 0;

}