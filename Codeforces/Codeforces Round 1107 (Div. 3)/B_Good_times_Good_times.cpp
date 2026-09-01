#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long x;
        scanf("%lld", &x);
        int L = (int)to_string(x).size();
        long long p = 1;
        for (int i = 0; i < L; i++)
            p *= 10;
        long long y = p + 1;
        printf("%lld\n", y);
    }
    return 0;
}