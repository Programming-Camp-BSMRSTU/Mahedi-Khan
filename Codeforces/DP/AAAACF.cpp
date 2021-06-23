#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)
ll N = 1009 ;
ll C[1009][1009] ;
ll mod = 998244353 ;
ll dp[1009] ;


         int main(){

            for( ll i = 0 ; i < N ; i++){
                C[i][0] = C[i][i] = 1 ;
                for( ll j = 1 ; j < i ; j++)
                    C[i][j] = (C[i-1][j] % mod + C[i-1][j-1] % mod) % mod ;
                
            }

            ll n , ans = 0 ;
            cin >> n ;
            vector < ll > ar(n+1) ;
            for( ll i = 0 ; i < n ; i++) cin >> ar[i] , dp[i] = 0 ;

            dp[n] = 1 ;
            for( ll i = n -1 ; i >= 0 ; i--){
                if(ar[i] <= 0 ) continue ;
                
                for( ll j = i + ar[i] + 1 ; j <= n ; j++){
                    dp[i]+= (dp[j]%mod * C[j - i - 1][ar[i]] % mod) % mod ;
                    dp[i]%=mod ;
                }
            }

            for( ll i = 0 ; i < n ; i++){
                ans+=dp[i] ;
                ans%=mod ;
            }

            cout << ans << endl ;


            
         }
     
