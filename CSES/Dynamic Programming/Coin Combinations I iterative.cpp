#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
const ll N=1000000;
const ll Nmax = 5e15+1;
const ll mod = 1e9+7 ;
 ll dp[1000001] ;
 
        int main(){

             ll n , x ;
             cin >> n >> x  ;
             vector < ll > coin(n) ;
             
             dp[0] = 1 ;
             for( ll i = 0 ; i < n ; i++) cin >> coin[i] ;
             sort(coin.begin() , coin.end()) ;
             for( ll i = 1 ; i <= x ; i++){
                for(ll j = 0 ; j < n ; j++)
                    if(coin[j] <= i){
                        dp[i] = (dp[i] + dp[i-coin[j]]%mod)%mod ;
                    }
             }
             cout << dp[x] << endl ;
    }