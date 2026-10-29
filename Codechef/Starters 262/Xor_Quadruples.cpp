
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (n < 4)
        {
            cout << -1 << endl;
            continue;
        }

        vector<bitset<MAXN>> rightok(n);
        vector<bitset<MAXN>> suff(n + 1), pref(n + 1);

        for (int k = 0; k < n; k++)
        {
            int m = n - k - 1;
            if (m == 0) continue;

            vector<int> order1(m), order2(m);
            for (int i = 0; i < m; i++)
            {
                order1[i] = i;
                order2[i] = i;
            }

            sort(order1.begin(), order1.end(), [&](int x, int y)
            {
                return a[k + 1 + x] < a[k + 1 + y];
            });

            sort(order2.begin(), order2.end(), [&](int x, int y)
            {
                return (a[k] ^ a[k + 1 + x]) < (a[k] ^ a[k + 1 + y]);
            });

            vector<int> vals1(m), vals2(m);
            for (int i = 0; i < m; i++)
            {
                vals1[i] = a[k + 1 + order1[i]];
                vals2[i] = a[k] ^ a[k + 1 + order2[i]];
            }

            suff[m].reset();
            for (int i = m - 1; i >= 0; i--)
            {
                suff[i] = suff[i + 1];
                suff[i].set(k + 1 + order1[i]);
            }

            pref[0].reset();
            for (int i = 0; i < m; i++)
            {
                pref[i + 1] = pref[i];
                pref[i + 1].set(k + 1 + order2[i]);
            }

            for (int j = 0; j < k; j++)
            {
                int y = a[j] ^ a[k];
                int x = a[j];

                int t1 = upper_bound(vals1.begin(), vals1.end(), y) - vals1.begin();
                int t2 = lower_bound(vals2.begin(), vals2.end(), x) - vals2.begin();

                if ((suff[t1] & pref[t2]).any())
                    rightok[j].set(k);
            }
        }

        vector<bitset<MAXN>> pref1(n + 1), suff2(n + 1);
        bool found = false;

        for (int j = 0; j < n && !found; j++)
        {
            int m = j;
            if (m == 0) continue;

            vector<int> order1(m), order2(m);
            for (int i = 0; i < m; i++)
            {
                order1[i] = i;
                order2[i] = i;
            }

            sort(order1.begin(), order1.end(), [&](int x, int y)
            {
                return (a[x] ^ a[j]) < (a[y] ^ a[j]);
            });

            sort(order2.begin(), order2.end(), [&](int x, int y)
            {
                return a[x] < a[y];
            });

            vector<int> vals1(m), vals2(m);
            for (int i = 0; i < m; i++)
            {
                vals1[i] = a[order1[i]] ^ a[j];
                vals2[i] = a[order2[i]];
            }

            pref1[0].reset();
            for (int i = 0; i < m; i++)
            {
                pref1[i + 1] = pref1[i];
                pref1[i + 1].set(order1[i]);
            }

            suff2[m].reset();
            for (int i = m - 1; i >= 0; i--)
            {
                suff2[i] = suff2[i + 1];
                suff2[i].set(order2[i]);
            }

            for (int k = j + 1; k < n && !found; k++)
            {
                int x = a[k];
                int y = a[j] ^ a[k];

                int t1 = lower_bound(vals1.begin(), vals1.end(), x) - vals1.begin();
                int t2 = upper_bound(vals2.begin(), vals2.end(), y) - vals2.begin();

                if ((pref1[t1] & suff2[t2]).any() && rightok[j].test(k))
                {
                    int fi = -1;
                    for (int i = 0; i < j; i++)
                    {
                        if ((a[i] ^ a[j]) < a[k] && a[i] > (a[j] ^ a[k]))
                        {
                            fi = i;
                            break;
                        }
                    }

                    int fl = -1;
                    for (int l = k + 1; l < n; l++)
                    {
                        if ((a[j] ^ a[k]) < a[l] && a[j] > (a[k] ^ a[l]))
                        {
                            fl = l;
                            break;
                        }
                    }

                    cout << fi + 1 << ' ' << j + 1 << ' '
                         << k + 1 << ' ' << fl + 1 << endl;

                    found = true;
                }
            }
        }

        if (!found)
            cout << -1 << endl;
    }

    return 0;
}
