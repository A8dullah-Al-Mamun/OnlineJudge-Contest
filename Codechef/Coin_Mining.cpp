#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        for (ll day = 1; day <= x; day++)
        {
            bool possible = false;

            for (ll gpu = 1; gpu <= day; gpu++)
            {
                ll sum = 0;

                for (ll i = 1; i <= gpu; i++)
                    sum += i * i;

                sum += (day - gpu) * (gpu * gpu);

                ll rvnu = y * sum;
                ll cost = gpu * x;

                if (rvnu > cost)
                {
                    possible = true;
                    break;
                }
            }

            if (possible)
            {
                cout << day << endl;
                break;
            }
        }
    }

    return 0;
}