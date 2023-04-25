#ifdef LOCAL_TEST
#include "leetcode.h"
#endif


class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int number = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[number] != nums[i])
            {
                number++;
                nums[number] = nums[i];
            }
        }
        return (number + 1);
    }
};

#ifdef LOCAL_TEST
int main()
{
    
    return 0;
}
#endif