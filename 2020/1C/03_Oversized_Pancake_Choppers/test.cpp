#include "utest.h"
#include "util.h"
#define main mainFn
#include "main.cpp"

const string test = R"(
4
1 3
1
5 2
10 5 359999999999 123456789 10
2 3
8 4
3 2
1 2 3
)";

const string want = R"(
Case #1: 2
Case #2: 0
Case #3: 1
Case #4: 1
)";

TEST(Solution)
{
    string fact;
    Util::check(main, test, fact);
    EXPECT_EQ(Util::trim(want), Util::trim(fact));
}
