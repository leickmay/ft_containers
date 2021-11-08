#include <iostream>
#include "iterators/RandomAccessIterator.hpp"
#include <vector>
#include "containers/Vector.hpp"


int main()
{

	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	std::cout << "Display V :" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;

	ft::vector<int> myv;
	for (int i = 0; i < 10; i++)
		myv.push_back(i);
	std::cout << "Display myV :" << std::endl;
	for (ft::vector<int>::iterator it = myv.begin(); it != myv.end(); it++)
		std::cout << *it << std::endl;

	std::vector<int> insrt;
	for (int i = 40; i < 44; i++)
		insrt.push_back(i);
	std::cout << "Display insrt :" << std::endl;
	for (std::vector<int>::iterator it = insrt.begin(); it != insrt.end(); it++)
		std::cout << *it << std::endl;

	v.insert(v.begin() + 20, insrt.begin(), insrt.end());
	std::cout << "Display V after insert : size - capacity " << v.size() << " " << v.capacity() << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;

	myv.insert(myv.begin() + 20, insrt.begin(), insrt.end());
	std::cout << "Display myV after insert : size - capacity " << v.size() << " " << v.capacity() << std::endl;
	for (ft::vector<int>::iterator it = myv.begin(); it != myv.end(); it++)
		std::cout << *it << std::endl;
	/*std::vector<int> array;
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
	array.insert(array.begin(), 1, 10);
	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	array.insert(array.begin(), 10);
	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	array.insert(array.begin(), 1, 10);
	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	array.insert(array.begin(), array.begin(), array.end());
	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;
	std::vector<int>::iterator pp = array.begin();
	pp++;
	pp++;
	pp++;
	std::vector<int>::iterator pe = array.end();
	pe--;
	pe--;
	pe--;
	std::cout << "ret : " << *array.erase(pp, pe) << std::endl;
	std::cout << "array after erase : " << std::endl;
	for (std::vector<int>::iterator i = array.begin(); i != array.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	myarray.push_back(20);
		std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.push_back(4);
		std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.push_back(6);
		std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.push_back(8);
		std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.insert(myarray.begin(), 1, 10);
	std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.insert(myarray.begin(), 10);
	std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.insert(myarray.begin(), 1, 10);
	std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.insert(myarray.begin(), myarray.begin(), myarray.end());
	std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;

		std::cout << "myarray after insert : " << std::endl;
	for (ft::vector<int>::iterator i = myarray.begin(); i != myarray.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	ft::vector<int>::iterator mpp = myarray.begin();
	mpp++;
	mpp++;
	mpp++;
	ft::vector<int>::iterator mpe = myarray.end();
	mpe--;
	mpe--;
	mpe--;
	std::cout << "myarray part to erase : " << std::endl;
	for (ft::vector<int>::iterator i = mpp; i != mpe; i++)
	{
		std::cout << *i << std::endl;
	}

	std::cout << "ret : " << *myarray.erase(mpp, mpe) << std::endl;
	std::cout << "myarray after erase : " << std::endl;
	for (ft::vector<int>::iterator i = myarray.begin(); i != myarray.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	ft::vector<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);

	std::cout << " === SWAP === " << std::endl;

	array.swap(a);
	myarray.swap(b);
	std::cout << "array : " << std::endl;
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "a : " << std::endl;
	for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "my array : " << std::endl;
	for (ft::vector<int>::iterator it = myarray.begin(); it != myarray.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "b : " << std::endl;
	for (ft::vector<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;

	std::cout << " === CLEAR === " << std::endl;

	array.clear();
	std::cout << "array size - capacity after cleaning : " << array.size() << " " << array.capacity() << std::endl;
	array.push_back(1000);
	array.push_back(2000);
	std::cout << "array : " << std::endl;
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "array size - capacity : " << array.size() << " " << array.capacity() << std::endl;

	myarray.clear();
	std::cout << "myarray size - capacity after cleaning : " << myarray.size() << " " << myarray.capacity() << std::endl;
	myarray.push_back(1000);
	myarray.push_back(2000);
	std::cout << "myarray : " << std::endl;
	for (ft::vector<int>::iterator it = myarray.begin(); it != myarray.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "myarray size - capacity : " << myarray.size() << " " << myarray.capacity() << std::endl;

	std::cout << " === RELATIONAL OPERATORS ===" << std::endl;
	std::cout << "array == a : " << (array == a) << std::endl;
	std::cout << "array == array : " << (array == array) << std::endl;
	std::cout << "myarray == b : " << (myarray == b) << std::endl;
	std::cout << "myarray == myarray : " << (myarray == myarray) << std::endl;
	std::cout << "array != a : " << (array != a) << std::endl;
	std::cout << "array != array : " << (array != array) << std::endl;
	std::cout << "myarray != b : " << (myarray != b) << std::endl;
	std::cout << "myarray != myarray : " << (myarray != myarray) << std::endl;
	std::cout << "array < a : " << (array < a) << std::endl;
	std::cout << "array < array : " << (array < array) << std::endl;
	std::cout << "myarray < b : " << (myarray < b) << std::endl;
	std::cout << "myarray < myarray : " << (myarray < myarray) << std::endl;
	std::cout << "array <= a : " << (array <= a) << std::endl;
	std::cout << "array <= array : " << (array <= array) << std::endl;
	std::cout << "myarray <= b : " << (myarray <= b) << std::endl;
	std::cout << "myarray <= myarray : " << (myarray <= myarray) << std::endl;
	std::cout << "array > a : " << (array > a) << std::endl;
	std::cout << "array > array : " << (array > array) << std::endl;
	std::cout << "myarray > b : " << (myarray > b) << std::endl;
	std::cout << "myarray > myarray : " << (myarray > myarray) << std::endl;
	std::cout << "array >= a : " << (array >= a) << std::endl;
	std::cout << "array >= array : " << (array >= array) << std::endl;
	std::cout << "myarray >= b : " << (myarray >= b) << std::endl;
	std::cout << "myarray >= myarray : " << (myarray >= myarray) << std::endl;

	ft::vector<std::string> myfill(5, "pouic");
	for (ft::vector<std::string>::iterator it = myfill.begin(); it != myfill.end(); it++)
		std::cout << *it << std::endl;

	std::vector<std::string> fill(5, "pouic-");
	for (std::vector<std::string>::iterator it = fill.begin(); it != fill.end(); it++)
		std::cout << *it << std::endl;

	ft::vector<int> mylol;
	mylol.push_back(1);
	mylol.push_back(2);
	mylol.push_back(3);
	mylol.push_back(4);
	mylol.push_back(5);
	ft::vector<int>::iterator mlb = mylol.begin();
	mlb++;
	ft::vector<int>::iterator mle = mylol.end();
	mle--;
	std::cout << "mlb - mle : " << *mlb << " - " << *mle << std::endl;
	std::vector<int> lol;
	lol.push_back(1);
	lol.push_back(2);
	lol.push_back(3);
	lol.push_back(4);
	lol.push_back(5);
	std::vector<int>::iterator lb = lol.begin();
	lb++;
	std::vector<int>::iterator le = lol.end();
	le--;
	std::cout << "lb - le : " << *lb << " - " << *le << std::endl;
	ft::vector<int> mytest (mlb, mle);
	std::vector<int> test (lb, le);

	for (ft::vector<int>::iterator it = mytest.begin(); it != mytest.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "lol : " << std::endl;
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << *it << std::endl;

	//array.clear();*/

/*std::cout << "empty test : " << myarray.empty() << " -- " << array.empty() << std::endl;

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

*/

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