#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int main() {
	// your code goes here
	
    ll t ; cin >> t ;
    while(t--){
        
        
        ll n , k ;
        cin >> n >> k ;
        
        ll x = 2* k ;
        
        if(n>=k && n<= x ) cout << "YES" << endl ;
        
        else cout << "NO" << endl;
    }
    
    return 0 ;
}
