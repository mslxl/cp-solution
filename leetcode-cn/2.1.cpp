#ifdef LOCAL_TEST
#include "leetcode.h"
#include "2.h"
#endif

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto p1 = l1, p2 = l2;
        // Previous loop number part which excess 10
        // Need plus to this loop number
        auto plus = 0;
        // Both pointer are not be nullptr
        while (true)
        {
            p1->val += p2->val + plus;
            if (p1->val >= 10)
            {
                plus = p1->val / 10;
                p1->val %= 10;
            }
            else
            {
                plus = 0;
            }
            if(p1->next == nullptr || p2->next == nullptr){
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // If the target link is nullptr
        if (p1->next == nullptr && p2->next != nullptr)
        {
            p1->next = p2->next;
        }
        
        // Make sure all plus number are plus
        while (plus != 0)
        {
            if(p1->next == nullptr){
                p1->next = new ListNode(0);
            }
            p1 = p1->next;
            p1->val += plus;
            if (p1->val >= 10)
            {
                plus = p1->val / 10;
                p1->val %= 10;
            }
            else
            {
                plus = 0;
            }
        }

        return l1;
    }
};

#ifdef LOCAL_TEST

int main()
{
    int i1[] = {2, 4, 3};
    int i2[] = {5, 6, 4};
    auto l1 = create_link(i1, i1 + sizeof(i1) / sizeof(int));
    auto l2 = create_link(i2, i2 + sizeof(i2) / sizeof(int));
    println_link(l1);
    println_link(l2);
    Solution solution;
    auto result = solution.addTwoNumbers(l1, l2);
    print_link(result);

    return 0;
}
#endif