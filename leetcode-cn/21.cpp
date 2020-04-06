#ifdef LOCAL_TEST
#include "leetcode.h"
#endif
//--
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        vector<int>::iterator it = nums.begin();
        int num = *it;
        for (++it; it != nums.end();)
        {
            if (*it == num)
            {
                nums.erase(it);
            }else{
                num = *it;
                ++it;
            }
        }
        return nums.size();
    }
};

#ifdef LOCAL_TEST
int main()
{
    
    return 0;
}
#endif