#include "util.h"
#include <iostream>
#include <sstream>

using namespace std;

namespace Util {

const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string& s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string& s)
{
    return rtrim(ltrim(s));
}

void check(const function<int(void)>& mainFn, const string& test, string& fact)
{
    istringstream in(test);
    auto cinbuf = cin.rdbuf(in.rdbuf());

    ostringstream out;
    auto coutbuf = cout.rdbuf(out.rdbuf());

    mainFn();
    fact = "\n" + out.str();

    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
}

}
