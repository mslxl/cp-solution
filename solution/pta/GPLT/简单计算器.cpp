#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int N;
	std::cin >> N;
	std::stack<int> num;
	std::stack<char> ops;
	rep(i, 0, N){
		int c;
		std::cin >> c;
		num.push(c);
	}
	rep(i, 0, N-1){
		char c;
		std::cin >> c;
		ops.push(c);
	}
	while(num.size() > 1){
		int a = num.top();
		num.pop();
		int b = num.top();
		num.pop();
		char op = ops.top();
		ops.pop();
		if(op == '/'){
			if(a == 0){
				std::cout << "ERROR: " << b << '/' << 0; 
				return 0;
			}
			int ret = b/a;
			num.push(ret);
		}else if(op == '*'){
			num.push(a*b);
		}else if(op == '-'){
			num.push(b-a);
		}else if(op == '+'){
			num.push(a+b);
		}
	}
	std::cout << num.top();
	
	return 0;
}
