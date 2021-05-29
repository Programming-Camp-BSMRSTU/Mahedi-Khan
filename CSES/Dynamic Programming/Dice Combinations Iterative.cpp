#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)

       int main(){
 
         ll n , sum = 0 , mod = 1e9 + 7; 
         cin >> n ;
         ll dp[n+1] ;
         for( ll i = 0 ; i <= n ; i++) dp[i] = 0 ;
          dp[0] = 1 ;
         for( ll i = 1 ; i <= n ; i++){
          for( ll j = 1 ; j <= 6 ; j++)
            if(i >= j) (dp[i]+=dp[i-j])%=mod ;
         }
         cout << dp[n] << endl ;


       
     }