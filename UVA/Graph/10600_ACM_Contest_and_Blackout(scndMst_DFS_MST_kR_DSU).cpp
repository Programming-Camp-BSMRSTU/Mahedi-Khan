#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)
        struct edge{
        
           ll a , b , x, y , w;
        };
        
        bool com(edge a , edge b){
            if(a.w < b.w) return true ;
            return false ;
        }

         const int N = 1000000;
         ll par[N], sz[N] ,vis[N];
         edge ar[N] ;
         vector < pair < ll , ll > > ad[N] ;
          
             void init( ll n ) {
                  for (int i=1; i<=n; i++) {
                     par[i] = i;
                     sz[i] = 1;
                 }
             }
            double find(ll u) {
                if(par[u] == u) return u;
                return par[u] = find(par[u]);
                   }
             void join(ll u, ll v) {
                 ll upar = find(u) ;
                 ll vpar = find(v) ;
                 if(upar == vpar) return;
                 if(sz[upar] > sz[vpar]) swap(upar , vpar) ;
                 par[upar] = vpar ;
                 sz[vpar]+=sz[upar];
             }

             void dfs(ll node , ll par){
                  for(auto it: ad[node]){
                    if(it.first == par) continue ;
                    vis[it.first] = max(vis[node] , it.second) ;
                    dfs(it.first , node) ;
                  }
             }


                int main(){
                    T{
                      ll  n  , m , x, y , w ,mst1 = 0 , mst2 = 1e17 ;
                      scanf("%lld %lld", &n , &m) ;
                      for( ll i = 0 ; i < m ; i++){
                        scanf("%lld %lld %lld", &x , &y , &w) ;
                        ar[i].a =  x ;
                        ar[i].b =  y ;
                        ar[i].w =  w ;
                      }
                      init(n) ;
                      sort(ar, ar+m , com) ;
                      for( ll i = 0 ; i <= n ; i++) ad[i].clear() ;
                      for( ll i = 0 ; i < m ; i++){
                        if(find(ar[i].a) != find(ar[i].b)){
                            join(ar[i].a , ar[i].b) ;
                            ad[ar[i].a].pb({ar[i].b , ar[i].w}) ;
                            ad[ar[i].b].pb({ar[i].a , ar[i].w}) ; 
                            mst1+=ar[i].w ;
                            ar[i].w = -1 ;
                        }
                      }

                      for( ll i = 0 ; i < m ; i++){
                        if(ar[i].w != - 1){
                            for( ll i = 0 ; i <= n ; i++) vis[i] = 0 ;
                                dfs(ar[i].a, -1) ; 
                            mst2 = min(mst2 , ((mst1-vis[ar[i].b]) + ar[i].w)) ;
                        }
                      }
                      cout << mst1 << " " << mst2 << endl ;
                  }

                }