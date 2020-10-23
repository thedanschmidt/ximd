#include <iostream>
#include <string>
#include <string.h>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ximd_ascii.hpp"

namespace ximd {

TEST_CASE("to lower 64 correctness", "[ascii]") {
  const char* test = "a ShOrt StrinG of AscII";
  const char* tres = "a short string of ascii";

  char buff[256];
  strcpy(buff, test);
  to_lower_64(buff);
  std::cout << buff << std::endl;
  REQUIRE(strcmp(tres, buff) == 0);
}

}
