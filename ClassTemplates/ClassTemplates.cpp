//https://www.hackerrank.com/challenges/c-class-templates/problem
template <class T>
class AddElements {
    T element;
public:
    AddElements(T arg) { element = arg; }
    T add(T arg) { return element+arg; }
};
#include <iostream>

int main()
{
    AddElements<double> myfloat(1.5);
    std::cout << myfloat.add(2.3) << "\n";


    AddElements<int> myint(1);
    std::cout << myint.add(2) << "\n";
    
    AddElements<std::string> mystr("happy ");
    std::cout << mystr.add("birthday") << "\n";

}
