#include "Solution.h"
#include <map>

namespace leetcode
{
using namespace std;

Node* Solution::copyRandomList(Node* head)
{
    map<Node*, Node*> oldToNew;

    Node* orig = head;
    while (orig != nullptr)
    {
        oldToNew[orig] = new Node(orig->val);
        orig = orig->next;
    }

    orig = head;
    while (orig != nullptr)
    {
        Node* copy = oldToNew[orig];
        copy->next = oldToNew[orig->next];
        if (orig->random != nullptr)
        {
            copy->random = oldToNew[orig->random];
        }
        orig = orig->next;
    }
    return oldToNew[head];
}

} // leetcode
