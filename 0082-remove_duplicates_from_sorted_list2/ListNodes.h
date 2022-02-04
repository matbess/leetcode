#ifndef LISTNODES_H
#define LISTNODES_H

#include <deque>
#include <vector>
#include <memory>
#include "ListNode.h"

namespace leetcode
{

using ListNodePtr_t = std::shared_ptr<ListNode>;

class ListNodes
{
public:
    ListNodes(const std::vector<int>& values);

    ListNode* Head();

private:
    std::deque<ListNodePtr_t> nodePtrs;
};

} // namespace leetcode

#endif // LISTNODES_H
