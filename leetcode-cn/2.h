#pragma once
#include "leetcode.h"
//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *create_link(int *begin, int *end)
{
    if (begin != end)
    {
        auto node = new ListNode(*begin);
        node->next = create_link(begin + 1, end);
        return node;
    }
    else
    {
        return nullptr;
    }
}
void print_link(ListNode *node)
{
    std::cout << node->val;
    if (node->next != nullptr)
    {
        std::cout << " -> ";
        print_link(node->next);
    }
}
void println_link(ListNode *node)
{
    print_link(node);
    std::cout << std::endl;
}