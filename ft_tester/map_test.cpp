#include "../containers/Map.hpp"

void map_test()
{
	std::cout << std::endl << "===== FT::MAP TESTS =====" << std::endl << std::endl;
	ft::map<int, std::string> test;
	test.insert(ft::pair<int, std::string> (5, "cinq"));
	test.insert(ft::pair<int, std::string> (1, "un"));
	test.insert(ft::pair<int, std::string> (32, "trente deux"));
	test.insert(ft::pair<int, std::string> (25, "vingt cinq"));
	test.insert(ft::pair<int, std::string> (12, "douze"));
	test.insert(ft::pair<int, std::string> (21, "vingt et un"));

	ft::map<int, std::string>::iterator it = test.begin();
	ft::map<int, std::string>::iterator itt = test.end();
	itt--;
	std::cout << " comp : it == begin() : " << (it == test.begin()) << " it != begin() : " << (it != test.begin()) << std::endl;
	it++;
	std::cout << "it++" << std::endl;
	std::cout << " comp : it == begin() : " << (it == test.begin()) << " it != begin() : " << (it != test.begin()) << std::endl;
	std::cout << "ft::begin : " << test.begin()->second << std::endl << std::endl;
	std::cout << "ft::begin : " << (++it)->second << std::endl << std::endl;
	std::cout << "ft::end : " << itt->second << std::endl << std::endl;
	std::cout << "display test ft::map : " << std::endl;
	for (ft::map<int, std::string>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;
	std::cout << std::endl << "display test ft::map by reverse it : " << std::endl;
	for (ft::map<int, std::string>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	ft::map<int, std::string>::iterator Cit = test.begin();
	ft::map<int, std::string>::const_iterator Citt = test.begin();

	std::cout << "comp it et const_it begin() : " << (Cit == Citt) << std::endl;

	std::cout << std::endl << "=== Capacity ===" << std::endl;
	std::cout << "Create an empty map and test empty() :" << std::endl;
	ft::map<int, int> empty;
	std::cout << "empty bool : " << empty.empty() << " and on the other existing one : " << test.empty() << std::endl;
	std::cout << "size : " << test.size() << " max_size : " << test.max_size() << std::endl;

	std::cout << std::endl << "=== Element Access ===" << std::endl;
	std::cout << "Return with map.[key] : " << std::endl;
	std::cout << "map[1] : " << test[1] << " map[32] : " << test[32] << std::endl;
	std::cout << "test a non existing key, map[3] : " << test[3] << std::endl;
	std::cout << "new iteration : " << std::endl;
	for (ft::map<int, std::string>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;
	
	ft::map<int, std::string>::iterator po = test.begin();
	po++;
	po++;
	po++;
	std::cout << "new iterator : " << po->first << " - " << po->second << std::endl;
	std::cout << "insert with position it, 11 and 13 then display map : " << std::endl;
	test.insert(po, ft::make_pair(11, "onze"));
	test.insert(po, ft::make_pair(13, "treize"));

	for (ft::map<int, std::string>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;

	std::cout << "New map, insert with iterators of the old one : " << std::endl;
	ft::map<int, std::string> test2;
	test2.insert(po, --test.end());
	for (ft::map<int, std::string>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;
std::cout << "size : " << test2.size() << std::endl;
	std::cout << "erase ++begin : " << std::endl;
	test2.erase(++test2.begin());
	for (ft::map<int, std::string>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;
		std::cout << "----" << std::endl;
	for (ft::map<int, std::string>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;
	std::cout << "erase(21) : " << std::endl;
	std::cout << "size : " << test2.size() << std::endl;
	test2.erase(21);
	for (ft::map<int, std::string>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;
	std::cout << "size : " << test2.size() << std::endl;
	std::cout << "test 2 begin : " << test2.begin()->second << std::endl;
	test2.erase(test2.begin(), test2.end());
	std::cout << " -- -- -- " << std::endl;
	for (ft::map<int, std::string>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;
	std::cout << "final size : " << test2.size() << std::endl;

	std::cout << "Take back first map : " << std::endl;
	for (ft::map<int, std::string>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl ;

	ft::map<int, std::string>::iterator er = test.begin();
	ft::map<int, std::string>::iterator ere = test.end();


	ere--;
	ere--;

	std::cout << "erase from iterator " << er->first << " to " << ere->first << std::endl;
	test.erase(ere);
	for (ft::map<int, std::string>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "key : loooooop" << it->first << " - value : " << it->second << std::endl ;
	

std::cout << std::endl << "Swap the 2 maps : " << std::endl;
test.swap(test2);
	for (ft::map<int, std::string>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "key " << it->first << " - value : " << it->second << std::endl ;
	for (ft::map<int, std::string>::iterator it = test2.begin(); it != test2.end(); it++)
		std::cout << "key " << it->first << " - value : " << it->second << std::endl ;

	ft::map<int, std::string>::iterator f;
	f = test.find(12);
	std::cout << "f : " << f->first << " - " << f->second << std::endl;
	std::cout << "count 12 : " << test.count(12) << " count 123 : " << test.count(123) << std::endl;
ft::map<int, std::string> ctest(test);
std::cout << "Copy : " << std::endl;
	
	for (ft::map<int, std::string>::iterator it = ctest.begin(); it != ctest.end(); it++)
		std::cout << "key " << it->first << " - value : " << it->second << std::endl ;

}