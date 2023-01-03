#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif

#define rep(var, initial, end) for(int var = initial; var < end; var++)

typedef long long ll;
const int maxi = 100 + 3;
int score[maxi] = {0};
int std_ans[maxi] = {0};

int student, q;
int main(){
	std::cin >> student >> q;
	rep(i, 0, q){
		std::cin >> score[i];
	}
	rep(i, 0, q){
		std::cin >> std_ans[i];
	}
	rep(i, 0, student){
		int g = 0, input;
		rep(j, 0, q){
			std::cin >> input;
			if(input == std_ans[j]){
				g+=score[j];
			}
		}
		std::cout << g << std::endl;
	}
	return 0;
}
