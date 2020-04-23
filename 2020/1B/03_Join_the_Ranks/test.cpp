#include "utest.h"
#include "util.h"
#define main mainFn
#include "main.cpp"

const string test = R"(
3
2 2
3 2
2 3
)";

const string want = R"(
Case #1: 1
2 1
Case #2: 2
3 2
2 1
Case #3: 2
2 3
2 2
)";

TEST(Solution) {
    string fact;
    util::checkSimple(main, test, fact);
    EXPECT_EQ(util::trim(want), util::trim(fact));
}
