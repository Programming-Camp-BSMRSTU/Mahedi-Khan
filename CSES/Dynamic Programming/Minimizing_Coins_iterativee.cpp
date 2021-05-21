#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
const ll N=1000000;
const ll Nmax = 5e15+1;
 ll ar[N+100] ; 
 
        int main(){

            ll n , x , save;
            cin >> n >> x ;
            ll coin[n+2] ;

            for( ll i = 0 ; i < n ; i++)
            cin >> coin[i] ;
            for( ll j = 1 ; j <= x ; j++) 
            ar[j] = Nmax ;
            ar[0] = 0 ;
            for( ll i = 0 ; i <= x ; i++){
                if(ar[i] != Nmax)
                for( ll j = 0 ; j < n ; j++){
                    save = i + coin[j] ;
                    if(save <= x) ar[save] = min(ar[save] , ar[i]+1) ;
                }
            }
            if(ar[x] == Nmax) cout << "-1" << endl ;
            else cout << ar[x] << endl ;

    }
