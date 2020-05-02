#include "utest.h"
#include "util.h"
#define main mainFn
#include "main.cpp"

const string test = R"(
)";

const string want = R"(
)";

TEST(Solution)
{
    string fact;
    Util::check(main, test, fact);
    EXPECT_EQ(Util::trim(want), Util::trim(fact));
}
