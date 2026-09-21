#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int odd = 0;
        int mod0 = 0;
        int mod2 = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (x % 2 != 0)
                odd++;

            else if (x % 4 == 0)
                mod0++;

            else
                mod2++;
        }

        int ans = odd;
        if (mod0 > ans)
        {
            ans = mod0;
        }
        if (mod2 > ans)
        {
            ans = mod2;
        }
        cout << ans << endl;
    }

    return 0;
}