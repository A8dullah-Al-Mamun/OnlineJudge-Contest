#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a < b) {
        cout << "Yes\n";
    } else {
       
        if (a % 2 == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}