#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = s; i < e; i++)
typedef long long ll;

/**
* Convert time in HH:MM format into the minutes from 00:00
* e.g. "01:00" -> 60
*/

int time2stamp(const std::string& time){
	assert(time.size() == 5);
	int hour = (time[0] - '0') * 10 + (time[1] - '0');
	int min = (time[3] - '0') * 10 + (time[4] - '0');
	return hour * 60 + min;
}

void solve_day(){
	std::map<int, int> record;
	int id;
	char op;
	std::string time;

	std::cin >> id >> op >> time;

	double read_times = 0, read_consume = 0;

	while(id != 0){
		if(op == 'S'){
			record[id] = time2stamp(time);
		}else if(op == 'E'){
			// Ignore it if it have not 'S' record in map
			if(record.count(id)){
				read_times++;
				read_consume += time2stamp(time) - record[id];
				record.erase(id);
			}
		}
		std::cin >> id >> op >> time;
	}
	if(read_times == 0){
		std::cout << 0 << ' ' << 0 << std::endl;
	}else{
		std::cout << read_times << ' ' << std::round(read_consume/read_times) << std::endl;
	}
}

int main(){
	int q;
	std::cin >> q;
	rep(i, 0, q){
		solve_day();
	}
	return 0;
}
