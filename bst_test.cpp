#include "containers/Map.hpp"
#include <map>


int main()
{
	/*ft::bst<int, std::string> test;
	test.insert(10, "pouic");
	test.insert(5, " lol");
	test.insert(4, "leaks ?");
	test.insert(32, "maybe");
	test.insert(11, "pouic");
	test.insert(6, " lol");
	test.insert(3, "leaks ?");
	test.insert(33, "maybe");
	test.print();
	std::cout << "root : " << test.getRoot()->data << std::endl;*/
	//ft::bst<int, std::string>::iterator it;
	
	ft::map<int, std::string> test2;
	test2.insert(ft::pair<int, std::string> (5, "lol"));
	test2.insert(ft::pair<int, std::string> (1, "pouic"));
	test2.insert(ft::pair<int, std::string> (2, "aha"));

	ft::map<int, std::string>::iterator it = test2.begin();
	std::cout << " comp : it == begin() : " << (it == test2.begin()) << " it != begin() : " << (it != test2.begin()) << std::endl;
	it++;
	std::cout << "it++" << std::endl;
	std::cout << " comp : it == begin() : " << (it == test2.begin()) << " it != begin() : " << (it != test2.begin()) << std::endl;
	std::cout << "ft::begin : " << test2.begin()->second << std::endl << std::endl;
	std::cout << "ft::begin : " << (++it)->second << std::endl << std::endl;
	std::cout << "ft::end : " << test2.end()->second << std::endl << std::endl;


	std::map<int, std::string> test3;

	test3.insert(std::pair<int, std::string> (5, "lol"));
	test3.insert(std::pair<int, std::string> (1, "pouic"));
	test3.insert(std::pair<int, std::string> (2, "aha"));

	std::map<int, std::string>::iterator it3 = test3.begin();
	it3++;

	std::cout << "std::begin : " << test3.begin()->second << std::endl;
	std::cout << "std::begin : " << (++it3)->second << std::endl << std::endl;
	std::cout << "std::end : " << test3.end()->second << std::endl << std::endl;

	return 0;
}