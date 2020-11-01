#include <iostream>
#include <iterator>
#include <typeinfo>

void arrayFunc(int array[8])// actually same as: int *array
{
    std::cout << "the type is: " << typeid(array).name() << '\n';
    //std::cout << std::size(array) << '\n'; // Error
    std::cout << "wrong size: " << sizeof(array) / sizeof(array[0]) << "\n"; // does not count properly

}
enum StudentNames
{
    kenny, // 0
    kyle, // 1
    stan, // 2
    butters, // 3
    cartman, // 4 --add new students here and max_students will adjust itself
    max_students // 5
};

int main()
{
    struct Rectangle
    {
        int length{};
        int width{};
    };
    Rectangle rects[5]{}; // declare an array of 5 Rectangle

    rects[0].length = 24; //accessing elements

    // using a symbolic constant
    constexpr int arrayLength{ 5 };
    int array1[arrayLength]{}; // not allowed if not a compile-time const

    std::cout << "accessing elements with subscript is the same as pointer: " << (array1[3] == *(array1+3)) << '\n';

    
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };// compiler will detect the length of array
    std::cout << "The array has: " << std::size(array) << " elements (std::size)\n";
    std::cout << "The array has: " << sizeof(array) / sizeof(array[0]) << " elements (sizeof)\n";
    arrayFunc(array);

    /*enum example*/
    int testScores[max_students]{}; // allocate array with max_student length
    testScores[stan] = 76;

    /*Multi Dimension*/
    int multArray1[3][5]
    {
      { 1, 2 }, // row 0 = 1, 2, 0, 0, 0
      { 6, 7, 8 }, // row 1 = 6, 7, 8, 0, 0
      { 11, 12, 13, 14 } // row 2 = 11, 12, 13, 14, 0
    };
    int multArray2[][5]//can omit (only) the leftmost length specification
    {
      { 1, 2, 3, 4, 5 },
      { 6, 7, 8, 9, 10 },
      { 11, 12, 13, 14, 15 }
    };
    std::cout <<"row 1, col 3: "<< multArray2[1][3] << '\n'; 

    return 0;
}