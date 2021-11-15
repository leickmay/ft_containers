#include "tools/bst.hpp"


int main()
{
	ft::bst<int, std::string> test;
	test.insert(10, "pouic");
	test.insert(5, " lol");
	test.insert(4, "leaks ?");
	test.insert(32, "maybe");
	test.print();
	return 0;
}