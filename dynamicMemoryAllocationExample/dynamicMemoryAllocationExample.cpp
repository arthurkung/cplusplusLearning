#include <iostream>
#include <cstddef> // std::size_t

/* memory leak bad example */
void doSomething()
{
    int *ptr{ new int{} };
    // memory allocated but never returned
}


int main()
{
    /* basic allocation */
    int* ptr{ new int };
    *ptr = 7;
    delete ptr; // return the memory pointed to by ptr to the operating system
    ptr = nullptr; // set ptr to be a null pointer


    /* initialization */
    int* ptr1{ new int(5) }; // use direct initialization
    int* ptr2{ new int { 6 } }; // use uniform initialization
    int* otherPtr{ ptr1 }; // otherPtr is now pointed at that same memory location
    delete ptr1;     // ptr1 and otherPtr are now dangling pointers.
    ptr1 = nullptr;  // ptr1 is now a nullptr
    // however, otherPtr is still a dangling pointer!


    /* Operator "new" can fail */
    int *value{ new (std::nothrow) int{} }; // value will be set to a null pointer if the integer allocation fails
    if (!value) // handle nullptr case
    {
        // Do error handling here
        std::cout << "Could not allocate memory";
    }

    /* memory leak solution */
    int value1{ 5 };
    int *ptr3{ new int{} }; // allocate memory
    // ptr = new int{}; // double-allocation loses old address causing memory leak
    delete ptr3; // return memory before reassign
    ptr3 = &value1; // reassign pointer to address of value

    /* dynamic array*/
    {
        std::cout << "Enter a positive integer: ";
        std::size_t length{};
        std::cin >> length;

        int* array{ new int[length] {} }; // use array new.  Note that length does not need to be constant!

        /*We could also have done:
        * int length{};
        * std::cin >> length;
        * int *array{ new int[static_cast<std::size_t>(length)]{} };
        */

        std::cout << "I just allocated an array of integers of length " << length << '\n';

        array[0] = 5; // set element 0 to value 5

        delete[] array; // use array delete to deallocate array

        // we don't need to set array to nullptr/0 here because it's going to go out of scope immediately after this anyway

    }

    int* array1{ new int[5]{ 9, 7, 5, 3, 1 } }; // initialize a dynamic array since C++11
    // To prevent writing the type twice, we can use auto. This is often done for types with long names.
    auto* array2{ new int[5]{ 9, 7, 5, 3, 1 } };

}

