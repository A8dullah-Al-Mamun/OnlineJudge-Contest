#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n;
        cin >> k;

        string s;
        cin >> s;

        int ans = 0;
        for (int i = 0; i < n; i += k)
        {
            int count = 0;
            for (int j = i; j < i + k; j++)
            {
                if (s[j] == '1')
                {
                    count++;
                }
            }
            if (count == k)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}