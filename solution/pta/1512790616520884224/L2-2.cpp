#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
int D, P;

struct Person{
	std::string name;
	std::string id;
	int feel;
	int hh;
	int mm;
};
std::istream& operator >> (std::istream& is, Person& rhs){
	is >> rhs.name >> rhs.id >> rhs.feel;
	is >> rhs.hh;
	is.get();
	is >> rhs.mm;
	return is;
}
std::map<std::string, int> apply_time;

void solve_day(){
	int T,S;
	std::cin >> T >> S;
	std::vector<Person> ppl(T);
	rep(i, 0 ,T){
		Person pp;
		std::cin >> pp;
		ppl[i] = pp;
	}
	
		
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> D >> P;
	rep(i, 0, D){
		solve_day();
	}
	
	
	return 0;
}
