#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T ll time;        cin >> time; while(time--)

const ll INF = 1e17 ;

            int main(){
                ios::sync_with_stdio(false) ;
                cin.tie(0) ;
                 
                  ll t ;
                  cin >> t ;
                  while(t--){
                 ll n ;
                 cin >> n ;
                 ll a[n+1] , b[n+1] , dp[n+1][4] ;

                 for( ll i = 1 ; i <= n ; i++)
                    cin >> a[i] >> b[i] ;

                 dp[1][0] = 0 ;
                 dp[1][1] = b[1] ;
                 dp[1][2] = 2*b[1] ;
                 dp[1][3] = 3*b[1] ;

                 for( ll i = 2 ; i <= n ; i++){
                    for( ll n = 0 ; n < 3 ; n++){
                        dp[i][n] = INF ;
                        for( ll p = 0 ; p < 3 ; p++){
                            if(a[i-1]+p == a[i] + n) continue ;
                            dp[i][n] = min(dp[i][n] , dp[i-1][p] + n*b[i]) ;
                        }
                    }
                 }
                 cout << (min({dp[n][0] , dp[n][1] , dp[n][2]})) <<endl ;
             }
             


              }