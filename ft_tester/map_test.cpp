#include "../containers/Map.hpp"

void map_test()
{
	/*std::cout << std::endl << "===== FT::MAP TESTS =====" << std::endl << std::endl;
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
	//ft::map<int, std::string>::iterator pit = test2.begin();
	for (ft::map<int, std::string>::iterator pit = test2.begin(); pit != test2.end(); pit++)
		std::cout << "key : " << pit->first << " - value : " << pit->second << std::endl ;

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
	//test2.erase(test2.begin(), test2.end());
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
		std::cout << "key " << it->first << " - value : " << it->second << std::endl ;*/

	std::cout << std::endl << "======== FT::MAP TESTS ========" << std::endl << std::endl;

	std::cout << std::endl << "===== Constructors =====" << std::endl << std::endl;
	std::cout << "Create an empty map m1 and fill it with insert fct : " << std::endl;
	ft::map<int, std::string> m1;
	m1.insert(ft::pair<int, std::string> (15, "quinze"));
	m1.insert(ft::pair<int, std::string> (1, "un"));
	m1.insert(ft::pair<int, std::string> (32, "trente deux"));
	m1.insert(ft::pair<int, std::string> (25, "vingt cinq"));
	m1.insert(ft::pair<int, std::string> (12, "douze"));
	m1.insert(ft::pair<int, std::string> (21, "vingt et un"));
	std::cout << "Display m1 : " << std::endl;
	for (ft::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	ft::map<int, std::string>::iterator itb = ++m1.begin();
	ft::map<int, std::string>::iterator ite = --m1.end();
	ite--;
	std::cout << std::endl << "Create a map m2 with a range of iterators from " << itb->first << " to " << ite->first << std::endl;
	ft::map<int, std::string> m2(itb, ite);
	std::cout << "Display m2 : " << std::endl;
	for (ft::map<int, std::string>::iterator it = m2.begin(); it != m2.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	/*std::cout << std::endl << "Create a copy map of m1 using copy constructor : " << std::endl;
	ft::map<int, std::string> copy(m1);
	std::cout << "Display copy : " << std::endl;
	for (ft::map<int, std::string>::iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "Create a copy2 map of m1 using assignation operator : " << std::endl;
	ft::map<int, std::string> copy2 = m1;
	std::cout << "Display copy2 : " << std::endl;
	for (ft::map<int, std::string>::iterator it = copy2.begin(); it != copy2.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;
*/
	std::cout << std::endl << "===== Iterators =====" << std::endl << std::endl;
	std::cout << "Display m1 from rbegin to rend :" << std::endl;
	for (ft::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "Compare iterators : " << std::endl;
	ft::map<int, std::string>::iterator itc = m1.begin();
	ft::map<int, std::string>::const_iterator citc = m1.begin();
	std::cout << "m1.begin() == const m1.begin() : " << (itc == citc) << std::endl;
	std::cout << "m1.begin() != const m1.begin() : " << (itc != citc) << std::endl;

	std::cout << std::endl << "===== Capacity =====" << std::endl << std::endl;
	std::cout << "m1 size : " << m1.size() << " - empty : " << m1.empty() << " - max size : " << m1.max_size() << std::endl;

	std::cout << std::endl << "===== Element access =====" << std::endl << std::endl;
	std::cout << "access elements with m1[key] : " << std::endl;
	std::cout << "m1[1] : " << m1[1] << " - m1[32] : " << m1[32] << " - m1[21] : " << m1[21] << std::endl;
	std::cout << "insert an element using a non existing key, m1[4] = quatre, and display m1" << std::endl;
	m1[4] = "quatre";
	for (ft::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "===== Modifiers =====" << std::endl << std::endl;
	ft::pair<ft::map<int, std::string>::iterator, bool> ret_insert = m1.insert(ft::make_pair(1, "test"));
	std::cout << "insert on an already existing key, return : iterator key : " << ret_insert.first->first \
	<< " - value : " << ret_insert.first->second << " - bool : " << ret_insert.second << std::endl;
	ret_insert = m1.insert(ft::make_pair(27, "vingt-sept"));
	std::cout << "insert on a non-existing key, return : iterator key : " << ret_insert.first->first \
	<< " - value : " << ret_insert.first->second << " - bool : " << ret_insert.second << std::endl;

	ret_insert = m1.insert(ft::make_pair(12, "pouic"));
	ft::map<int, std::string>::iterator douze = ret_insert.first;
	ft::map<int, std::string>::iterator onze = m1.insert(douze, ft::make_pair(11, "onze"));
	std::cout << "insert 11 with an hint position 12 - ret iterator : " << onze->first << " - " << onze->second << std::endl;

	ft::map<int, std::string>::iterator treize = m1.insert(douze, ft::make_pair(13, "treize"));
	std::cout << "insert 13 with an hint position 12 - ret iterator : " << treize->first << " - " << treize->second << std::endl;

	std::cout << std::endl << "Create a new m3 map and display it : " << std::endl;
	ft::map<int, std::string> m3;
	m3.insert(ft::pair<int, std::string> (-10, "moins dix"));
	m3.insert(ft::pair<int, std::string> (427, "Quatre cent vingt-sept"));
	m3.insert(ft::pair<int, std::string> (8, "huit"));
	for (ft::map<int, std::string>::iterator it = m3.begin(); it != m3.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;
	std::cout << std::endl << "use m3.begin() and m3.end() as iterators to insert in m1, display m1 : " << std::endl;
	m1.insert(m3.begin(), m3.end());
	for (ft::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	ret_insert = m1.insert(ft::make_pair(25, "pouic"));
	std::cout << std::endl << "Erase 25 by iterator and print m1: " << std::endl;
	ft::map<int, std::string>::iterator vingtcinq = ret_insert.first;
	m1.erase(vingtcinq);
	for (ft::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "Erase 427 by key and print the return : " << std::endl;
	size_t ret1 = m1.erase(427);
	std::cout << "ret1 : " << ret1 << std::endl;
	std::cout << "Try to erase 321 (that doesn't exist) by key and print the return : " << std::endl;
	size_t ret2 = m1.erase(321);
	std::cout << "ret2 : " << ret2 << std::endl;

	ft::map<int, std::string>::iterator itt = m1.begin();
	itt++;
	itt++;
	ft::map<int, std::string>::iterator ittee = m1.end();
	ittee--;

	std::cout << std::endl << "Erase by range between " << "itt : " << itt->first << " and ittee  ans print m1 : " << ittee->first << std::endl;
	m1.erase(itt, ittee);
	for (ft::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;
		std::cout << "size : " << m1.size() << std::endl;

	std::cout << std::endl << "Swap m1 and m3, print them : " << std::endl;
	m1.swap(m3);
	std::cout << "m1 : " << std::endl;
	for (ft::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;
	std::cout << "m3 : " << std::endl;
	for (ft::map<int, std::string>::iterator it = m3.begin(); it != m3.end(); it++)
		std::cout << "key : " << it->first << " - value : " << it->second << std::endl;

	std::cout << std::endl << "clear m3 and print its size : " << std::endl;
	m3.clear();
	std::



	/*srand(time(NULL));

	ft::map<int, char> tab;
	for (int i = 0; i < 10000000; i++)
	{
		int nb = rand() % 100000;
		tab.insert(ft::make_pair<int, char>(nb, 'e'));
	}*/

}