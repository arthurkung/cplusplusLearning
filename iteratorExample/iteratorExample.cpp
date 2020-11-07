#include <array>
#include <iostream>
void printBeginToEnd()
{

}
int main()
{
    std::array myArray{ 0, 1, 2, 3, 4, 5, 6 };

    //pointer as iterator
    {
        auto begin{ &myArray[0] };
        // note that this points to one spot beyond the last element
        auto end{ begin + std::size(myArray) };
        //int* end{ myArray.data() + std::size(myArray) };// we could also do this

        std::cout << typeid(begin).name() << "\n";
        std::cout << typeid(end).name() << "\n";

        // for-loop with pointer
        for (auto ptr{ begin }; ptr != end; ++ptr) // ++ to move to next element
        {
            std::cout << *ptr << ' '; // dereference to get value of current element
        }
        std::cout << '\n';
    }
    //myArray.begin
    {
        // Ask our array for the begin and end points (via the begin and end member functions).
        auto begin{ myArray.begin() };
        auto end{ myArray.end() };
        std::cout << typeid(begin).name() << "\n";
        std::cout << typeid(end).name()<<"\n";

        for (auto p{ begin }; p != end; ++p) // ++ to move to next element.
        {
            std::cout << *p << ' '; // dereference to get value of current element.
        }
        std::cout << '\n';
    }
    //std::begin(myArray)
    {
        auto begin{ std::begin(myArray) };
        auto end{ std::end(myArray) };
        std::cout << typeid(begin).name() << "\n";
        std::cout << typeid(end).name() << "\n";

        for (auto p{ begin }; p != end; ++p) // ++ to move to next element
        {
            std::cout << *p << ' '; // dereference to get value of current element
        }
        std::cout << '\n';
    }
    //range-based for loops
    {
        for (int i : myArray)
        {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}
