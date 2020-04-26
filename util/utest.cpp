#include "utest.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace Internal {

bool UnitTest::registerTest(const TestCase& test)
{
    auto it = find_if(listeners.begin(), listeners.end(), [&test](const TestCase& obj) { return obj.name == test.name; });
    if (it != listeners.end()) {
        return false;
    }
    listeners.push_back(test);
    return true;
}

void UnitTest::run()
{
    for (auto& l : listeners) {
        l.pointer();
    }
}

void report(const string& val1, const string& val2, const string& file, int line, bool valid)
{
    if (valid) {
        cout << file << ":" << line << ": \033[32m"
             << "PASSED"
             << "\033[0m" << endl;
        return;
    }

    cout << file << ":" << line << ": \033[31m"
         << "FAILED"
         << "\033[0m" << endl;
    istringstream ss1(val1);
    istringstream ss2(val2);
    string s1;
    string s2;
    while (getline(ss1, s1) && getline(ss2, s2)) {
        if (s1 != s2) {
            cout << "\t" << s1 << " != " << s2 << endl;
        }
    }
    while (getline(ss1, s1)) {
        cout << "\t" << s1 << " != <empty>" << endl;
    }
    while (getline(ss2, s2)) {
        cout << "\t"
             << "<empty> != " << s2 << endl;
    }
}

}

int main()
{
    Internal::UnitTest::getInstance().run();
    return 0;
}
