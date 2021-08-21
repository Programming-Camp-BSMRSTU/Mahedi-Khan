#include<bits/stdc++.h>
using namespace std;
#define ll   long long int 
#define pb   push_back
#define T ll time;        cin >> time; while(time--) 
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)            
const ll Nmax = 5001000 , mod = 1e9+7;
 double ar[Nmax] ;

 
 void cal(){
    for( ll i = 1 ; i < Nmax ; i++)
        ar[i] = ar[i-1] + log10(i) ;
 }
       

int main(){
        cal() ;
        ll tt = 1 ;
        T{
            ll n , b ;
            cin >> n >> b ;
            printf("Case %lld: %lld\n", tt++ , (ll)((ar[n] / log10(b) ) + 1));   
   }
        }

    


    



            
