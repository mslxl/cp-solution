#include<iostream>
#include<cmath>

#define ll long long

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int N;
	std::cin >> N;
  int tot = N;
	ll min = -0x3f3f3f3f, max = 0x3f3f3f3f;
	while(N--){
		ll A,B;
		std::cin >> A >> B;
		ll cmin = 0x3f3f3f3f, cmax = -0x3f3f3f3f;
		ll L = 1, R = A, mid;
		while(L <= R){
			mid = (L + R) / 2;
			if(A / mid > B){
				L = mid + 1;
			}else{
				R = mid - 1;
				cmin = mid;
			}
		}
		L = 1, R = A;
		while(L <= R){
			mid = (L + R) / 2;
			if(A / mid >= B){
				L = mid + 1;
				cmax = mid;
			}else{
				R = mid - 1;
			}
		}


		max = std::min(max, cmax);
		min = std::max(min, cmin);
	  if(min > max){
	    std::cerr << "oppos! min > max on item " << tot - N << std::endl;
	  }
	}
	std::cout << min << " " << max;

	return 0;
}
