#include "containers/Vector.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "=== Constructors ===" << std::endl;

	ft::vector<std::string> v1;
	ft::vector<std::string> v2(5, "test");

	std::cout << "v2 :" << std::endl;
	for (ft::vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
		std::cout << *it << std::endl;

	ft::vector<std::string> v3(v2.begin() + 1, v2.end() - 1);
	std::cout << "v3 :" << std::endl;
	for (ft::vector<std::string>::iterator it = v3.begin(); it != v3.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size - capacity : " << v3.size() << " " << v3.capacity() << std::endl;

	ft::vector<std::string> copy(v3);
	std::cout << "v3 copy : " << std::endl;
	for (ft::vector<std::string>::iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size - capacity : " << copy.size() << " " << copy.capacity() << std::endl;

	v1 = v3;
	std::cout << "v3 assignation : " << std::endl;
	for (ft::vector<std::string>::iterator it = v1.begin(); it != v1.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size - capacity : " << v1.size() << " " << v1.capacity() << std::endl;

	std::cout << std::endl << "=== Iterators ===" << std::endl;
	ft::vector<int> vec;
	for (int i = 1; i <= 10; i++)
		vec.push_back(i);
	std::cout << "new vector : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "begin : " << *vec.begin() << " - end : " << *vec.end() << " - rbegin : " << *vec.rbegin() << " - rend : " << *vec.rend() << std::endl;

	std::cout << std::endl << "=== Capacity ===" << std::endl;
	std::cout << "size : " << vec.size() << " - max size : " << vec.max_size() << " - capacity : " << vec.capacity() << " - empty : " << vec.empty() << std::endl;
	vec.resize(5);
	std::cout << "vector after resize(5) : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size : " << vec.size() << " - max size : " << vec.max_size() << " - capacity : " << vec.capacity() << " - empty : " << vec.empty() << std::endl;
	vec.resize(12);
	std::cout << "vector after resize(12) : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size : " << vec.size() << " - max size : " << vec.max_size() << " - capacity : " << vec.capacity() << " - empty : " << vec.empty() << std::endl;
	vec.reserve(2);
	std::cout << "vector after reserve(2) : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size : " << vec.size() << " - max size : " << vec.max_size() << " - capacity : " << vec.capacity() << " - empty : " << vec.empty() << std::endl;
	vec.reserve(20);
	std::cout << "vector after reserve(20) : " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "size : " << vec.size() << " - max size : " << vec.max_size() << " - capacity : " << vec.capacity() << " - empty : " << vec.empty() << std::endl;

	std::cout << std::endl << "=== Element Access ===" << std::endl;
	std::cout << "vector[3] : " << vec[3] << std::endl;
	std::cout << "vector.at(3) : " << vec.at(3) << std::endl;
	std::cout << "exception with vector.at(13) : " << std::endl;
	try
	{
		std::cout << vec.at(12) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "vector.front : " << vec.front() << " vector.back : " << vec.back() << std::endl;
	
	std::cout << std::endl << "=== Modifiers ===" << std::endl;
	std::cout << "set a new vector to modify the existing one : " << std::endl;
	ft::vector<int> modif;
	for(int i = 42; i < 47; i++)
		modif.push_back(i);
	for (ft::vector<int>::iterator it = modif.begin(); it != modif.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "assign by range of iterators : " << std::endl;
	vec.assign(modif.begin(), modif.end());
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "assign by fill : vec.assign(4,12) " << std::endl;
	vec.assign(4, 12);
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
}