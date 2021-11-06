#pragma once

#include <algorithm>
#include <iostream>
#include "../iterators/RandomAccessIterator.hpp"
#include "../iterators/ReverseIterator.hpp"
#include "../tools/type_traits.hpp"
#include "../tools/tools.hpp"


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
			typedef ft::RandomAccessIterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const iterator>		const_reverse_iterator;


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
			const_iterator begin() const {return _c;}
			iterator end() {return &_c[_size];}
			const_iterator end() const {return &_c[_size];}
			reverse_iterator rbegin(){return reverse_iterator(end());}
			const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
			reverse_iterator rend(){return reverse_iterator(begin());}
			const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

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
			};

			size_type	capacity() const {return _capacity;}

			bool empty() const {return (_size == 0);}

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

		//Element access

			reference operator[] (size_type n){return _c[n];}

			const_reference operator[] (size_type n) const{return _c[n];}

			reference at (size_type n){
				if (n >= _size)
					throw std::out_of_range("vector");
				return _c[n];
			};

			const_reference at (size_type n) const{
				if (n >= _size)
					throw std::out_of_range("vector");
				return _c[n];
			};

			reference front() {return _c[0];}

			const_reference front() const{ return _c[0];}

			reference back() {return _c[_size - 1];}

			const_reference back() const {return _c[_size - 1];}

		//modifiers

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL){
				size_type size = last - first;
				if (size > _capacity)
				{
					pointer tmp = _alloc.allocate(size);
					for (int i = 0; i < size; i++)
					{
						_alloc.construct(&tmp[i], *first);
						_alloc.destroy(&_c[i]);
						first++;
					}
					_c = tmp;
					_capacity = size;
					_size = size;
				}
				else
				{
					for (int i = 0; i < size; i++)
					{
						_alloc.destroy(&_c[i]);
						_alloc.construct(&_c[i], *first);
						first++;
					}
					_size = size;
				}
			}


			void assign (size_type n, const value_type& val){
				if (n > _capacity)
				{
					pointer tmp = _alloc.allocate(n);
					for (int i = 0; i < n; i++)
					{
						_alloc.construct(&tmp[i], val);
						_alloc.destroy(&_c[i]);
					}
					_c = tmp;
					_capacity = n;
					_size = n;
				}
				else
				{
					for (int i = 0; i < n; i++)
					{
						_alloc.destroy(&_c[i]);
						_alloc.construct(&_c[i], val);
					}
					_size = n;
				}
			}

			void	push_back(const value_type& val){
				if (_size + 1 > _capacity)
					_reAlloc();
				_alloc.construct(&_c[_size], val);
				_size++;
			}

			void	pop_back(){
				_alloc.destroy(&_c[_size - 1]);
				_size--;
			}


//single element (1)	
			iterator insert (iterator position, const value_type& val){
				if (_size + 1 > _capacity)
					_reAlloc();
				int i = _size - 1;
				iterator it = end();
				_alloc.construct(&_c[_size], _c[i]);
				_size++;
				it--;
				while (it != position && i > 0)
				{
					_alloc.destroy(&_c[i]);    
					_alloc.construct(&_c[i], _c[i - 1]);
					i--;
					it--;
				}
				_alloc.destroy(&_c[i]);
				_alloc.construct(&_c[i], val);
				return it;
			};
			//fill (2)	
			void insert (iterator position, size_type n, const value_type& val){
			if (n <= 0 )
				return;
			if (n + _size > _capacity && n + _size <= _capacity * 2)
				_reAlloc();
			else
				reserve(_size + n);
				for (size_type i = 0; i < _size; i++){
					_alloc.construct(&_c[_size - 1 + n - i], _c[_size - 1 - i]);
					_alloc.destroy(&_c[_size - 1 - i]);
				}
					//_c[_size - 1 + n - i] = _c[_size - 1 - i];
				for (size_type i = 0; i < n; i++){
					_alloc.destroy(&_c[i]);
					_alloc.construct(&_c[i], val);
				}
		//_c[i] = val;
	_size += n;
}
//range (3)	
			template <class InputIterator>
			    void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL){
					size_type dist = last - first;

					if (dist <= 0 )
						return;
					if (dist + _size > _capacity && dist + _size <= _capacity * 2)
						_reAlloc();
					else
						reserve(_size + dist);
						for (size_type i = 0; i < dist; i++){
							_alloc.construct(&_c[_size - 1 + dist - i], _c[_size - 1 - i]);
							_alloc.destroy(&_c[_size - 1 - i]);
						}
						for (size_type i = 0; i < dist; i++){
							_alloc.destroy(&_c[i]);
							_alloc.construct(&_c[i], *first);
							first++;
						}
						_size += dist;
				}

			iterator erase (iterator position){
				size_type dist = position - begin();
				//_alloc.destroy(&_c[dist]);
				iterator it = position;
				while (it != (end() - 1))
				{
					_alloc.destroy(&_c[dist]);
					_alloc.construct(&_c[dist], _c[dist + 1]);
					dist++;
					it++;
				}
				_alloc.destroy(&_c[dist]);
				_size--;
				return position;
			}
			iterator erase (iterator first, iterator last){
				size_type dist = first - begin();
				size_type l = last - first;
				iterator it = first;
				while (it != last)
				{
					_alloc.destroy(&_c[dist]);
					_alloc.construct(&_c[dist], _c[dist + l]);
					dist++;
					it++;
				}
				while (it != end())
				{
					_alloc.destroy(&_c[dist]);
					dist++;
					it++;
				}
				_size -= l;
				return first;
			}

			void swap (vector& x){
				pointer 		tmpC = _c;
				size_type		tmpSize = _size;
				size_type		tmpCapacity = _capacity;
				allocator_type	tmpAlloc = _alloc;

				_c = x._c;
				_size = x._size;
				_capacity = x._capacity;
				_alloc = x._alloc;

				x._c = tmpC;
				x._size = tmpSize;
				x._capacity = tmpCapacity;
				x._alloc = tmpAlloc;
			}

			void clear(){
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_c[i]);
				_size = 0;
			}

			//Allocator
			allocator_type get_allocator() const {return _alloc;};

		private:
			void _reAlloc()
			{
				if (_capacity == 0)
				{
					_c = _alloc.allocate(1);
					_capacity = 1;
				}
				else
				{
					pointer tmp = _alloc.allocate(_capacity * 2);
					for (int i = 0; i < _size; i++)
					{
						_alloc.construct(&tmp[i], _c[i]);
						_alloc.destroy(&_c[i]);
					}
					_c = tmp;
					_capacity *= 2;
				}
			}

			pointer			_c;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
	};

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	if (lhs.size() != rhs.size())
		return false;	
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
  }
/*
template <class T, class Alloc>
  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
*/
}