#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)

            ll EEA( ll a , ll b , ll &x , ll &y){
                if(b == 0){
                    x = 1 ;
                    y = 0 ;
                    return a ;
                }
                ll x1 , y1 ;
                ll gcd = EEA(b , a%b , x1 , y1) ;
                x = y1 ;
                y = (x1 - (y1*(a/b))) ;
                return gcd ;
            }
            

               int main(){

                ll a , b , x , y , gcd;
                while(cin >> a >> b){
               gcd =  EEA(a , b , x , y) ;
               // if(x > y) swap(x , y) ;
                cout << x << " " << y << " "<< gcd << endl ;
            }
            return 0 ;

               }
               

