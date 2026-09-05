#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/* 2D Fenwick tree for prefix-index and prefix-value maximum */
struct BIT2D {
    int n;
    vector<vector<ll>> vals;    // compressed values per outer node
    vector<vector<ll>> bit;     // inner Fenwick trees

    BIT2D(int n, const vector<ll>& a) : n(n) {
        vals.resize(n + 1);
        // collect all values that will appear in each outer node
        for (int i = 1; i <= n; i++) {
            for (int x = i; x <= n; x += x & -x) {
                vals[x].push_back(a[i]);
            }
        }
        bit.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            sort(vals[i].begin(), vals[i].end());
            vals[i].erase(unique(vals[i].begin(), vals[i].end()), vals[i].end());
            bit[i].assign(vals[i].size() + 1, 0);
        }
    }

    // update at index `idx` with value `val` and dp `dpval`
    void update(int idx, ll val, ll dpval) {
        for (int x = idx; x <= n; x += x & -x) {
            int pos = lower_bound(vals[x].begin(), vals[x].end(), val) - vals[x].begin() + 1;
            for (int y = pos; y < (int)bit[x].size(); y += y & -y) {
                if (dpval > bit[x][y]) bit[x][y] = dpval;
            }
        }
    }

    // query maximum dp with index <= idx and value <= val
    ll query(int idx, ll val) {
        ll res = 0;
        for (int x = idx; x > 0; x -= x & -x) {
            int pos = upper_bound(vals[x].begin(), vals[x].end(), val) - vals[x].begin(); // count <= val
            for (int y = pos; y > 0; y -= y & -y) {
                if (bit[x][y] > res) res = bit[x][y];
            }
        }
        return res;
    }
};

/* Segment tree for range maximum query */
struct SegTree {
    int n;
    vector<ll> tree;
    SegTree(int sz) {
        n = 1;
        while (n < sz) n <<= 1;
        tree.assign(2 * n, 0);
    }

    void update(int pos, ll val) {  // 1-indexed position
        pos += n - 1;
        if (val > tree[pos]) tree[pos] = val;
        for (pos >>= 1; pos; pos >>= 1) {
            tree[pos] = max(tree[pos << 1], tree[pos << 1 | 1]);
        }
    }

    ll query(int l, int r) {        // inclusive 1-indexed range
        l += n - 1;
        r += n - 1;
        ll res = 0;
        while (l <= r) {
            if (l & 1) res = max(res, tree[l++]);
            if (!(r & 1)) res = max(res, tree[r--]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n + 1);
        vector<ll> vals;
        vals.reserve(n);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vals.push_back(a[i]);
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> rank(n + 1);
        for (int i = 1; i <= n; i++) {
            rank[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
        }

        BIT2D bit2d(n, a);
        SegTree activeSeg(vals.size());

        vector<vector<int>> bucket(n + 2);
        vector<ll> dp(n + 1, 0);
        ll ans = 0;

        for (int i = 1; i <= n; i++) {
            // insert all indices that become active for group2 at this position
            for (int j : bucket[i]) {
                activeSeg.update(rank[j], dp[j]);
            }

            ll best = 0;

            // group1: j < i - a[i] and a[j] <= a[i]
            ll L_ll = (ll)i - a[i] - 1;
            if (L_ll > 0) {
                int L = (int)L_ll;
                ll g1 = bit2d.query(L, a[i]);
                best = max(best, g1);
            }

            // group2: a[j] > a[i] and j + a[j] < i
            if (rank[i] < (int)vals.size()) {
                ll g2 = activeSeg.query(rank[i] + 1, (int)vals.size());
                best = max(best, g2);
            }

            dp[i] = best + a[i];
            ans = max(ans, dp[i]);

            // insert current index into 2D BIT
            bit2d.update(i, a[i], dp[i]);

            // schedule for group2 activation
            ll active_time = (ll)i + a[i] + 1;
            if (active_time <= n) {
                bucket[(int)active_time].push_back(i);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}