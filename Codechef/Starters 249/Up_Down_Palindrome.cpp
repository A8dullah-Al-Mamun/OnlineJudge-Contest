// not sbmitted 

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
  
//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         vector<long long> a(n);
//         for (int i = 0; i < n; i++)
//             cin >> a[i];

//         if (n <= 1) {
//             cout << "Yes\n";
//             continue;
//         }

//         vector<int> p;
//         bool f = false;

//         for (int i = 0; i < n / 2; i++) {
//             long long x = a[i], y = a[n - 1 - i];

//             if (x == y) continue;

//             if (abs(x - y) != 2) {
//                 p.clear();
//                 f = true;
//                 break;
//             }

//             int l = min(x, y);
//             vector<int> c = {l, l + 1};

//             if (!f) {
//                 p = c;
//                 f = true;
//             } else {
//                 vector<int> v;
//                 for (int z : p)
//                     if (z == l || z == l + 1)
//                         v.push_back(z);
//                 p = v;
//                 if (p.empty()) break;
//             }
//         }

//         cout << (!f || !p.empty() ? "Yes" : "No") << '\n';
//     }

//     return 0;
// }