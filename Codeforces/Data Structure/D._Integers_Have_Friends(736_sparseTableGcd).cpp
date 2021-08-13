#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T ll time;        cin >> time; while(time--) 
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)            

const ll Nmax = 2e5 + 100 ;
ll TP[Nmax] , gt[Nmax][21]  , ar[Nmax] , dif[Nmax]; 

        inline ll GCD(ll l , ll r){
            ll len = (r - l + 1) , k = TP[len] ;
            return __gcd(gt[l][k], gt[r - (1ll<<k) + 1][k]) ;
        }   
         
         int main(){
  
            TP[0] = TP[1] =  0 ; 
            for( ll i = 2 ; i <= Nmax ; i++) TP[i] = TP[i/2] + 1 ;
            T{

                ll n , ret = 1 , ans = 1;
                cin >> n ;
                for( ll i = 0 ; i < n ; i++)
                    cin >> ar[i] ;

                for( ll i =  1 ; i < n ; i++ ){
                    dif[i] = abs(ar[i] - ar[i-1]) ;
                    gt[i][0] = dif[i] ;
                    }
    
                for( ll i = 1 ; i < 20 ; i++){
                    for( ll j = 1 ; j+(1ll<<i)-1 <= n ; j++){
                        gt[j][i] = __gcd(gt[j][i-1] , gt[j+(1ll<<(i-1))][i-1]) ;
                    }
                }

                for( ll i = 1 ; i < n ; i++){
                    ll l = i , h = n-1 , mid , ret = 0 ;
                    while(l <= h){
                        mid = (l+h)/2;
                        if(GCD(i , mid) != 1){
                            ret = mid - i + 1 ;
                            l = mid+1 ;
                        }
                      
                        else h = mid-1 ;
                    }

                    ans = max(ans , ret+1) ;
                }
                cout << ans << endl ;
            }
            
     }
           
 
        