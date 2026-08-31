#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z <= y) {
            cout << -1 << '\n';
        } else {
            int diff = z - y;
            int months = (x + diff - 1) / diff; 
            cout << months << '\n';
        }
    }

    return 0;
}