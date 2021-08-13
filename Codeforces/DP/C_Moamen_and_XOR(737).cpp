#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T ll time;        cin >> time; while(time--) 
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)            
const ll sz = 2e5+10  ;
ll fact[sz] , inv[sz] , pw[sz] , even_way = 0 , dp[sz][5] , n , k ,mod = 1e9+7 ;
 
 ll BigMod(ll a, ll b)
{
    if(b==0) return 1;
    ll x=BigMod(a, b/2);
    if(b%2==0) return (x*x)%mod;
    x=(x*x)%mod;
    return (x*a)%mod;
}
 
ll Inv(){
  for( ll i = 0 ; i < sz - 1; i++)
    inv[i] = BigMod(fact[i] , mod-2)%mod ;
}
 
ll nCr(ll n , ll r){
  ll down = (inv[r]*inv[n-r])%mod ;
  return (fact[n]*down)%mod ;
}
 
ll solve(ll k , ll isBig){
  if(k == -1) return 1 ;
  ll& ret = dp[k][isBig] ;
  if(dp[k][isBig] != -1) return ret ;
  if(isBig)
    return ret = (pw[n]*solve(k-1 , 1)%mod)%mod;
  if(n&1)
    return ret = (even_way*solve(k-1 , 0)%mod + solve(k-1 , 0)%mod)%mod ;
  return ret = (even_way*solve(k-1 , 0)%mod + solve(k-1 , 1)%mod)%mod ;
}
 
 
int main(){
 
  fact[0] = 1 ;
  for( ll i = 1 ; i < sz-1 ; i++)
    fact[i] = (fact[i-1]*i)%mod ;
  pw[0] = 1 ;
  for( ll i = 1 ; i < sz-1 ; i++)
    pw[i] = (pw[i-1]*2)%mod ;
 Inv() ;
T{ 
  cin >> n >> k ;
  even_way = 0 ;
  memset(dp, -1 , sizeof(dp)) ;
  for( ll i = 0 ; i < n ; i+=2){
    even_way+=nCr(n , i);
    if(even_way >= mod) even_way-=mod ;
  }
  cout << solve(k-1 , 0) << endl ;
 
}
 
            
}