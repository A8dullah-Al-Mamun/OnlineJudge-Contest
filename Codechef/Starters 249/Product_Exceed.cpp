#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int t;
    cin >> t;

    while (t--) {
        int x, y, p;
        cin >> x >> y >> p;

        int mx = max(0, (p + y - 1) / y - x);
        int ans = INT_MAX;

        for (int a = 0; a <= mx; a++) {
            int nx = x + a;
            int ny = (p + nx - 1) / nx;
            int b = max(0, ny - y);
            ans = min(ans, a + b);
        }

        cout << ans << '\n';
    }

    return 0;
}