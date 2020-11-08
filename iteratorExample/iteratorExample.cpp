#include <array>
#include <algorithm> //for count_if
#include <iostream>
void pointerAsIterator(const std::array<int, 7>& myArray)
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
void arrayBegin(const std::array<int, 7>& myArray)
{
    // Ask our array for the begin and end points (via the begin and end member functions).
    auto begin{ myArray.begin() };
    auto end{ myArray.end() };
    std::cout << typeid(begin).name() << "\n";
    std::cout << typeid(end).name() << "\n";

    for (auto p{ begin }; p != end; ++p) // ++ to move to next element.
    {
        std::cout << *p << ' '; // dereference to get value of current element.
    }
    std::cout << '\n';
}
void stdBegin(const std::array<int, 7>& myArray)
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
void printWithRangeBasedForLoop(const std::array<int, 7>& myArray)
{
    for (int i : myArray)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}
void stdFindAndReplace(std::array<int, 7>& myArray, const int search, const int replace)
{
    // std::find returns an iterator pointing to the found element (or the end of the container)
    // we'll store it in a variable, using type inference to deduce the type of
    // the iterator (since we don't care)
    auto found{ std::find(myArray.begin(), myArray.end(), search) };

    // Algorithms that don't find what they were looking for return the end iterator.
    // We can access it by using the end() member function.
    if (found == myArray.end())
    {
        std::cout << "Could not find " << search << '\n';
    }
    else
    {
        // Override the found element.
        *found = replace;
    }
}
bool isGreaterThan8(const int num)
{
    return num > 8;
}

void stdFindIfGreaterThan8(const std::array<int, 7>& myArray)
{
    auto found{ std::find_if(myArray.begin(), myArray.end(), isGreaterThan8) };

    if (found == myArray.end())
    {
        std::cout << "No number greater than 8\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

}
void countNumGreaterThan8(const std::array<int, 7>& myArray)
{
    auto numGreaterThan8{ std::count_if(myArray.begin(), myArray.end(), isGreaterThan8) };

    std::cout << "Counted " << numGreaterThan8 << " number(s) greater than 8\n";
}
bool isGreater(const int a, const int b)
{
    return (a > b);
}
void sortDesc(std::array<int, 7>& myArray)
{
    std::sort(myArray.begin(), myArray.end(), isGreater);
    //std::sort(myArray.begin(), myArray.end(), std::greater{}); // use the standard library greater comparison
    //std::sort(myArray.begin(), myArray.end(), std::greater<int>{});//element type required before C++17
}
void tripleNumber(int &num) {
    num *= 3;
}

void tripleArray(std::array<int, 7>& myArray)
{
    std::for_each(myArray.begin(), myArray.end(), tripleNumber);
    //std::for_each(std::next(myArray.begin()), myArray.end(), tripleNumber); //to skip the first number

}
int main()
{
    std::array myArray{ 0, 1, 2, 3, 4, 5, 6 };

    //pointer as iterator
    pointerAsIterator(myArray);

    //myArray.begin
    arrayBegin(myArray);

    //std::begin(myArray)
    stdBegin(myArray);

    //range-based for loops
    printWithRangeBasedForLoop(myArray);
    
    //std::find
    stdFindAndReplace(myArray, 1, 10);
    printWithRangeBasedForLoop(myArray);

    //std::find_if
    stdFindIfGreaterThan8(myArray);

    //std::count_if
    countNumGreaterThan8(myArray);

    //std::sort
    sortDesc(myArray);
    printWithRangeBasedForLoop(myArray);

    //std::for_each
    tripleArray(myArray);
    printWithRangeBasedForLoop(myArray);


}
