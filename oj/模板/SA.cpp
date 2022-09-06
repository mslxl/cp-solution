#include<string>
#include<vector>
namespace ojlib{
    std::vector<int> gen_suffix_array(const std::string & s){
        std::vector<int> x(s.begin(), s.end());
        for(auto& i:x)
            i = i -'a' + 1;
        
        std::vector<int> c(s.size());
        for(int i = 0; i < x.size();i++){
            c[x[i]]++;
        }
    }
}