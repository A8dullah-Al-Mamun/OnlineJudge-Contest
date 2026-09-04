#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        vector<int> freq;
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && a[j] == a[i])
                ++j;
            freq.push_back(j - i);
            i = j;
        }

        int m = freq.size();
        int max_c = *max_element(freq.begin(), freq.end());
        vector<int> cnt_of(max_c + 1, 0), sum_of(max_c + 1, 0);
        for (int c : freq)
        {
            cnt_of[c]++;
            sum_of[c] += c;
        }

        vector<int> distinct;
        for (int x = 1; x <= max_c; ++x)
            if (cnt_of[x])
                distinct.push_back(x);

        long long S = n;
        int sz = m;
        int ans = 0;

        for (int v : distinct)
        {
            if ((k - S) % sz == 0)
            {
                long long d = (k - S) / sz;
                if (d >= 1 - v)
                    ++ans;
            }
            S -= sum_of[v];
            sz -= cnt_of[v];
        }

        cout << ans << '\n';
    }
    return 0;
}