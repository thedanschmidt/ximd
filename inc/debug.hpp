#pragma once
#include <iostream>
#include <iomanip>

#define LOG_HEX(x) std::cout << std::setw(16) << std::setfill('0') << std::hex << x << std::endl
