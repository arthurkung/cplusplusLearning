#include <tuple>
#include <iostream>

std::tuple<int, double> returnTuple() // return a tuple that contains an int and a double
{
	return { 5, 6.7 };
}

int main()
{
	std::cout << "using std::get to unpack tuples:\n";
	std::tuple s{ returnTuple() }; // get our tuple (C++17)
	std::cout << std::get<0>(s) << ' ' << std::get<1>(s) << '\n'; // std::get<n> to get nth element(C++17)

	// using tie
	std::cout << "using std::tie to unpack tuples:\n";
	int a;
	double b;
	std::tie(a, b) = returnTuple(); // put elements of tuple in variables a and b
	std::cout << a << ' ' << b << '\n';

	// structured binding declaration
	std::cout << "using structured binding declaration to unpack tuples:\n";
	auto [c, d] { returnTuple() }; // used structured binding declaration to put results of tuple in variables a and b
	std::cout << c << ' ' << d << '\n';

	return 0;
}