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
        int n;
        cin >> n;

        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            ++freq[x];
        }

        int mex = 0;
        while (freq.count(mex))
        {
            ++mex;
        }

        long long totalMoves = 0;
        for (auto &[val, cnt] : freq)
        {
            if (val < mex)
            {
                if (val > 0) totalMoves += 1LL * (cnt - 1) * val;
            }
            else if (val > mex)  totalMoves += 1LL * cnt * (val - mex - 1);
            
        }

       if (totalMoves % 2 == 1)  cout << "Alice" << endl;
        
       else cout << "Bob" << endl;
    
    }

    return 0;
}