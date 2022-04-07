#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
int N;

struct Point{
	int x,y;
};

double calc_slope(const Point& l, const Point& r){
	return 1.0 * (r.y - l.y) / (r.x - l.x);
}

double calc_slope(const Point&& l, const Point&& r){
	return calc_slope(std::move(l), std::move(r));
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> N;
	std::vector<Point> vertex(N);
	rep(i, 0, N){
		Point &pt = vertex[i];
		std::cin >> pt.x >> pt.y;
	}
	// make sure the order of point 
	std::sort(vertex.begin(), vertex.end(), [](const Point &lhs, const Point &rhs)->bool{
		return lhs.x < rhs.x;
	});
	std::vector<double> slope(N);
	
	// calc slope rate
	rep(i, 1, N){
		const auto &detect = vertex[i];
		const auto &previous = vertex[i-1];
		slope[i - 1] = 1.0 * (detect.y - previous.y) / (detect.x - previous.x);
		
		test std::cout << (i-1) << "th slope rate " << slope[i - 1] << std::endl; 
	}
	
	int ans = 0;
	
	bool U_terria_existed = false; 
	rep(i, 1, N){
		const auto previous = slope[i-1];
		const auto detect = slope[i];
		if(previous < detect){
			// U terria
			U_terria_existed = true;
		}
		if(detect < previous && U_terria_existed){
			// n terria
			if(i != N - 1){
				ans++;
			}
			U_terria_existed = false;
		}
	}
	std::cout << ans; 
	
	return 0;
}

