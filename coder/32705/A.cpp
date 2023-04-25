#include<bits/stdc++.h>
int T,F,S,P,C;

void solve(){
	std::cin >> T >> F >> S >> P >> C;
	std::cout <<  T * 6 + F * 3 + S * 2 + P + 2 * C;
}
int main(){
	solve();
	std::cout << " ";
	solve();
	return 0;
}
