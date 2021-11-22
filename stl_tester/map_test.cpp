#include <map>
#include <iostream>

void map_test()
{
	std::cout << std::endl << "===== FT::MAP TESTS =====" << std::endl << std::endl;
	std::map<int, std::string> test;
	test.insert(std::pair<int, std::string> (5, "cinq"));
	test.insert(std::pair<int, std::string> (1, "un"));
	test.insert(std::pair<int, std::string> (32, "trente deux"));
	test.insert(std::pair<int, std::string> (25, "vingt cinq"));
	test.insert(std::pair<int, std::string> (12, "douze"));
	test.insert(std::pair<int, std::string> (21, "vingt et un"));

	std::map<int, std::string>::iterator it = test.begin();
	std::map<int, std::string>::iterator itt = test.end();
	itt--;
	std::cout << " comp : it == begin() : " << (it == test.begin()) << " it != begin() : " << (it != test.begin()) << std::endl;
	it++;
	std::cout << "it++" << std::endl;
	std::cout << " comp : it == begin() : " << (it == test.begin()) << " it != begin() : " << (it != test.begin()) << std::endl;
	std::cout << "ft::begin : " << test.begin()->second << std::endl << std::endl;
	std::cout << "ft::begin : " << (++it)->second << std::endl << std::endl;
	std::cout << "ft::end : " << itt->second << std::endl << std::endl;
	std::cout << "display test ft::map : " << std::endl;
	for (std::map<int, std::string>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;
	std::cout << std::endl << "display test ft::map by reverse it : " << std::endl;
	for (std::map<int, std::string>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::map<int, std::string>::iterator Cit = test.begin();
	std::map<int, std::string>::const_iterator Citt = test.begin();

	std::cout << "comp it et const_it begin() : " << (Cit == Citt) << std::endl;

	std::cout << std::endl << "=== Capacity ===" << std::endl;
	std::cout << "Create an empty map and test empty() :" << std::endl;
	std::map<int, int> empty;
	std::cout << "empty bool : " << empty.empty() << " and on the other existing one : " << test.empty() << std::endl;
	std::cout << "size : " << test.size() << " max_size : " << test.max_size() << std::endl;
	
	std::cout << std::endl << "=== Element Access ===" << std::endl;
	std::cout << "Return with map.[key] : " << std::endl;
	std::cout << "map[1] : " << test[1] << " map[32] : " << test[32] << std::endl;
	std::cout << "test a non existing key, map[3] : " << test[3] << std::endl;
	std::cout << "new iteration : " << std::endl;
	for (std::map<int, std::string>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;
}