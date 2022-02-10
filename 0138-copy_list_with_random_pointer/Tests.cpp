#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <map>
#include "Solution.h"

using namespace std;
using namespace leetcode;


class AutoList
{
public:
    AutoList(Node* head) : m_head(head) { }
    ~AutoList()
    {
        freeList(m_head);
    }
    Node* get() { return m_head; }

private:
    Node* m_head = nullptr;

    void freeList(Node* head)
    {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr)
        {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
    }
};

class SolutionTester
{
public:
    // For C++ compatibility replace 'null' with -1
    // Our tests input format will look like this:
    //  {{3,-1},{3,0},{3,-1}}
    //  {}
    //  {{1,1},{2,1}}
    //  {{7,-1},{13,0},{11,4},{10,2},{1,0}}
    void testCopyRandomList(const vector<pair<int,int>>& listDetails)
    {
        AutoList orig(buildList(listDetails));
        Solution solution;
        AutoList copy(solution.copyRandomList(orig.get()));
        verifyDeepCopy(orig.get(), copy.get());
    }

private:
    Node* buildList(const vector<pair<int,int>>& listDetails)
    {
        vector<Node*> nodes;

        for (auto [val, random] : listDetails)
        {
            nodes.push_back(new Node(val));
        }
        for (int i=0; i < nodes.size(); ++i)
        {
            if (i+1 < nodes.size())
            {
                nodes[i]->next = nodes[i+1];
            }
            int randIndex = listDetails[i].second;
            nodes[i]->random = randIndex == -1 ? nullptr : nodes[listDetails[i].second];
        }
        return nodes.size() > 0 ? nodes[0] : nullptr;
    }

    void verifyDeepCopy(Node* orig, Node* copy)
    {
        auto list1 = orig;
        auto list2 = copy;
        while (list1 != nullptr && list2 != nullptr)
        {
            REQUIRE(list1->val == list2->val);
            if(list1->random != nullptr)
            {
                REQUIRE(list2->random != nullptr);
                // check that list2 random points to the copied node
                REQUIRE(list1->random != list2->random);
                REQUIRE(list1->random->val == list2->random->val);
            }
            if(list1->next != nullptr)
            {
                REQUIRE(list2->next != nullptr);
                REQUIRE(list1->next != list2->next);
            }
            list1 = list1->next;
            list2 = list2->next;
        }
    }
};

TEST_CASE("", "[copyListWithRandomPointer]")
{
    SolutionTester tester;

    auto testLists = [&](vector<vector<pair<int,int>>> lists)
    {
        for (auto list : lists)
            tester.testCopyRandomList(list);
    };

    SECTION("A single random pointer")
    {
        testLists({
            {{3,-1},{3,0},{3,-1}},
            {{13,-1},{23,-1},{33,-1},{43,3},{33,-1},{23,-1},{13,-1}}
            });
    }


    SECTION("No random pointers")
    {
        testLists({
            {{100,-1}},
            {{3,-1},{3,-1}},
            {{3,-1},{3,-1},{3,-1}},
            {{13,-1},{23,-1},{33,-1},{43,-1},{33,-1},{23,-1},{13,-1}}
            });
    }

    SECTION("All have random pointers")
    {
        testLists({
            {{7,1},{13,3},{11,4},{10,2},{1,0}},
            {{13,0},{23,0},{33,2},{43,2},{33,4},{23,4},{13,0}},
            {{13,1},{23,2},{33,3},{43,4},{33,5},{23,6},{13,0}}
            });
    }


    SECTION("Multiple pointers to same node")
    {
        testLists({
            {{1,1},{2,1}},
            {{7,-1},{13,0},{11,4},{10,2},{1,0}},
            {{7,0},{13,0},{11,0},{10,0},{1,0}}
            });
    }

    SECTION("Empty set")
    {
        tester.testCopyRandomList({});
    }
}

