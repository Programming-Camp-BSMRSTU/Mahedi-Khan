#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)
         int main(){

             ll n , inf = 1e17 , ans ;
             cin >> n ;
             string s[n+10] , t[n+10];
             vector < vector < ll > > dp(n+1 , vector < ll >(2)) ;
             ll cost[n+1] ;
             for( ll i = 0 ; i < n ; i++) cin >> cost[i] ;
             for( ll i = 0 ; i < n ; i++){
                cin >> s[i] ;
                t[i] = s[i] ;
                reverse(t[i].begin(), t[i].end()) ;
             }

             dp[0][0] = 0 ; dp[0][1] = cost[0] ;
             for( ll i = 1 ; i <= n ; i++){
                dp[i][0] = inf , dp[i][1] = inf ;
             }
             
             for( ll i = 1 ; i < n ; i++){
                if(s[i-1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i-1][0]) ;
                if(t[i-1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i-1][1]) ;
                if(s[i-1] <= t[i]) dp[i][1] = min(dp[i][1],  dp[i-1][0] + cost[i]) ;
                if(t[i-1] <= t[i]) dp[i][1] = min(dp[i][1] , dp[i-1][1] + cost[i]) ;
             }
             ans = min(dp[n-1][0], dp[n-1][1]) ;
             if(ans == inf) cout << "-1" << endl ;
             else cout << ans << endl; 



            


            
               
    
         }
     
        


            


         
 