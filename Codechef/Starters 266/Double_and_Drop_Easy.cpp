#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

int main() {
	// your code goes here
    ll t ; cin >> t ; while(t--){
    
    ll n , sum = 0 , mx = 0 ; cin >> n ;
    vector<ll> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
        
        sum = sum+ a[i];
        mx = max(mx, a[i]);
    }
    
    
    ll ans = sum - mx ;
    
    for(int i = 0 ; i < n ; i++){
        
        ll x , n_sum , n_mx , score ;
        
        x = 2* a[i] ;
        n_sum = sum + a[i] ;
        n_mx = max(mx , x ) ;
        score = n_sum - n_mx ;
        ans = max( ans , score );
    }
        
        cout<< ans<<endl ;
    }
    
    return 0 ;
}
