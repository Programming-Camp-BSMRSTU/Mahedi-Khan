#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)

       int main(){
 
          ll n ;
          cin >> n ;
          vector < ll > v(n+1) , lis ;
           ll dp[n+1] ;
           dp[0] = 0 ;
          for( ll i = 0 ; i < n ; i++) cin >> v[i];
            lis.pb(v[0]) ;
          for( ll i = 0 ; i <= n ; i++){
            auto it = lower_bound(lis.begin() , lis.end() , v[i]);
            if(it == lis.end()) lis.pb(v[i]) ;
            else lis[it-lis.begin()] = v[i] ;
            
          }
          cout << lis.size() << endl ;



       
     }
