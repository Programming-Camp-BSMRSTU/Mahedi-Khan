#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
const ll N=1000000;
const ll mod = 1e9 + 7;
 ll ar[N+100] ; 
 ll dp[1000001];
 
        int main(){
            
            ll n , x ;
            cin >> n >> x ;
            vector < ll > c(n) ;
            for( ll i = 0 ; i < n ; i++) cin >> c[i] ;
            sort(c.begin() , c.end()) ;
            dp[0] = 1 ;
            for( ll i = 0 ; i < n ; i++){
                for( ll j = 1 ; j <= x ; j++){
                    if(j >= c[i]) dp[j] = (dp[j]%mod + dp[j - c[i]]%mod)%mod ;
                }
            }
            cout << dp[x] << endl ;
    }