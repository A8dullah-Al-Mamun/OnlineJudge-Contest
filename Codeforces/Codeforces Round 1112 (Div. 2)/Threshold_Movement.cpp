#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> w(n);
        for (int i = 0; i < n; i++) cin >> w[i];

        if (n % 2 == 1) {
            cout << "NO\n";
            continue;
        }

        long long max_even = LLONG_MIN;
        long long min_odd = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {          
                min_odd = min(min_odd, w[i]);
            } else {                  
                max_even = max(max_even, w[i]);
            }
        }

        if (max_even + 1 < min_odd)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}