#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> freq(31, 0);
        int max_fr = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            int msb = 0;
            while (x > 1)
            {
                x = x / 2;
                msb++;
            }

            freq[msb]++;
            max_fr = max(max_fr, freq[msb]);
        }

        cout << max_fr << "\n";
    }

    return 0;
}