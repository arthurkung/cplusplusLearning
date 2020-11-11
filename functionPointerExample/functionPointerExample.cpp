#include <utility> // for std::swap
#include <iostream>
#include <functional> // for std::function

int foo()
{
    return 5;
}

int goo()
{
    return 6;
}
double hoo(int x)
{
    return 7;
}

// Note our user-defined comparison is the third parameter
void selectionSort(int* array, int size, bool (*comparisonFcn)(int, int))
{
    for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
    {
        int bestIndex{ startIndex };

        for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
        {
            if (comparisonFcn(array[bestIndex], array[currentIndex])) 
            {
                bestIndex = currentIndex;
            }
        }

        // Swap our start element with our smallest/largest element
        std::swap(array[startIndex], array[bestIndex]);
    }
}
bool descending(int x, int y)
{
    return x < y;
}
int main()
{

    {
        int (*fcnPtr)() { &foo };   // fcnPtr points to function foo
        //std::function<int()> fcnPtr{ &foo }; //same as above
        fcnPtr = &goo;              // can point to another function
        //auto fcnPtr{ &foo };      // this works too
    }
    {
        double (*fcnPtr)(int) { &hoo };

        // explicit dereference
        (*fcnPtr)(5); // call function hoo(5).

        // implicit dereference
        fcnPtr(5);
    }
    // usage of function pointer
    {
        int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };

        selectionSort(array, 9, descending);
        for (int i : array)
            std::cout << i;

    }
    // using type alias to make function pointers prettier
    {
        using validateFcn = bool(*)(int, int);
        //using validateFcn = std::function<bool(int, int)>; // same as above
        bool validate(int x, int y, validateFcn pfcn);
    }
    // or use std::function as alternative
    {
        bool validate(int x, int y, std::function<bool(int, int)> fcn);
    }

    return 0;
}