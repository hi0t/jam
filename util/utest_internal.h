#pragma once

#include <functional>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace Internal {
struct TestCase {
    std::string name;
    std::function<void()> pointer;
};

class UnitTest {
public:
    static UnitTest& getInstance()
    {
        static UnitTest instance;
        return instance;
    }

    bool registerTest(const TestCase& test);
    void run();

private:
    UnitTest() = default;
    ~UnitTest() = default;
    UnitTest(const UnitTest&) = delete;
    UnitTest& operator=(const UnitTest&) = delete;

    std::vector<TestCase> listeners;
};

void report(const std::string& val1, const std::string& val2, const std::string& file, int line, bool valid);

template <typename T>
std::string serialize(const std::vector<T>& val)
{
    std::ostringstream ss;

    ss << "[";
    if (!val.empty()) {
        std::copy(val.begin(), val.end() - 1, std::ostream_iterator<T>(ss, ", "));
        ss << val.back();
    }
    ss << "]";

    return ss.str();
}

template <typename T1, typename T2>
bool compare(const T1& val1, const T2& val2, const std::string& file, int line)
{
    std::ostringstream ss1;
    std::ostringstream ss2;

    ss1 << val1;
    ss2 << val2;

    std::string s1(ss1.str());
    std::string s2(ss2.str());

    auto res = (s1 == s2);
    report(s1, s2, file, line, res);
    return res;
}

template <typename T1, typename T2>
bool compare(const std::vector<T1>& val1, const std::vector<T2>& val2, const std::string& file, int line)
{
    return compare(serialize(val1), serialize(val2), file, line);
}

template <typename T1, typename T2>
bool compare(const std::vector<std::vector<T1>>& val1, const std::vector<std::vector<T2>>& val2, const std::string& file, int line)
{
    std::ostringstream ss1;
    std::ostringstream ss2;

    ss1 << "[";
    if (!val1.empty()) {
        auto it = val1.begin();
        ss1 << serialize(*it++);
        for (; it != val1.end(); ++it) {
            ss1 << ", " << serialize(*it);
        }
    }
    ss1 << "]";

    ss2 << "[";
    if (!val1.empty()) {
        auto it = val2.begin();
        ss2 << serialize(*it++);
        for (; it != val2.end(); ++it) {
            ss2 << ", " << serialize(*it);
        }
    }
    ss2 << "]";

    return compare(ss1.str(), ss2.str(), file, line);
}
}
