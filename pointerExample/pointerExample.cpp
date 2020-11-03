#include <iostream>
#include <iterator> // for std::size, std::begin and std::end
#include <algorithm>// for std::count_if

int* doSomething(int *x) //asterisk next to return type for function
{
    if (!x)
        std::cout << "print(int*): nullptr\n";         // for null pointers
    else
    {
        std::cout << "print(int*): " << *x << '\n'; // print value stored
        *x = 100;   // this will change the value (not only in function scope)
    }

    return x;
}
bool isT(char ch)
{
    if (ch == 't')
        return true;
    
    return false;
}

int main()
{
    int x{ 5 };
    // memory address of variable x
    std::cout << "address is: "<< &x << '\n'; 
    // value at the memory address of variable x (parenthesis not required, but make it easier to read)
    std::cout << "value is: " << *(&x) << '\n'; 
    // type
    std::cout << "the data type of the addess: "<<typeid(&x).name() << '\n';


    //init a pointer
    int *xPtr1{ nullptr }; //put asterisk next to pointer variable name
    xPtr1 = &x;
    int* xPtr2{ &x }; //put asterisk next to pointer variable name

    // double* dPtr{ 0x0012FF7C }; // cannot convert literal memory addresses to pointer

    //they access the same memory
    *xPtr1 = 7; // *xPtr1 is the same as value, assigned 7
    std::cout << "value of x is: " << *xPtr2 << '\n'; // accessing the same address


    struct Something
    {
        int x{};
        int y{};
        int z{};
    };

    Something* somethingPtr{}; // Something is probably 12 bytes

    std::cout << "size of pointer is: "<<sizeof(somethingPtr) << '\n'; // the sise of the pointer is 4

    // null pointers
    int* ptr{ nullptr };
    ptr = doSomething(nullptr);     // nullptr makes sure that a ptr is interpreted

    // arrays
    int array[5]{ 9, 7, 5, 3, 1 };

    // print address of the array's first element
    std::cout << "Element 0 has address: " << &array[0] << '\n';

    // print the value of the pointer the array decays to
    std::cout << "The array decays to a pointer holding address: " << array << '\n';

    std::cout << "the data type of the array: " << typeid(array).name() << '\n'; // not int *
    //sizes
    std::cout << "the size of the array: " << sizeof(array) << '\n'; // will print sizeof(int) * array length
    std::cout << "the size of the address: "<<sizeof(&array[0]) << '\n'; // the address is again only size 4

    // passing arrays to functions will have the changes take effect
    doSomething(array);
    std::cout << "Element 0 is now: " << array[0] << '\n';

    // address of the elements of array
    std::cout << "Address of array[2]: " << &array[2] << '\n';
    std::cout << "Can also be accessed by + : " << array + 2 << '\n';

    // use pointer to iterate an array
    char word[]{ "substitution" };
    int arrayLength{ static_cast<int>(std::size(word)) };
    int numT{ 0 };

    for (char* ptr{ word }; ptr < (word + arrayLength); ++ptr)
    {
        if (isT(*ptr))
        {
            ++numT;
        }
    }

    std::cout << "the word "<< word << " has " << numT << " t(s).\n";

    // or we can use count_if
    auto numT2{ std::count_if(std::begin(word), std::end(word), isT) };
    std::cout << "the word " << word << " has " << numT2 << " t(s). Using count_if\n";

    // pointer and const
    int value1 = 5;
    const int* ptr1 = &value1; // ptr points to a "const int"
    value1 = 6; // the value is non-const when accessed through a non-const identifier
    // *ptr = 6; // ptr treats its value as const, so changing the value through ptr is not legal

    int value2 = 6;
    ptr1 = &value2; // okay, ptr now points at some other const int

    // const pointer
    int value = 5;
    int* const ptr2 = &value;    // a const pointer: const between type and pointer name
    *ptr2 = 6; // allowed, since ptr points to a non-const int
    // ptr2 = &value2; // not okay, once initialized, a const pointer can not be changed.


    return 0;
}