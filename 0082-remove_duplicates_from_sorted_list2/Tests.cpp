#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch.hpp"
#include "Solution.h"
#include "ListNodes.h"

using namespace std;
using namespace leetcode;

void VerifyResults(ListNode* head, const vector<int>& expectedValues)
{
    auto node = head;
    for (int expected : expectedValues)
    {
        REQUIRE(node != nullptr);
        REQUIRE(node->val == expected);
        node = node->next;
    }
    REQUIRE(node == nullptr);
}

TEST_CASE("deleteDuplicates", "[deleteDuplicates]")
{
    Solution solution;

    SECTION("Consecutive duplicates in middle of list")
    {
        ListNodes nodes({5,7,7,8,8,8,9,9,9,9,10});
        auto head = solution.deleteDuplicates(nodes.Head());
        VerifyResults(head, {5,10});
    }

    SECTION("Consecutive duplicates at beginning of list")
    {
        ListNodes nodes({7,7,8,8,8,10,11,12});
        auto head = solution.deleteDuplicates(nodes.Head());
        VerifyResults(head, {10,11,12});
    }

    SECTION("Consecutive duplicates at end of list")
    {
        ListNodes nodes({1,2,7,7,8,8,8});
        auto head = solution.deleteDuplicates(nodes.Head());
        VerifyResults(head, {1,2});
    }

    SECTION("Entire list is duplicates")
    {
        ListNodes nodes1({7,7,8,8,8,8,8,8});
        auto result = solution.deleteDuplicates(nodes1.Head());
        VerifyResults(result, {});

        ListNodes nodes2({7,7});
        auto result2 = solution.deleteDuplicates(nodes2.Head());
        VerifyResults(result2, {});
    }

    SECTION("Duplicates spread throughout list")
    {
        ListNodes nodes({1,2,6,6,7,8,8,8,8,9,9,10,11,11,12});
        auto head = solution.deleteDuplicates(nodes.Head());
        VerifyResults(head, {1,2,7,10,12});
    }
}
