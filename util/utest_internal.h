#pragma once

#include <functional>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

namespace internal {
    struct TestCase {
        std::string           Name;
        std::function<void()> Pointer;
    };

    class UnitTest {
    public:
        static UnitTest& GetInstance() {
            static UnitTest instance;
            return instance;
        }

        bool Register(const TestCase &test);
        void Run();
    private:
        UnitTest() = default;
        ~UnitTest() = default;
        UnitTest(const UnitTest&) = delete;
        UnitTest& operator=(const UnitTest&)= delete;

        std::vector<TestCase> listeners;
    };

    void Report(const std::string &val1, const std::string &val2, const std::string &file, int line, bool valid);

    template<typename VAL1, typename VAL2>
    bool Compare(const VAL1 &val1, const VAL2 &val2, const std::string &file, int line) {
        std::ostringstream ss1;
        std::ostringstream ss2;

        ss1 << val1;
        ss2 << val2;

        std::string s1(ss1.str());
        std::string s2(ss2.str());

        auto res = (s1 == s2);
        Report(s1, s2, file, line, res);
        return res;
    }

    template<typename VAL1, typename VAL2>
    bool Compare(const std::vector<VAL1> &val1, const std::vector<VAL2> &val2, const std::string &file, int line) {
        std::ostringstream ss1;
        std::ostringstream ss2;

        ss1 << "[";
        if (!val1.empty()) {
            std::copy(val1.begin(), val1.end() - 1, std::ostream_iterator<VAL1>(ss1, ", "));
            ss1 << val1.back();
        }
        ss1 << "]";


        ss2 << "[";
        if (!val2.empty()) {
            std::copy(val2.begin(), val2.end() - 1, std::ostream_iterator<VAL2>(ss2, ", "));
            ss2 << val2.back();
        }
        ss2 << "]";

        return Compare(ss1.str(), ss2.str(), file, line);
    }
}
