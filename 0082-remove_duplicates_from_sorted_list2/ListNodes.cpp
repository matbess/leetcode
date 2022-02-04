#include "ListNodes.h"

namespace leetcode
{
using namespace std;

ListNodes::ListNodes(const std::vector<int>& values)
{
    ListNode* next = nullptr;
    for (int i = values.size()-1; i >= 0; --i)
    {
        auto node = make_shared<ListNode>(values[i], next);
        nodePtrs.push_front(node);
        next = node.get();
    }
}

ListNode* ListNodes::Head()
{
    if (!nodePtrs.empty())
        return nodePtrs.front().get();
    return nullptr;
}

} // namespace leetcode
