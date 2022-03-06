#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Solution.h"

using namespace leetcode;

TEST_CASE("countOrders", "[countOrders]")
{
// Explanation:
//
// n=2:
//    result is 6 seqs like: (P1,D1,P2,D2)
// 
// n=3:
//    Add (P3,D3) to each of the 6 n=2 seq (P1,D1,P2,D2):
//    Take (P1,D1,P2,D2):
//      With D3 at the end (P1,D1,P2,D2,D3) there are 5 posibilities for P3.
//      (P1,D1,P2,D3,D2) => 4 valid places for P3
//      (P1,D1,D3,P2,D2) => 3 valid places for P3
//      (P1,D3,D1,P2,D2) => 2 valid places for P3
//      (D3,P1,D1,P2,D2) => 1 valid place for P3
//    For each seq in n=2 there are 5+4+3+2+1 posibilities
//      and there are a total of 6 seqs when n=2
//    total(n=3) = 6 * (5+4+3+2+1) = 90
//    result is 90 seqs like: (P1,D1,P2,D2,P3,D3)
//
// for n:
//    each resulting seq has n*2 items in it
//    need to add (Pn,Dn) to each seq of n-1
//
// total(3) = 6 * (5+4+3+2+1) = 90
//          = total(2) * sum(5...1) = 90
//          = total(2) * sum((n*2)-1...1) = 90
//          = total(2) * ((2n-1)+(2n-2)+...+1) = 90
//          = total(2) * ((2n-1)+(2n-2)+(2n-3)+(2n-4)+1) = 90
//          = total(2) * ((6-1)+(6-2)+(6-3)+(6-4)+1) = 90
//          = 6 * (5+4+3+2+1) = 90
//
// formula:
//    total(1) = 1
//    n > 1:
//    total(n) = total(n-1) * ((2n-1)+(2n-2)+...+1)
// 
// examples:
// total(1) = 1
// total(2) = total(1) * ((4-1)+(4-2)+(4-3))
//          = 1 * (3+2+1)
//          = 3+2+1
//          = 6
// total(3) = total(2) * ((2n-1)+(2n-2)+...+1)
//          = total(2) * ((6-1)+...+1)
//          = total(2) * (5+4+3+2+1)
//          = 6 * 15
//          = 90
// total(4) = total(3) * (7+...+1)
//          = 90 * (7+6+5+4+3+2+1)
//          = 90 * 28
//          = 2520

    Solution s;
    SECTION("Verify answer")
    {
        REQUIRE(s.countOrders(1) == 1);
        REQUIRE(s.countOrders(2) == 6);
        REQUIRE(s.countOrders(3) == 90);
        REQUIRE(s.countOrders(4) == 2520);
        REQUIRE(s.countOrders(5) == 113400);
        REQUIRE(s.countOrders(7) == 681080400);
        REQUIRE(s.countOrders(8) == 729647433);
        REQUIRE(s.countOrders(9) == 636056472);
        REQUIRE(s.countOrders(10) == 850728840);
        REQUIRE(s.countOrders(20) == 580270580);
        REQUIRE(s.countOrders(34) == 765945940);
        REQUIRE(s.countOrders(100) == 14159051);
        REQUIRE(s.countOrders(500) == 764678010);
    }
}

