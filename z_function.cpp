#include<bits/stdc++.h>
using namespace std;

//Here comes the code for Z-function in strings.

vector < int > z_fun ( vector < int > &v ) /// returns the Z array for the vector v
{
    int l = 0 , r = 0 ;
    int n = v.size() ;
 
    vector < int > z ( n ) ;
 
    for ( int i = 1 ; i < n ; i ++ )
    {
        if ( i <= r )
            z[i] = min ( z[i - l] , r - i + 1 );
 
        while ( i + z[i] < n && v[z[i]] == v[i + z[i]] )
            z[i] ++ ;
 
        if ( i + z[i] - 1 > r )
            l = i , r = i + z[i] - 1 ;
    }
 
    return z ;
}

int main(){

  return 0;
}
