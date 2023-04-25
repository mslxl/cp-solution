#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

struct User{
	std::string name;
	std::set<int> tags;
	int total;
	bool operator < (const User & rhs) const {
		if(this->tags.size() == rhs.tags.size()){
			return this->total < rhs.total;
		}else{
			return this->tags.size() > rhs.tags.size();	
		}
		
	}
};

std::istream& operator >> (std::istream& is, User& lhs){
	is >> lhs.name;
	int num;
	is >> num;
	rep(i, 0, num){
		int tag;
		std::cin >> tag;
		lhs.tags.insert(tag);
	}
	lhs.total = num;
	return is;
}

int main(){
	int N;
	std::cin >> N;
	std::vector<User> users(N);
	rep(i, 0, N) std::cin >> users[i];
	std::sort(users.begin(), users.end());
	
	rep(i, 0, N) tout << users[i].tags.size() << " ";
	tout << std::endl;
	
	if(N == 1) std::cout << users[0].name << " - -";
	else if(N == 2) std::cout << users[0].name << ' ' << users[1].name << " -";
	else std::cout << users[0].name << ' ' << users[1].name << ' ' << users[2].name;
	
}
