#include "CTRPluginFramework/Utils/StringExtensions.hpp"

namespace CTRPluginFramework {

  std::string ResetColor(void) {
    std::string a1;
    char * v1; // r4
    std::string result; // r0
    v1 = a1;
    * a1 = a1 + 2;
    v1[1] = 1;
    result = v1;
    *(u8 * )( * v1 + 1) = 0;
    return result;
  }

  std::string operator << (const std::string & left,
    const char * right); {
    return left + right;
  }

  std::string operator << (const std::string & left,
    const std::string & right) {
    return left + right;
  }
}