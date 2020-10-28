#include "math.h"
#include <iostream>

int main()
{   
    std::cout << "Please insert a number\n";
    int x;
    std::cin >> x;
    std::cout << "Please insert another number\n";
    int y;
    std::cin >> y;
    std::cout << x << " plus " << y << " is " << math::add(x, y)<<"\n";
    std::cout << "value of pi is: " << math::pi << "\n";

}

