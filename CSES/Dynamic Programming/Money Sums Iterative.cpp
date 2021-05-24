#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)
    ll dp[1001][1001] ;
           int main(){
              ll n , sum = 0 , cnt = 0 ;
              cin >> n ;
              vector < ll > c(n) ;
              for( ll i = 0 ; i < n ; i++)
                cin >> c[i] , sum+=c[i] ;
              ll dp[sum+1]={} ;
              dp[0] = 1 ;
              sort(c.begin() , c.end()) ;
              for( ll i = 0 ; i < n ; i++){
                for( ll j = sum ; j >= 1 ; j--){
                    if(j >= c[i] and dp[j] != 1) {
                        dp[j] = dp[j-c[i]] ;
                    }
                }
              }

              for( ll i = 1 ; i <= sum ; i++) 
                cnt+=dp[i] ;
            

              cout << cnt << endl ;
          for( ll i = 1 ; i <= sum ; i++){
            if(dp[i]) cout << i << " " ;
          }
          cout << endl ;





           }


            


        
           