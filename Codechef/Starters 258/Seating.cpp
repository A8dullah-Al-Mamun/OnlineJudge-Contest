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
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> vorti(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            vorti[x] = 1;
        }

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (vorti[j] == 0)
                {
                    vorti[j] = 1;
                    ans.push_back(j);
                    break;
                }
            }
        }

        for (int i = 0; i < k; i++)
            cout << ans[i] << " ";

        cout << endl;
    }

    return 0;
}