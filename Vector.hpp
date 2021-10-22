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

			typedef typename std::size_t	size_type;
			typedef typename std::ptrdiff_t	difference_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
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