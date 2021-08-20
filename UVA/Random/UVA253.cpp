#include<bits/stdc++.h>
using namespace std;
#define ll   long long int 
#define pb   push_back
#define T ll time;        cin >> time; while(time--) 
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)            
const ll Nmax = 5001000 , mod = 1e9+7;

string tem , s ;

bool milche(){
    for( ll i = 0 ; i < 6 ; i++)
        if(s[i] != s[i+6]) return false ;

    return true ;
}

void rotateX(){
    char tm = s[0] ;
    s[0] = s[4] ;
    s[4] = s[5] ;
    s[5] = s[1] ;
    s[1] = tm ;
}

void rotateZ(){
    char tm = s[1] ;
    s[1] = s[3] ;
    s[3] = s[4] ;
    s[4] = s[2] ;
    s[2] = tm ;
}

void rotateY(){
    char tm = s[0] ;
    s[0] = s[3] ;
    s[3] = s[5] ;
    s[5] = s[2] ;
    s[2] = tm ;
}


int main(){

    while(cin >> s){
         tem = s ; 

         ll mile = 0;

      
         for( ll i = 0 ; i < 4 ; i++){
            mile |= milche() ;
            rotateX() ;
            mile |= milche() ;
            for( ll j = 0 ; j < 4 ; j++){
                rotateZ() ;
                mile |= milche() ;
            } 
         }
        s = tem ;
           for( ll i = 0 ; i < 4 ; i++){
            mile |= milche() ;
            rotateY() ;
            mile |= milche() ;
            for( ll j = 0 ; j < 4 ; j++){
                rotateZ() ;
                mile |= milche() ;
            } 
         }

         if(mile) cout << "TRUE" << endl ;
         else cout << "FALSE" << endl ;
    }

}



    


    



            
