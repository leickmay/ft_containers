#include <iostream>
#include "iterators/RandomAccessIterator.hpp"
#include <vector>
#include "Vector.hpp"
int main()
{
	std::vector<int> array;
	ft::vector<int> myarray;
	//myarray.push_back(42);
	//myarray.push_back(84);
	array.push_back(2);
	array.push_back(4);

	int test[3];
	test[0] = 42;
	test[1] = 1;
	test[2] = 2;

	ft::RandomAccessIterator<int> pouic(test);
	std::vector<int>::iterator it;
	ft::vector<int>::iterator b;
	//b = myarray.begin();
	//pouic++;
	std::cout << "size before resize : " << array.size() << std::endl;
	std::cout << "capacity : " << array.capacity() << std::endl;
	for (it = array.begin(); it != array.end(); it++)
		std::cout << "-- " << *it << std::endl;
	array.resize(10, 10);
	std::cout << "size after resize : " << array.size() << std::endl;
	std::cout << "capacity : " << array.capacity() << std::endl;
	for (it = array.begin(); it != array.end(); it++)
		std::cout << "-- " << *it << std::endl;
	array.resize(5, 5);
	std::cout << "size after resize : " << array.size() << std::endl;
	std::cout << "capacity : " << array.capacity() << std::endl;
	for (it = array.begin(); it != array.end(); it++)
		std::cout << "-- " << *it << std::endl;
		array.resize(7, 42);
	std::cout << "size after resize : " << array.size() << std::endl;
	std::cout << "capacity : " << array.capacity() << std::endl;
	for (it = array.begin(); it != array.end(); it++)
		std::cout << "-- " << *it << std::endl;

	ft::vector<int>::iterator it2;
	myarray.push_back(5);
	myarray.push_back(6);
	myarray.reserve(10);
	std::cout << "my array after resize : " << myarray.size() << std::endl;
	std::cout << "capacity : " << myarray.capacity() << std::endl;
	it2 = myarray.begin();
	for (int i = 0; i < myarray.size(); i++)
	{
		std::cout << i <<  " -- " << *it2 << std::endl;
		it2++;
	}
	for (ft::vector<int>::iterator pouic = myarray.begin(); pouic != myarray.end(); pouic++)
		std::cout << " - " << *pouic << std::endl;
	ft::vector<int>::iterator it3 = myarray.begin();
	it3++;
	//it3++;
	//it3++;
	//std::cout << "-- " << *it3 << std::endl;
  return 0;
}