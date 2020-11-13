#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <functional> //for std::function
#include <cmath> //for std::abs
void basicStringViewLambda() {
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // Define the function right where we use it.
    const auto found{ std::find_if(arr.begin(), arr.end(),
                             [](std::string_view str) // here's our lambda, no capture clause
                             {
                               return (str.find("nut") != std::string_view::npos);
                             }) };

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }
}
void apply1ToN(int repetitions, const std::function<void(int)>& fn)
{
    for (int i{ 0 }; i < repetitions; ++i)
    {
        fn(i);
    }
}
void passLambdaToFunc()
{
    std::cout << "print 1 to 3:\n";
    apply1ToN(3, [](int i) {
        std::cout << i;
        });
    std::cout << "\n";

    std::cout << "print even numbers from 1 to 7:\n";
    auto printIfEven{
        [](int i)
        {
        if ((i % 2) == 0)
            std::cout << i;
        }
    };
    apply1ToN(7, printIfEven);
}
void useGenericLambda() {
    constexpr std::array months{ // pre-C++17 use std::array<const char*, 12>
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
    };
    // Search for two consecutive months that start with the same letter.
    const auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
                                        [](const auto& a, const auto& b) {  // use of auto here
                                          return (a[0] == b[0]);
                                        }) };

    if (sameLetter != months.end())// Make sure that two months were found.
    {
        std::cout << *sameLetter << " and " << *std::next(sameLetter)
            << " start with the same letter\n";
    }
}
// note: explicitly specifying this returns a double in a lambda function
auto divide{ [](int x, int y, bool bInteger) -> double {
  if (bInteger)
    return x / y; // will do an implicit conversion to double
  else
    return static_cast<double>(x) / y;
} };
void maxElementExample()
{
    struct Student
    {
        std::string name{};
        int score{};
    };
     
    std::array<Student, 8> arr
    {
        {   { "Albert", 3 },
            { "Ben", 5 },
            { "Christine", 2 },
            { "Dan", 8 }, // Dan has the most points (8).
            { "Enchilada", 4 },
            { "Francis", 1 },
            { "Greg", 3 },
            { "Hagrid", 5 } 
        }
    };
    const auto bestStudent{
        std::max_element(arr.begin(),arr.end(),[](const Student& a, const Student& b)
        {  
            return (a.score < b.score);
        })
    };
    std::cout << typeid(bestStudent).name() << "\n";
    std::cout << bestStudent->name << " is the best student\n";

}
void mutableCapture()
{
    int ammo{ 10 };

    auto shoot{
        // Added mutable after the parameter list.
        [ammo]() mutable {
        //[=]() mutable {//we could also use default capture
            // We're allowed to modify ammo now
            --ammo;

            std::cout << "Pew! " << ammo << " shot(s) left.\n";
          }
    };

    shoot();
    shoot();

    std::cout << ammo << " shot(s) left\n";
}

void referenceCapture()
{
    int ammo{ 10 };

    auto shoot{
        [&ammo](){// &ammo means ammo is captured by reference
        //[&](){    //we could also use default capture
            --ammo;

            std::cout << "Pew! " << ammo << " shot(s) left.\n";
          }
    };

    shoot();
    shoot();

    std::cout << ammo << " shot(s) left\n";
}
void squareNumGame(int randNum)
{
    int start{};
    int count{};

    std::cout << "Start where? ";
    std::cin >> start;

    std::cout << "How many? ";
    std::cin >> count;

    std::vector<int> results(count);
    for (int i{}; i < count; ++i)
        results[i] = randNum * (start + i) * (start + i);

    std::cout << "I generated "<<count<<" square numbers. Do you know what each number is after multiplying it by " << randNum << "?";
    while (std::size(results))
    {
        int guess{};
        std::cin >> guess;
        auto closest{ std::min_element(results.begin(),results.end(),[guess](int x, int y) {
            return std::abs(x - guess) < std::abs(y - guess);
            }
            ) };
        std::cout << "the closest answer is: " << *closest << "\n";
        std::cout <<  *closest << " is now removed from the list" << "\n";
        results.erase(closest);
    }

}
int main()
{
    basicStringViewLambda();
    passLambdaToFunc();
    useGenericLambda();
    maxElementExample();
    // lambda captures
    mutableCapture();
    referenceCapture();
    
    std::cout << "square number game\n";
    squareNumGame(4);


    return 0;
}