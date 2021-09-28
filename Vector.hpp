#pragma once

#include <algorithm>
#include <iostream>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T		value_type;
			typedef Alloc	allocator_type;
//default (1)	
			explicit vector (const allocator_type& alloc = allocator_type()){};
//fill (2)	
			//explicit vector (size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
//range (3)	
			//template <class InputIterator>
			//vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
//copy (4)	
			//vector (const vector& x);

		//Iterators
			

		private:
			int i;
	};
}