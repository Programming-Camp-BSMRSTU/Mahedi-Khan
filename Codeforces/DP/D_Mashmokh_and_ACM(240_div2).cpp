#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)

    ll MOD = 1e9+7 ;

     int main(){


      ll n , k , ans = 0;
      cin >> n >> k ;

      ll DP[k+1][n+1] = {};
 
      for( ll i = 1 ; i <= n ; i++ )
        DP[1][i] = 1 ;

      for( ll i = 2 ; i <= k ; i++){
        for( ll j = 1 ; j <= n ; j++){
          for( ll l = j ; l <= n ; l+=j)
              if((DP[i][j]+=DP[i-1][l]) >= MOD) 
                DP[i][j]-=MOD ;
              
        }
      }

      for( ll i = 1 ; i <= n ; i++){
        (ans+=DP[k][i])%=MOD ;
        
      }
      cout << ans << endl ;

        




     }






            
         
       
          

     