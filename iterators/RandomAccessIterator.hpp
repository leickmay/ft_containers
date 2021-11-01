#pragma once

#include "iterator_traits.hpp"

namespace ft{
	template < class T >
	class RandomAccessIterator{
		public:
		//typedef
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

		//constructors
			RandomAccessIterator():_ptr(NULL) {};
			RandomAccessIterator(pointer ptr):_ptr(ptr) {};
			~RandomAccessIterator() {};
			RandomAccessIterator (RandomAccessIterator const& other): _ptr(other._ptr) {};
			RandomAccessIterator &operator=(RandomAccessIterator const& other) {
				if (this != &other)
					_ptr = other._ptr;
				return *this; 
			};

		//Dereference
			reference operator*() {return *_ptr;}
			pointer operator->() const {return &(operator*());}

		//Incrementation
			RandomAccessIterator	&operator++() {
				++_ptr;
				return *this;
			}
			RandomAccessIterator	operator++(int) {
				RandomAccessIterator ret(*this);
				++_ptr;
				return ret;
			}
			RandomAccessIterator	&operator--() {
				--_ptr;
				return *this;
			}
			RandomAccessIterator	operator--(int) {
				RandomAccessIterator ret(*this);
				--_ptr;
				return ret;
			}
			RandomAccessIterator	&operator+=(difference_type n) {
				_ptr += n;
				return *this;
			}
			RandomAccessIterator	&operator-=(difference_type n) {
				_ptr -= n;
				return *this;
			}

			//Arithmetics
			RandomAccessIterator	operator+(difference_type n){return (_ptr + n);}
			RandomAccessIterator	operator-(difference_type n){return (_ptr - n);}
			difference_type			operator-(RandomAccessIterator const& a){return _ptr - a._ptr;}


			//comparisons
			bool					operator!=(RandomAccessIterator const& a){return (a._ptr != _ptr);}
			bool					operator==(RandomAccessIterator const& a){return (a._ptr == _ptr);}
			bool					operator>=(RandomAccessIterator const& a){return (a._ptr >= _ptr);}
			bool					operator<=(RandomAccessIterator const& a){return (a._ptr <= _ptr);}
			bool					operator>(RandomAccessIterator const& a){return (a._ptr > _ptr);}
			bool					operator<(RandomAccessIterator const& a){return (a._ptr < _ptr);}


			//offset derefence operator
			reference &operator[] (difference_type n) const {return &_ptr[n];}
		private:
			pointer	_ptr;
	};
}