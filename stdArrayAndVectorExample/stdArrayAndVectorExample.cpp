#include <array>
#include <vector>
#include <iostream>
#include <algorithm> // for std::sort

void printLength(const std::array<double, 5>& myArray)
{
    std::cout << "The array length: " << myArray.size() << '\n';
}
void printLength(const std::vector<int>& array)
{
    std::cout << "The vector length is: " << array.size() << '\n';
}
void printVector(const std::vector<int>& array)
{
    for (int i : array)
        std::cout << i << ' ';
    std::cout << '\n';
}
int main()
{
    // std::array
    {
        std::array<int, 3> myArray; // declare an integer array with length 3
        myArray[0] = 1;
        myArray.at(1) = 6; // bounds checking included
        std::array<int, 5> myArray1 = { 9, 7, 5, 3, 1 }; // initializer list
        std::array<int, 5> myArray2{ 9, 7, 5, 3, 1 }; // list initialization
    }
    //std::array<int> myArray{ 9, 7, 5, 3, 1 };// illegal, cannot omit length 

    // since C++17, it is allowed to omit the type and size
    {
        std::array myArray1{ 9, 7, 5, 3, 1 }; // The type is deduced to std::array<int, 5>
        std::array myArray2{ 9.7, 7.31 }; // The type is deduced to std::array<double, 2>
    }

    // Since C++20, it is possible to specify the element type but omit the array length.
    {
        auto myArray1{ std::to_array<int, 5>({ 9, 7, 5, 3, 1 }) }; // Specify type and size
        auto myArray2{ std::to_array<int>({ 9, 7, 5, 3, 1 }) }; // Specify type only, deduce size
        auto myArray3{ std::to_array({ 9, 7, 5, 3, 1 }) }; // Deduce type and size

        //std::to_array should be avoided when the array is created many times, eg. in a loop.
    }
    
    //Assignment
    {
        std::array<int, 5> myArray;
        myArray = { 0, 1, 2, 3, 4 }; // okay
        myArray = { 9, 8, 7 }; // okay, elements 3 and 4 are set to zero!
        //myArray = { 0, 1, 2, 3, 4, 5 }; // illegal, too many elements in initializer list!
    }
    // length
    {
        std::array myArray{ 9.0, 7.2, 5.4, 3.6, 1.8 };

        printLength(myArray);
    }
    
    std::array myArray{ 7, 3, 1, 9, 5 };
    //sort
    {
        std::sort(myArray.begin(), myArray.end()); // sort the array forwards
        //  std::sort(myArray.rbegin(), myArray.rend()); // sort the array backwards

        for (int element : myArray)
            std::cout << element << ' ';

        std::cout << '\n';
    }
    //manual indexing
    {
        for (std::size_t i{ 0 }; i < myArray.size(); ++i)
            std::cout << myArray[i] << ' ';
        std::cout << '\n';
    }
    //Array of struct

    struct House
    {
        int number{};
        int stories{};
        int roomsPerStory{};
    };
    // init each member one by one
    {
        std::array<House, 3> houses{};

        houses[0] = { 13, 4, 30 };
        houses[1] = { 14, 3, 10 };
        houses[2] = { 15, 3, 40 };
    }
    // This does not work because it is initialising the element of houses, the underlying array in one go
    /*
    {
        std::array<House, 3> houses{
            { 13, 4, 30 },
            { 14, 3, 10 },
            { 15, 3, 40 }
        };
    }
    */
    // We can initialise like below as braces can be omitted during aggregate initialisation
    {
        std::array<House, 3> houses{
            {
                { 13, 4, 30 },
                { 14, 3, 10 },
                { 15, 3, 40 }
            }
        };
        for (const auto& house : houses)
        {
            std::cout << "House number " << house.number
                << " has " << (house.stories * house.roomsPerStory)
                << " rooms\n";
        }
    }

    /**********************************************************************************/
    // std::vector

    //init
    {
        // no need to specify length at the declaration
        std::vector<int> array;
        array = { 9, 7, 5, 3, 1 };
        array[0] = 1;
        array.at(1) = 2;
        array = { 9, 8, 7 }; // okay, array length is now 3

        std::vector<int> array2 = { 9, 7, 5, 3, 1 }; // use initializer list to initialize array (Before C++11)
        std::vector<int> array3{ 9, 7, 5, 3, 1 }; // use uniform initialization to initialize array

        // as with std::array, the type can be omitted since C++17
        std::vector array4{ 9, 7, 5, 3, 1 }; // deduced to std::vector<int>
    }

    // vector size and resize
    {
        std::vector array{ 9, 7, 5, 3, 1 };
        printLength(array);
        std::cout << "resizing vector to 3\n";
        array.resize(3);
        printVector(array);
        std::cout << "resizing vector to 5\n";
        array.resize(5);
        printVector(array);

    }
    //
    {
        // Using direct initialization, we can create a vector with 5 elements,
        // each element is a 0. If we use brace initialization, the vector would
        // have 1 element, a 5.
        std::cout << "creating a empty vector length 5\n";
        std::vector<int> array(5);

        printLength(array);
        printVector(array);

    }

    return 0;
}