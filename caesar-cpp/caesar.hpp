#pragma once

#include <string>

namespace Caesar::details {
  int absolute_int(int x);
}
namespace Caesar {

  // Ciphers a buffer with a right shift specified by the user
  std::string encrypt(const std::string & str, int offset);
  
  // Deciphers a buffer with a left shift specified by the user
  std::string decrypt(const std::string & str, int offset);
}

