#include "utest.h"
#include "util.h"
#define main mainFn
#include "main.cpp"

const string test = R"(
5
4 4 SSSS
3 0 SNSS
2 10 NSNNSN
0 1 S
2 7 SSSSSSSS
)";

const string want = R"(
Case #1: 4
Case #2: IMPOSSIBLE
Case #3: IMPOSSIBLE
Case #4: 1
Case #5: 5
)";

TEST(Solution)
{
    string fact;
    Util::check(main, test, fact);
    EXPECT_EQ(Util::trim(want), Util::trim(fact));
}
