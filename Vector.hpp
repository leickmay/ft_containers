#pragma once

#include <algorithm>
#include <iostream>
#include "iterators/RandomAccessIterator.hpp"


namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T		value_type;
			typedef Alloc	allocator_type;

			typedef size_t		size_type;
			typedef ptrdiff_t	difference_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef ft::RandomAccessIterator<value_type> 		iterator;
			typedef const ft::RandomAccessIterator<value_type>	const_iterator;


//default (1)	
			explicit vector (const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), _alloc(alloc), _c(NULL){};
//fill (2)	
			explicit vector (size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(n), _capacity(n), _alloc(alloc), _c(NULL)
			{
				push_back(val);
			};
//range (3)	
			//template <class InputIterator>
			//vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
//copy (4)	
			//vector (const vector& x);


			//Iterators
			iterator begin() {return _c;}
			iterator end() {return &_c[_size];}
			//Capacity
			size_type	size() const {return _size;}
			size_type	max_size() const {return _alloc.max_size();}
			void		resize (size_type n, value_type val = value_type()){
				if (n < _size)
				{
					for (int i = n; i < _size; i++)
						_alloc.destroy(&_c[i]);
				}
				else if (n < _capacity)
				{
					for (int i = _size; i < n; i++)
						_alloc.construct(&_c[i], val);
				}
				if (n > _capacity)
				{
					reserve(n);
					for (int i = _size; i < n; i++)
						_alloc.construct(&_c[i], val);
				}
				_size = n;
				std::cout << " n : " << n << " et val : " << val << std::endl;
				
			};
			size_type	capacity() const {return _capacity;}

			void		reserve(size_type n){
				if (n > _capacity)
				{
					pointer tmp = _alloc.allocate(n);
					for (int i = 0; i < _size; i++)
					{
						_alloc.construct(&tmp[i], _c[i]);
						_alloc.destroy(&_c[i]);
					}
					_c = tmp;
					_capacity = n;
				}
			}

			void	push_back(value_type val){
				if (_size + 1 > _capacity)
					resize(_size + 1, val);
				else
				{
					_alloc.construct(&_c[_size], val);
					_size++;
				}
			}

		private:
			pointer			_c;
			int				_size;
			int				_capacity;
			allocator_type	_alloc;
	};
}