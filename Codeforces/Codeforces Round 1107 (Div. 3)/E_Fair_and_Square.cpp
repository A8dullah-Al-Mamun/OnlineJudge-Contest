#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using ull = unsigned long long;

const int MAXA = 1000000;
vector<int> spf(MAXA + 1);
ull prime_hash[MAXA + 1];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void sieve() {
    for (int i = 0; i <= MAXA; i++) spf[i] = i;
    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    for (int i = 2; i <= MAXA; i++) {
        if (spf[i] == i) prime_hash[i] = rng();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ull> val(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            int temp = x;
            while (temp > 1) {
                int p = spf[temp];
                int cnt = 0;
                while (temp % p == 0) {
                    temp /= p;
                    cnt ^= 1;
                }
                if (cnt) val[i] ^= prime_hash[p];
            }
        }

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n + 1, 0);
        vector<int> order;
        order.reserve(n);


        vector<int> st;
        st.push_back(1);
        parent[1] = -1;
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            order.push_back(u);
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                st.push_back(v);
            }
        }

        vector<int> sz(n + 1, 0);
        vector<int64> f(n + 1, 0);
        int64 ans = 0;

        for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
            int u = order[idx];
            sz[u] = 1;
            int64 sum_sz = 0, sum_sz2 = 0, sum_sz3 = 0;
            int64 f_sum = 0;

            for (int v : adj[u]) {
                if (parent[v] == u) {
                    sz[u] += sz[v];
                    sum_sz += sz[v];
                    sum_sz2 += 1LL * sz[v] * sz[v];
                    sum_sz3 += 1LL * sz[v] * sz[v] * sz[v];
                    f_sum += f[v];
                }
            }

            int64 pairs_with_LCA_u = (sz[u] - 1) + ( (sum_sz * sum_sz - sum_sz2) / 2 );

            if (val[u] == 0) {
                f[u] = pairs_with_LCA_u + f_sum;
            } else {
                f[u] = f_sum;
            }

            int64 total = sz[u];
            int64 sum2 = 1 + sum_sz2;   // group {u} contributes 1^2
            int64 sum3 = 1 + sum_sz3;
            int64 dp3 = (total * total * total - 3 * total * sum2 + 2 * sum3) / 6;

            if (val[u] == 0) {
                ans += dp3;
            }

            for (int v : adj[u]) {
                if (parent[v] == u) {
                    ans += f[v] * (sz[u] - sz[v]);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}