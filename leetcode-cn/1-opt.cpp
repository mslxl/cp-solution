#ifdef LOCAL_TEST
#include "leetcode.h"
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            
            if(map.find(target - nums[i]) != map.end()){
                return {map[target - nums[i]],i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
#ifdef LOCAL_TEST
int main()
{
    
    return 0;
}
#endif
