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

        vector<long long> numbers(n);

        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }

        long long prefixSum = 0;
        bool possible = true;

        for (int i = 0; i < n; i++)
        {
            prefixSum += numbers[i];

            long long requiredSum = (long long)(i + 1) * (i + 2) / 2;

            if (prefixSum < requiredSum)
            {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}