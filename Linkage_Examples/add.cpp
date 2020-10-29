#include<iostream>

/********************
Internal linkage
*********************/
constexpr int g_x_i{ 2 }; // this internal g_x is only accessible within add.cpp


// This function is declared as static, and can now be used only within this file
// Attempts to access it from another file via a function forward declaration will fail
static int add(int x, int y)
{
    return 0;
}

/********************
External linkage
*********************/

// global variable definitions
int g_x_ex{ 2 }; // non-constant globals have external linkage by default
extern const int g_y_ex{ 3 }; // this extern gives g_y external linkage


int addOne(int x) // this function has external linkage, and can be seen by other files
{
    return x + 1;
}