#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstring>
int K;
const int maxs = 5e5 + 17;
std::string S;
char A,B;
int prefix[maxs];
int main(){
	std::cin >> K >> S >> A >> B;
	S = "^" + S;
	for(int i = 1; i < S.size(); i++){
		prefix[i] = prefix[i-1] + (S[i] == A);
	}
	int ans = 0;
	for(int i = K; i < S.size(); i++){
		if(S[i] == B){
			ans += prefix[i - K + 1];
		}
	}
	std::cout << ans;
}
