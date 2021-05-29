#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)

       int main(){
        T{
         ll n ;
         cin >> n ;
         ll dp[n+1] = {} ;
         for( ll i = 1 ; i <= n ; i++){
          dp[i] = 1e17 ;
            for(char it: to_string(i)){
              dp[i] = min(dp[i] , dp[i-(it - '0')]+1) ;
            }
         }
         cout << dp[n] << endl ;
       }
     }