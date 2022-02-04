#include "Solution.h"

namespace leetcode
{

ListNode* Solution::deleteDuplicates(ListNode* head)
{
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* front = head;

    while (curr != nullptr)
    {
        bool currIsDupe = false;
        // loop to remove the full sequence of duplicates that might follow
        while (curr->next != nullptr && curr->val == curr->next->val)
        {
            currIsDupe = true;
            auto nextNext = curr->next->next;
            curr->next->next = nullptr;
            curr->next = nextNext;
        }
        if (currIsDupe)
        {
            auto next = curr->next;
            curr->next = nullptr;
            if (prev != nullptr)
                prev->next = next;
            if (front == curr)
                front = next;
            curr = next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return front;
}

} // leetcode
