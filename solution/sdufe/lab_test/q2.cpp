#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<set>

std::vector<int> gen_randseq(){
	std::vector<int> seq(1000);
	srand((unsigned)time(NULL));
	for(std::size_t i = 0; i < seq.size(); i++){
		int rdm = rand() % 1000;
		seq[i] = rdm;
		std::cout << rdm << std::endl;
	}
	return seq;
}


struct vec{
	int x,y,z;
	double distance(const vec& rhs) const {
		return std::sqrt(
			std::pow(rhs.x - x,2 ) 
			+ std::pow(rhs.y - y,2) 
			+ std::pow(rhs.z - z,2));
	}
};


std::ostream& operator<<(std::ostream& os, const vec& v){
	return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

std::vector<vec> gen_vec_by_window(std::vector<int> & rand_seq, int stride = 1){
	std::vector<vec> res;
	for(std::size_t i = 0; i + 2 < rand_seq.size(); i+= stride){
		res.push_back(vec{
			rand_seq[i],
			rand_seq[i+1],
			rand_seq[i+2]
		});
	}
	return res;
}

std::vector<std::vector<vec>> group(10);
std::set<int> base_vec;

std::map<int, std::map<int, int>> sim; //a,b 的 dis



int main(){
	auto rand_seq = gen_randseq();
	std::vector<vec> v = gen_vec_by_window(rand_seq);
	for(std::size_t i = 0 ; i < v.size(); i++){
		for(std::size_t j = 0; j < v.size(); j++){
			sim[i][j] = v[i].distance(v[j]);
		}
	}
	
	
	while(base_vec.size() < 10){
		int max_dis = 0;
		int v1, v2;
		for(std::size_t i = 0; i < v.size(); i++){
			for(std::size_t j = 0; j < v.size(); j++){
				
				if(sim[i][j] > max_dis && (!base_vec.count(j)) && (!base_vec.count(i))){
					v1 = i;
					v2 = j;
					max_dis = sim[i][j];
				}
				
			}
		}

		std::cout << base_vec.size() << std::endl;
		base_vec.insert(v2);
		if(base_vec.size() < 10){
			base_vec.insert(v1);
		}
	}
	
	
	
	std::vector<int> ids(base_vec.begin(), base_vec.end());
	
	for(std::size_t i = 0; i < v.size(); i++){
		int min_dis = INT32_MAX;
		int group_id = -1;
		for(int j = 0; j < 10; j++){
			if(sim[ids[j]][i] < min_dis){
				min_dis = sim[ids[j]][j];
				group_id = j;
			}
		}
		group[group_id].push_back(v[i]);
		
	}
	
	for(std::size_t i = 0; i < 10; i++){
		std::cout << "group " << i << ": ";
		for(auto vvv : group[i]){
			std::cout << vvv << " ";
		}
		std::cout << std::endl;
	}
	
	
	return 0;
	
}
