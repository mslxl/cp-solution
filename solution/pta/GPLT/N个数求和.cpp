#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

struct Frac{
	ll top, bottom;
	Frac(ll t = 0, ll b = 0): top(t), bottom(b){
	};
	
	Frac operator+(const Frac& rhs) const{
		Frac res;
		if(rhs.bottom != this->bottom){
			res.bottom = this->bottom * rhs.bottom;
			res.top = this->top * rhs.bottom + rhs.top * this->bottom;
		}else{
			res.bottom = this->bottom;
			res.top = this->top + rhs.top;
		}
		return res;
	}
	Frac reduce() const{
		Frac res;
		ll gcd = std::__gcd(this->bottom, this->top);
		res.top = this->top / gcd;
		res.bottom = this->bottom / gcd;
		return res;
	}
};

std::istream& operator >> (std::istream& os, Frac& frac){
	os >> frac.top;
	if(os.get() == '/'){
		os >> frac.bottom;
	}else{
		frac.bottom = 1;
	}
	return os;
}

std::ostream& operator << (std::ostream& os, Frac& frac){
	if(frac.bottom == 1){
		os << frac.top;
	}else{
		if(frac.top > frac.bottom){
			os << (frac.top / frac.bottom) << " " << (frac.top % frac.bottom)<< "/" << frac.bottom;
		}else{
			os << frac.top << "/" << frac.bottom;
		}
		
	}
	return os;
}

int main(){
	int N;
	std::cin >> N;
	Frac input;
	Frac sum(0,1);
	rep(i, 0, N){
		std::cin >> input;
		test std::cout << "input " << input << std::endl;
		sum = sum + input;
		sum = sum.reduce();
		test std::cout << "sum " << sum << std::endl;
	}
	sum = sum.reduce();
	std::cout << sum;
	return 0;
}

