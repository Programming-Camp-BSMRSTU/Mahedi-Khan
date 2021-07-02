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
         vector < ll > ad[N] ;
          
             void init( ll n ) {
                  for (int i=0; i<=n; i++) {
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

            void dfs(ll node){
                vis[node] = 1 ;
                for(auto it: ad[node])
                    if(!vis[it])dfs(it) ;
            }
          
        


         int main(){
            ll tt = 1 ;
               T{
            ll n , m , x , y , w , tot = 0 , sum= 0 , a , A , inf = 1e17 , z  ;
             scanf("%lld %lld %lld", &n , &m, &A) ;
            
        
            for( ll i = 0 ; i <= n ; i++)
                ad[i].clear(), vis[i] = 0  ;
            
            init(n) ;
            map < ll , ll > mp ;
            for( ll i = 0 ; i < m; i++){
              scanf("%lld  %lld  %lld", &x , &y, &z) ;
                ar[i].a = x ;
                ar[i].b = y ;
                ar[i].w = z ;
            
                ad[x].pb(y) ;
                ad[y].pb(x) ;
                mp[x] = 1 , mp[y] = 1 ;  
            }
          
            sort(ar , ar+m , com) ; 
            for(ll i = 0 ; i < m ; i++){ 
                x = find(ar[i].a) ;
                y = find(ar[i].b) ;
                if(x != y){
                    sum+=ar[i].w ;
                    join(ar[i].a , ar[i].b) ;
                    if(ar[i].w >= A) sum-=ar[i].w , tot++ ;
                }
            }


            for( ll i = 1 ; i <= n ; i++){
                if(!vis[i]){
                    tot++ ;
                    dfs(i) ;
                }  
               
            } sum+=A*tot;
            printf("Case #%lld: %lld %lld\n", tt++, (sum), tot) ;
        }
        
        }