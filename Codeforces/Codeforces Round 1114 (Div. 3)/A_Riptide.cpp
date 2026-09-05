#include <bits/stdc++.h>
using namespace std;

int main() {
 
    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        array<long long, 3> v = {a, b, c};
        sort(v.begin(), v.end());

        long long diffrence = v[1] - v[0];
        long long  diffrence2= v[2] - v[1];

        cout << min(diffrence, diffrence2) << '\n';
    }

    return 0;
}