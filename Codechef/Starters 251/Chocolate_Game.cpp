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

        vector<int> a(n);
        long long sum = 0;
        int oddCount = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum = sum + a[i];

            if (a[i] % 2 == 1)
            {
                oddCount++;
            }
        }

        long long result;

        if (sum % 2 == 1)
        {
            result = (oddCount - 1) / 2;
        }
        else
        {
            result = sum - oddCount / 2;
        }

        cout << result << '\n';
    }

    return 0;
}