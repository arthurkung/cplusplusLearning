#include <iostream>
#include <vector>
int factorial(int num)
{
	if (num < 1)
		return 1;
	else
		return factorial(num - 1) * num;
}
void printBinary(int num)
{
	static std::vector<bool> results{ };
	if (num>0)
	{
		results.push_back(num % 2);
		printBinary(num / 2);
		std::cout << results.back();
		results.pop_back();
	}
}
void printBinary2(unsigned int n)
{
	if (n > 1) // we only recurse if n > 1, so this is our termination case for n == 0
	{
		printBinary(n / 2);
	}

	std::cout << n % 2;
}


// h/t to potterman28wxcv for a variant of this code
int fibonacci(int count)
{
	// We'll use a static std::vector to cache calculated results
	static std::vector<int> results{ 0, 1 };

	// If we've already seen this count, then use the cache'd result
	if (count < static_cast<int>(std::size(results)))
		return results[count];
	else
	{
		// Otherwise calculate the new result and add it
		results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
		return results[count];
	}
}

int main()
{
	std::cout << "fibonacci:\n";
	for (int count = 0; count < 13; ++count)
		std::cout << fibonacci(count) << " ";
	std::cout << "\n";

	std::cout << "factorial:\n";
	for (int count = 0; count < 5; ++count)
		std::cout << factorial(count) << " ";
	std::cout << "\n";

	std::cout << "binary:\n";
	for (int count = 9; count !=-2 ; --count)
	{
		printBinary(count);
		std::cout << "\n";
		printBinary2(static_cast<unsigned int>(count));
		std::cout << "\n";
	}

}
