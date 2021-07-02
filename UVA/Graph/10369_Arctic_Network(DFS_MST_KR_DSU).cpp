#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)
        struct edge{
           double  w ;
           ll a , b , x, y;
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
                    if(par == it.first)continue ;
                        vis[it.first] = max(vis[node] , it.second) ;
                        dfs(it.first , node);
                    
                }
            }

         int main(){
   

        T{
            ll n , m , cnt = 0 , tt = 0;
            ll x , y ;
            scanf("%lld %lld", &n , &m) ;
            for( ll i = 0 ; i < m ; i++){
                scanf("%lld %lld", &x , &y) ;
                ar[i].a = x ;
                ar[i].b = y ;
            }

           for( ll i = 0 ; i < m ; i++){
            for( ll j = i+1 ; j < m ; j++){
                 ar[tt].x =i+1 ;
                 ar[tt].y = j+1 ; 
                 ar[tt++].w = sqrt((((ar[i].a - ar[j].a)*(ar[i].a - ar[j].a)) + ((ar[i].b - ar[j].b)*(ar[i].b - ar[j].b)))) ;
            }
           }

           sort(ar , ar+tt , com) ;
           init(tt) ;
        
           double ans ;
           for( ll i = 0 ; i < tt ; i++){
                  if(find(ar[i].x) != find(ar[i].y)){
                    join(ar[i].x , ar[i].y) ;
                    cnt++ ;
                    if(cnt == (m - 1 -(n - 1))) {
                        ans  = ar[i].w ;
                        break ;
                    }
                  }
           }

          printf("%0.2f\n", ans) ;
     }
        

         

           }