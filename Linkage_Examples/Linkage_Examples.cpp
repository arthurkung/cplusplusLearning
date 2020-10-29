#include<iostream>

/********************
Internal linkage
*********************/

// Internal global variables definitions:
static int g_x_i;          // defines non-initialized internal global variable (zero initialized by default)
//static int g_x{ 1 };     // defines initialized internal global variable

const int g_y_i{ 2 };     // defines initialized internal global const variable
//constexpr int g_y{ 3 }; // defines initialized internal global constexpr variable

// Internal function definitions:
static int add(int x, int y) {
	return x+y;
};     // defines internal function


/********************
External linkage
*********************/

extern int g_x_ex; // this extern is a forward declaration of a variable named g_x that is defined somewhere else
extern const int g_y_ex; // this extern is a forward declaration of a const variable named g_y that is defined somewhere else
int addOne(int x); // forward declaration for function addOne, makes addOne accessible in this file

int main()
{
	//Internal linkage
	g_x_i = 1;
	std::cout << "g_x_i: " << g_x_i << "\n";
	std::cout << "g_y_i: " << g_y_i << "\n";
	std::cout << "func add with internal linkage: "<<add(g_x_i,g_y_i) << "\n"; //this uses the add definition in this file

	//External linkage
	std::cout << "g_x_ex: " << g_x_ex << "\n";
	std::cout << "g_y_ex: " << g_y_ex << "\n";
	g_x_ex = addOne(g_x_ex);
	std::cout << "g_x_ex after external linkage func addOne: " << g_x_ex << "\n";

	

	return 0;
}
