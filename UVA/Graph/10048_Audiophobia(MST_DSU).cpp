#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)
        struct edge{
           ll a , b , w ;
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
            ll find(ll u) {
                if(par[u] == u) return u;
                return par[u] = find(par[u]);
                   }
             void join(int u, int v) {
                 ll upar = find(u) ;
                 ll vpar = find(v) ;
                 if(upar == vpar) return;
                 if(sz[upar] > sz[vpar]) swap(upar , vpar) ;
                 par[upar] = vpar ;
                 sz[vpar]+=sz[upar];
             }

            void dfs(ll node , ll par){
                for(auto it: ad[node]){
                    if(par == it.first)continue ;
                        vis[it.first] = max(vis[node] , it.second) ;
                        dfs(it.first , node);
                    
                }
            }
          
        


         int main(){
           ll tt = 1 ;
               while(1){

               ll n , m , q , x, y , w ;
               scanf("%lld %lld %lld", &n , &m , &q) ;
               init(n) ;
               if(n == 0 and m == 0 and q == 0) break ;
               if(tt > 1) printf("\n");
               for( ll i = 0 ; i < m ; i++){
                scanf("%lld %lld %lld", &x , &y , &w) ;
                ar[i].a = x ;
                ar[i].b = y ;
                ar[i].w =  w ;
               }
               for( ll i = 1 ; i <= n ; i++) ad[i].clear() ;

               sort(ar , ar+m , com) ;
               for( ll i = 0 ; i < m ; i++){
                x = find(ar[i].a) ;
                y = find(ar[i].b) ; 
                if( x != y){
                    join(ar[i].a , ar[i].b) ;
                    ad[ar[i].a].pb({ar[i].b , ar[i].w}) ;
                    ad[ar[i].b].pb({ar[i].a , ar[i].w}) ;
                }
               }
               printf("Case #%lld\n", tt++);
               for( ll i = 0 ; i < q ; i++){
                   scanf("%lld %lld", &x , &y) ;
                   for( ll i = 1 ; i <= n ; i++)
                    vis[i] = 0 ;
                    dfs(x , -1) ;
                     
                    if(vis[y] != 0) printf("%lld\n", vis[y]);
                    else printf("no path\n");

               }

           }

        
        }
         