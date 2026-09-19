#include <bits/stdc++.h>
using namespace std;

vector<long long> coords;

struct SegTree {
    int n;
    vector<long long> sum;
    vector<int> cnt;

    SegTree(int n) : n(n), sum(4 * n + 5, 0), cnt(4 * n + 5, 0) {}

    void update(int pos, long long val) {
        update(1, 1, n, pos, val);
    }

    void update(int node, int l, int r, int pos, long long val) {
        sum[node] += val;
        cnt[node]++;

        if (l == r) return;

        int mid = (l + r) / 2;
        if (pos <= mid) update(node * 2, l, mid, pos, val);
        else update(node * 2 + 1, mid + 1, r, pos, val);
    }

    int query(long long target) {
        return query(1, 1, n, target);
    }

    int query(int node, int l, int r, long long target) {
        if (target <= 0) return 0;

        if (l == r) {
            long long val = coords[l - 1];
            return (target + val - 1) / val;
        }

        int mid = (l + r) / 2;
        int rightChild = node * 2 + 1;

        if (sum[rightChild] >= target) {
            return query(rightChild, mid + 1, r, target);
        } else {
            return cnt[rightChild] + query(node * 2, l, mid, target - sum[rightChild]);
        }
    }

    long long totalSum() const {
        return sum[1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        long long totalCells = 1LL * n * m;
        vector<long long> a(totalCells);
        coords.clear();
        coords.reserve(totalCells);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[1LL * i * m + j];
                coords.push_back(a[1LL * i * m + j]);
            }
        }

        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        SegTree seg((int)coords.size());

        long long ans = m; // removing all pieces from any row makes it empty

        for (int i = n - 1; i >= 0; i--) {
            long long base = 1LL * i * m;

            for (int j = 0; j < m; j++) {
                long long val = a[base + j];
                int pos = lower_bound(coords.begin(), coords.end(), val) - coords.begin() + 1;
                seg.update(pos, val);
            }

            if (seg.totalSum() >= v[i]) {
                ans = min(ans, (long long)seg.query(v[i]));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}