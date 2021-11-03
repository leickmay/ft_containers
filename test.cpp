#include <iostream>
#include "iterators/RandomAccessIterator.hpp"
#include <vector>
#include "Vector.hpp"


int main()
{
	std::vector<int> array;
	ft::vector<int> myarray;
	std::vector<int> r;

	r.reserve(5);
	std::cout << "r size - capacity : " << r.size() << " " << r.capacity() << std::endl;


	std::cout << "empty test : " << myarray.empty() << " -- " << array.empty() << std::endl;

	array.push_back(20);
	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	array.push_back(4);
	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	array.push_back(6);
	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	array.push_back(8);
	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	array.insert(array.begin(), 10);
	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;

	myarray.push_back(20);
		std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.push_back(4);
		std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.push_back(6);
		std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.push_back(8);
		std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
		std::cout << "myarray before : " << std::endl;
	for (ft::vector<int>::iterator i = myarray.begin(); i != myarray.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	myarray.insert(myarray.begin(), 10);
	std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
		std::cout << "myarray after insert : " << std::endl;
	for (ft::vector<int>::iterator i = myarray.begin(); i != myarray.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	std::vector<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);


std::cout << "empty test : " << myarray.empty() << " -- " << array.empty() << std::endl;

	std::cout << "pop back" << std::endl;
	std::cout << "array before : " << std::endl;
	for (std::vector<int>::iterator i = array.begin(); i != array.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	array.pop_back();
	std::cout << "array after : " << std::endl;
	for (std::vector<int>::iterator i = array.begin(); i != array.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	std::cout << "myarray before : " << std::endl;
	for (ft::vector<int>::iterator i = myarray.begin(); i != myarray.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	myarray.pop_back();
	std::cout << "myarray after : " << std::endl;
	for (ft::vector<int>::iterator i = myarray.begin(); i != myarray.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;


	std::vector<int>::iterator it;
	std::vector<int>::iterator itt;

	it = array.begin();
	itt = it + 1;
	itt++;
	std::cout << *it + 1 << std::endl;

	ft::vector<int>::iterator it2;
	ft::vector<int>::iterator itt2;

	it2 = myarray.begin();
	itt2 = it2 + 1;
	itt2++;
	//ittt = itt - it;
	std::cout << *it2 + 1 << std::endl;

 // typedef ft::vector<const int*>::iterator traits;
  //if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
   // std::cout << "int* is a random-access iterator";

	std::cout << "rend " << *myarray.rend() <<  "    -    " << *array.rend() << std::endl;
	std::cout << "[] operator " << myarray[2] <<  "    -    " << array[2] << std::endl;
	std::cout << "at : " << myarray.at(2) <<   "    -    " << array[2]  << std::endl;
	std::cout << " at exceptions : " << std::endl;
	try
	{
		std::cout <<  " " << myarray.at(9)  << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout <<  " " << array.at(9)  << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "front : " << myarray.front() << " - " << array.front() << std::endl;
	std::cout << "end : " << myarray.back() << " - " << array.back() << std::endl;

	std::cout << "assign iterators : " << std::endl;
	std::cout << "array before : " << std::endl;
	for (std::vector<int>::iterator i = array.begin(); i != array.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	array.assign(b.begin(), b.end());
	std::cout << "array after : " << std::endl;
	for (std::vector<int>::iterator i = array.begin(); i != array.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	std::cout << "myarray before : " << std::endl;
	for (ft::vector<int>::iterator i = myarray.begin(); i != myarray.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	myarray.assign(b.begin(), b.end());
	std::cout << "myarray after : " << std::endl;
	for (ft::vector<int>::iterator i = myarray.begin(); i != myarray.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;

	std::cout << "assign value : " << std::endl;
	std::cout << "array before : " << std::endl;
	for (std::vector<int>::iterator i = array.begin(); i != array.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	array.assign(2, 42);
	std::cout << "array after : " << std::endl;
	for (std::vector<int>::iterator i = array.begin(); i != array.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	std::cout << "myarray before : " << std::endl;
	for (ft::vector<int>::iterator i = myarray.begin(); i != myarray.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	myarray.assign(2, 42);
	std::cout << "myarray after : " << std::endl;
	for (ft::vector<int>::iterator i = myarray.begin(); i != myarray.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;



	//b = myarray.begin();
	//pouic++;
/*	std::cout << "size before resize : " << array.size() << std::endl;
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
	it3++;*/
	//it3++;
	//it3++;
	//std::cout << "-- " << *it3 << std::endl;

  return 0;
}