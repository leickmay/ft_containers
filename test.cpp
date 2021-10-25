#include <iostream>
#include "iterators/RandomAccessIterator.hpp"
#include <vector>
#include "Vector.hpp"
int main()
{
	std::vector<int> array;
	ft::vector<int> myarray;
	myarray.push_back(42);
	myarray.push_back(84);
	array.push_back(5);
	array.push_back(4);

	int test[3];
	test[0] = 0;
	test[1] = 1;
	test[2] = 2;

	ft::RandomAccessIterator<int> pouic(test);
	//pouic++;
	std::cout << *pouic << std::endl;
}