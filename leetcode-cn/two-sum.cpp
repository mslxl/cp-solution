#ifdef LOCAL_TEST
#include "leetcode.h"
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if(nums[i] + nums[j] == target){
                    int ret[] = {i,j};
                    return vector<int>(ret,ret+2);
                }
            }
        }
        return vector<int>();
    }
};
#ifdef LOCAL_TEST
int main()
{
    
    return 0;
}
#endif