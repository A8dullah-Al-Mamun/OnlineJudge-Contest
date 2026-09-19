#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> cards(n);
        unordered_map<int, int> count;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> cards[i];
            sum += cards[i];
            count[cards[i]]++;
        }

        int highestCount = 0;
        int damage = 0;

        for (auto &it : count) {
            if (it.second > highestCount) {
                highestCount = it.second;
                damage = it.first;
            }
        }

        int otherCard = n - highestCount;

        if (highestCount <= otherCard + 1) {
            cout << sum << '\n';
        } else {
            long long ans = sum - 1LL * (highestCount - otherCard - 2) * damage;
            cout << ans << '\n';
        }
    }

    return 0;
}