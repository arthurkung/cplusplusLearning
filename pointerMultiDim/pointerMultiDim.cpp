#include <iostream>
int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
	return (row * numberOfColumnsInArray) + col;
}
void createDynArrayCompileTimeConst_width5(int arraySize)
{
	// doesn’t work if any non-leftmost array dimension isn’t a compile-time constant
	int(*array1)[5] = new int[arraySize][5]; // If the rightmost array dimension is a compile-time constant
	auto array2 = new int[arraySize][5]; // so much simpler in C++11

	// deallocate
	delete[] array1;
	delete[] array2;

}
void createDynArrayNonCompileTimeConst(int dim1, int dim2)
{
	int **array = new int* [dim1]; // allocate an array of 10 int pointers — these are our rows
	for (int count = 0; count < dim1; ++count)
		array[count] = new int[dim2]; // these are our columns

	//Deallocating a dynamically allocated two-dimensional array
	for (int count = 0; count < dim1; ++count)
		delete[] array[count];
	delete[] array; // this needs to be done last
}

void createTriArrayNonCompileTimeConst(int size)
{
	int **array = new int* [size]; // allocate an array of 10 int pointers — these are our rows
	for (int count = 0; count < size; ++count)
		array[count] = new int[count + 1]; // these are our columns

	//Deallocating same as above
	for (int count = 0; count < size; ++count)
		delete[] array[count];
	delete[] array; 
}
int main()
{
	// pointer of pointer
	{
		int value = 5;

		int* ptr = &value;
		std::cout << *ptr; // dereference pointer to int to get int value

		int** ptrptr = &ptr;
		std::cout << **ptrptr; // first dereference to get pointer to int, second dereference to get int value
		//int **ptrptr = &&value; // not valid because &value is a r-value
	}
	// nullptr
	{
		int** ptrptr2 = nullptr; // use 0 instead prior to C++11
	}
	
	// int **array = new int[10][5]; // won’t work!

	// You can create a rectangular array with fixed width
	createDynArrayCompileTimeConst_width5(10);

	// non compile time constant rectangular
	createDynArrayNonCompileTimeConst(10,5);

	// triangle array
	createTriArrayNonCompileTimeConst(10);

	//flatten
	{
		int* array = new int[50]; // a 10x5 array flattened into a single array
		array[getSingleIndex(9, 4, 5)] = 3;
	}

}
