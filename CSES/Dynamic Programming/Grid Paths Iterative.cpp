#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)

       int main(){
 
          ll n , mod = 1e9 + 7;
          cin >> n ;
          string s[n+1] ;
          for( ll i = 0 ; i < n ; i++) cin >> s[i] ;
          ll dp[n+1][n+1] = {} ;
          dp[0][0] = 1 ;
          for( ll i = 0 ; i < n ; i++){
            for( ll j = 0 ; j < n ; j++){
              if(s[i][j] == '*') {
                dp[i][j] = 0 ;
                continue ;
              }
              if(i > 0) dp[i][j]= (dp[i][j]%mod+dp[i-1][j]%mod)%mod ;
              if(j > 0) dp[i][j]= (dp[i][j]%mod + dp[i][j-1]%mod)%mod ;
            }
          }
          cout << dp[n-1][n-1] << endl ;

       
     }