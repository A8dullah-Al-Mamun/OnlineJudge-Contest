// #include <bits/stdc++.h>
// using namespace std;

// const long long MOD = 998244353;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     const int MAXN = 105;
//     vector<long long> pow2(MAXN + 5, 1);
//     for (int i = 1; i < (int)pow2.size(); i++) {
//         pow2[i] = (pow2[i - 1] * 2) % MOD;
//     }

//     int T;
//     cin >> T;

//     while (T--) {
//         int N;
//         cin >> N;

//         vector<int> cnt(N + 2, 0);
//         for (int i = 0; i < N; i++) {
//             int x;
//             cin >> x;
//             cnt[x]++;
//         }

//         // pref[i] = product_{x=0}^{i} (2^cnt[x] - 1) mod MOD
//         vector<long long> pref(N + 2, 0);
//         long long prod = 1;
//         for (int i = 0; i <= N + 1; i++) {
//             long long factor = (pow2[cnt[i]] - 1 + MOD) % MOD;
//             prod = (prod * factor) % MOD;
//             pref[i] = prod;
//         }

//         long long ans = 0;

//         // Case 1: mex(B) = m, max(B) = m + 1
//         for (int m = 0; m <= N; m++) {
//             long long left = (m == 0 ? 1 : pref[m - 1]);
//             long long right = (pow2[cnt[m + 1]] - 1 + MOD) % MOD;
//             ans = (ans + left * right) % MOD;
//         }

//         // Case 2: max(B) = M, mex(B) = M + 1
//         for (int M = 0; M <= N; M++) {
//             ans = (ans + pref[M]) % MOD;
//         }

//         cout << ans << '\n';
//     }

//     return 0;
// }