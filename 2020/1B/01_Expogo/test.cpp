#include "utest.h"
#include "util.h"
#define main mainFn
#include "main.cpp"

const string test = R"(
8
0 1
7 10
-11 2
0 0
2 3
-2 -3
3 0
-1 1
)";

const string want = R"(
Case #1: N
Case #2: WSSEN
Case #3: ENWW
Case #4: IMPOSSIBLE
Case #5: SEN
Case #6: NWS
Case #7: EE
Case #8: IMPOSSIBLE
)";

TEST(Solution) {
    string fact;
    util::checkSimple(main, test, fact);
    EXPECT_EQ(util::trim(want), util::trim(fact));
}
