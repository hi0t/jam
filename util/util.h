#include <functional>

namespace util {
    std::string ltrim(const std::string &s);

    std::string rtrim(const std::string &s);

    std::string trim(const std::string &s);

    void checkSimple(const std::function<int(void)> &main, const std::string &test, std::string &fact);
}
