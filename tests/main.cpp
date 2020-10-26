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

  size_t len = strlen(test);

  char buff[256];
  strcpy(buff, test);
  to_lower_64(buff, len);
  std::cout << buff << std::endl;
  REQUIRE(strcmp(tres, buff) == 0);
}

TEST_CASE("to lower 128 correctness", "[ascii]") {
  const char* test = "a ShOrt StrinG of AscII";
  const char* tres = "a short string of ascii";

  size_t len = strlen(test);

  char buff[256];
  strcpy(buff, test);
  to_lower_128(buff, len);
  std::cout << buff << std::endl;
  REQUIRE(strcmp(tres, buff) == 0);
}

}
