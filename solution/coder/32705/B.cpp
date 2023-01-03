#include<bits/stdc++.h>
#define int long long
struct Frac{
	int t,b;
	
	Frac operator * (const Frac&rhs) const{
		return Frac{
			t * rhs.t,
			b * rhs.b
		};
	}
	
	Frac operator * (int v) const {
		return Frac{
			v * t,
			b
		};
	} 
	
	Frac operator + (const Frac& v) const {
		return Frac{
			t * v.b + v.t * b,
			b * v.b
		};
	}
	
	Frac reduce(){
		int g = std::__gcd(t,b);
		if(g == 0){
			return Frac{
				t,
				b
			};
		}
		return Frac{
			t/g,
			b/g
		};
	}
};

signed main(){
	std::string line;
	std::cin >> line;
	Frac result{0,1};
	Frac f{1,1};
	for(long i = line.size()-1; i >= 0; i--){
		result = result + Frac{line[i]-'0', 1} * f;
		f = f * Frac{3,2};
		result = result.reduce();
	}
	if(result.b == 1){
		std::cout << result.t;
	}else{
		std::cout << result.t / result.b;
		result.t %= result.b;
		std::cout << " " << result.t << "/" << result.b;
	}
	
	return 0;
}
