#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int max_height = 0;
        for (int i = 0; i < n - 1; i++) {
            int height = min(a[i], a[i+1]);
            max_height = max(max_height, height);
        }
        cout << max_height << "\n";
    }
    return 0;
}