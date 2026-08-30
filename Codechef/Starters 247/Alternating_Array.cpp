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

        int f_pattern = 0;
        int s_Pattern = 0;

        for (int i = 0; i < n; i++) {
            bool isEven = (a[i] % 2 == 0);

            if (i % 2 == 0) {
                if (isEven)
                    f_pattern++;
                else
                    s_Pattern++;
            } else {
                if (isEven)
                    s_Pattern++;
                else
                    f_pattern++;
            }
        }

        cout << min(n - f_pattern, n - s_Pattern) << '\n';
    }

    return 0;
}