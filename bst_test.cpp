#include "tools/bst.hpp"


int main()
{
	ft::bst<int, std::string> test;
	test.insert(10, "pouic");
	test.insert(5, " lol");
	test.insert(4, "leaks ?");
	test.insert(32, "maybe");
	test.insert(11, "pouic");
	test.insert(6, " lol");
	test.insert(3, "leaks ?");
	test.insert(33, "maybe");
	test.print();
	std::cout << "root : " << test.getRoot()->data << std::endl;
	ft::bst<int, std::string>::iterator it;
	
	return 0;
}