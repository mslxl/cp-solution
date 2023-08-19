#include <iostream>
#include <string>
#include <unordered_map>
#include<vector>
using namespace std;

bool check (string A, string B){
    return(A[0]=='J'&&B[0]=='M')
        ||(A[0]=='M'&&B[0]=='T')
        ||(A[0]=='T'&&B[0]=='S')
        ||(A[0]=='S'&&B[0]=='H')
        ||(A[0]=='H'&&B[0]=='J');
}



int main (){
    int n,a=0,b=0;
    string A,B;
    cin >> n;
    while (n--){
        cin >> A>>B;
        if(check (A,B))
            a += 3;
        else if(check (B,A))
            b += 3;
        else
            a++,b++;
    }
    if( a >b)
      cout <<"Alice" ;
    else if (b > a)
     cout <<"Bob" ;
    else
     cout <<"Draw" ;
    return 0;
}
