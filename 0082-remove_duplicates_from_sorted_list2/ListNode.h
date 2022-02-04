#ifndef LISTNODE_H
#define LISTNODE_H

namespace leetcode
{

// The provided definition for singly-linked list
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

} // namespace leetcode

#endif // LISTNODE_H
