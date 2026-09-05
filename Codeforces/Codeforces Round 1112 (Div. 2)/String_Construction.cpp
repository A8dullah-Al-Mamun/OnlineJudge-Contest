#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k == n - 1) {
            cout << -1 << '\n';
            continue;
        }

        int runs = n - k;
        int extra = k;         

        bool found = false;
        for (int start = 0; start <= 1 && !found; start++) {
            int zeroRuns, oneRuns;

            if (start == 0) {
                zeroRuns = (runs + 1) / 2;
                oneRuns  = runs / 2;
            } else {
                zeroRuns = runs / 2;
                oneRuns  = (runs + 1) / 2;
            }

            int baseZ = zeroRuns;
            int baseO = oneRuns;
            for (int addZ = 0; addZ <= extra; addZ++) {
                int cnt0 = baseZ + addZ;
                int cnt1 = baseO + (extra - addZ);

                if (abs(cnt0 - cnt1) <= 1) {
                    vector<int> len(runs, 1);
                    vector<char> ch(runs);

                    int zeroIdx = -1, oneIdx = -1;

                    for (int i = 0; i < runs; i++) {
                        if (start == 0)
                            ch[i] = (i % 2 == 0 ? '0' : '1');
                        else
                            ch[i] = (i % 2 == 0 ? '1' : '0');

                        if (ch[i] == '0' && zeroIdx == -1) zeroIdx = i;
                        if (ch[i] == '1' && oneIdx == -1) oneIdx = i;
                    }

                    len[zeroIdx] += addZ;
                    len[oneIdx]  += (extra - addZ);

                    string ans;
                    for (int i = 0; i < runs; i++) {
                        ans.append(len[i], ch[i]);
                }

                    cout << ans << '\n';
                    found = true;
                    break;
                }
            }
        }

        if (!found) cout << -1 << '\n';
    }

    return 0;
}