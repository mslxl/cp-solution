#include "leetcode.h"
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        std::sort(beans.begin(), beans.end());
        std::vector<long long> pre;
        pre.push_back(0);
        for(auto v: beans){
            pre.push_back(v);
        }
        for(int i = 1; i <= beans.size(); i++){
            pre[i] = pre[i] + pre[i-1];
        }
        long long min = pre.back();
        for(int i = 1; i < pre.size(); i++){
            long long front = pre[i-1];
            long long back = (pre.back() - pre[i - 1]) - (pre.size() - i) * beans[i-1]; 
            min = std::min(min, front + back);
        }
        return min;
    }
};