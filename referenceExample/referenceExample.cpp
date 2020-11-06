#include <iostream>
#include <string>
// ref is a reference to the argument passed in, not a copy
void changeN(int &ref)
{
    ref = 6;
}
void printIt(const int &x)
{
    std::cout << x << '\n';
    //x = 1; //illegal, x is a const
}

// Note: You need to specify the array size in the function declaration
void printElements(int (&arr)[4])
{
    int length{ static_cast<int>(std::size(arr)) }; // we can now do this since the array won't decay

    for (int i{ 0 }; i < length; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}
void studyBasics()
{
    int value{ 5 }; // normal integer
    int& ref{ value }; // reference to variable value

    // int &invalidRef; // invalid, reference must be initialised

    value = 6; // value is now 6
    ref = 7; // value is now 7

    std::cout << value << '\n'; // prints 7
    ++ref;
    std::cout << value << '\n'; // prints 8

    std::cout << &value << '\n'; // prints 0012FF7C
    std::cout << &ref << '\n'; // prints 0012FF7C

    int value2{ 6 };

    ref = value2; // assigns 6 (the value of value2) to value -- does NOT change the reference!

    /*  References to non-const values can only be initialized with non-const l-values
    int x{ 5 };
    int &ref1{ x }; // okay, x is an non-const l-value

    const int y{ 7 };
    int &ref2{ y }; // not okay, y is a const l-value

    int &ref3{ 6 }; // not okay, 6 is an r-value
    */
}
void studyFunctionParam()
{
    std::cout << "references as function parameters\n";
    int n{ 5 };

    std::cout << "before applied to function, value of n is: " << n << '\n';

    changeN(n); // note that this argument does not need to be a reference

    std::cout << "after applied to function, value of n is: " << n << '\n';

}

void studyArray()
{
    std::cout << "Using references to print elements of an array\n";

    int arr[]{ 99, 20, 14, 80 };

    printElements(arr);
}

void studyShortcut()
{
    struct Something
    {
        int value1;
        float value2;
    };

    struct Other
    {
        Something something;
        int otherValue;
    };

    Other other;
    int& ref_as_shortcut{ other.something.value1 };
    ref_as_shortcut = 5; // identical to other.something.value1 = 5;

}

void studyPointers()
{
    int value{ 5 };
    int& ref{ value };
    int* const ptr{ &value }; //const because ref does not change reference

    ref = 5; // same as *ptr = 5;
}
void studyConstRefBasics()
{
    int x{ 5 };
    const int& ref1{ x }; // okay, x is a non-const l-value

    const int y{ 7 };
    const int& ref2{ y }; // okay, y is a const l-value

    const int& ref3{ 6 }; // okay, 6 is an r-value

    int value{ 5 };
    const int& ref{ value }; // create const reference to variable value

    value = 6; // okay, value is non-const
    //ref = 7; // illegal -- ref is const
}
void studyConstRefExtendLifetime()
{
    std::cout << "extend lifetime of r-values\n";
    const int& ref{ 2 + 3 }; // normally the result of 2+3 has expression scope and is destroyed at the end of this statement
    // but because the result is now bound to a reference to a const value...
    std::cout << ref << '\n'; // we can use it here
} // and the lifetime of the r-value is extended to here, when the const reference dies

void studyConstRefFuncParam()
{
    std::cout << "a is a non-const l-value\n";
    int a{ 1 };
    printIt(a); // non-const l-value

    std::cout << "b is a const l-value\n";
    const int b{ 2 };
    printIt(b); // const l-value

    std::cout << "3 is a literal r-value\n";
    printIt(3); // literal r-value

    std::cout << "2+b is a experession r-value\n";
    printIt(2 + b); // expression r-value
}
int main()
{
    studyBasics();

    // Function param
    studyFunctionParam();

    // pass arrays to functions as reference for performance
    studyArray();

    // reference as shortcut
    studyShortcut();

    // reference vs pointers
    studyPointers();

    studyConstRefBasics();

    studyConstRefExtendLifetime();

    studyConstRefFuncParam();

    return 0;
}