#ifndef MATH_H
#define MATH_H

// define your own namespace to hold constants
namespace math
{
    inline constexpr double pi{ 3.14159 };  // remove inline for prior C++20
    int add(int x, int y);
    extern const double gravity;  // using external variables method (definition in math.cpp)
    
}
#endif
