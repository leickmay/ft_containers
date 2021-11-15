#pragma once

namespace ft{
	template <class T1, class T2> struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		pair() {};
		template<class U, class V> pair (const pair<U,V>& pr): first(pr._a), second(pr.b) {};
		pair (const first_type& a, const second_type& b): first(a), second(b){};
		pair& operator= (const pair& pr){
			if (pr != &this)
			{
				first = pr.first;
				second = pr.second;
			}
			return *this;
		};

		first_type	first;
		second_type	second;
	};
	template< class T1, class T2 >
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return (lhs.first == rhs.first && lhs.second == rhs.second)
	};

	template <class T> struct less : binary_function <T,T,bool> {
	bool operator() (const T& x, const T& y) const {return x<y;}

	};
}