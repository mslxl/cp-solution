#include<iostream>
#include<algorithm>
#define ll long long
const int maxn = 10 + 17;

struct Plane{
	ll T = 0, D = 0, L = 0;
	bool operator<(const Plane & rhs) const {
		return rhs.T+rhs.D+ rhs.L < T + D + L;
	}
};

Plane p[maxn];
ll N;

void solve(){
	std::cin >> N;
	for(int i = 0; i < N; i++){
		std::cin >> p[i].T >> p[i].D >> p[i].L;
	}
	std::sort(p, p+N);
	ll safeTime = 3e5 + 17;
	for(int i = 0; i < N; i++){
		if(p[i].T + p[i].D + p[i].L <= safeTime){
			safeTime = p[i].T + p[i].D;
		}else{
			if(p[i].T + p[i].L <= safeTime){
				safeTime -= p[i].L;
			}else{
				std::cout << "NO";
				return;
			}
		}
	}
	std::cout << "YES";
}
int main(){
	int T;
	std::cin >> T;
	while(T--){
		solve();
		if(T != 0){
			std::cout << "\n";
		}
	}
	return 0;
}
