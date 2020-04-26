#include <functional>

namespace Util {
std::string ltrim(const std::string& s);

std::string rtrim(const std::string& s);

std::string trim(const std::string& s);

void check(const std::function<int(void)>& mainFn, const std::string& test, std::string& fact);
}
