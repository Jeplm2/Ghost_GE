#pragma once
#include <Ghost/Core.h>


#define LOG(x) { std::cout << x << std::endl; }
#define NLOG(x, y) { if(!x) std::cout << y << std::endl; }