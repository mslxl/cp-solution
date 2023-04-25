#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
typedef unsigned long long ll;
ll gcd(ll a, ll b){
    ll mb = a % b;
    if(mb == 0){
        return b;
    } else {
        return gcd(b,mb);
    }

}
int main(int argc, char const *argv[]){
    std::ios::sync_with_stdio(false);
    ll a, b, c;
    std::cin >> a >> b >> c;
    ll tmp = (a*b)/gcd(a,b); 
    ll max_day =  tmp * c / gcd(tmp, c);
    std::cout << max_day;
    return 0;
}
