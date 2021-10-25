#pragma once


namespace ft{
	template < class T >
	class RandomAccessIterator{
		public:
		//typedef
			typedef T	value_type;
			typedef T*	pointer;
			typedef T&	reference;

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

		//comparisons methodes
			pointer getPointer() {return _ptr;}

			value_type operator*() {return *_ptr;}
			RandomAccessIterator &operator++() {
				_ptr++;
				return *this;
			}

		private:
			pointer	_ptr;
			reference _ref;
	};
	//comparisons
	/*
		bool	operator==(RandomAccessIterator const& a, RandomAccessIterator const& b){
			return (a.getPointer() == b.getPointer());
		}
		bool	operator!=(RandomAccessIterator const& a, RandomAccessIterator const& b){
			return (a.getPointer() != b.getPointer());
		}
		bool	operator>=(RandomAccessIterator const& a, RandomAccessIterator const& b){
			return (a.getPointer() >= b.getPointer());
		}
		bool	operator<=(RandomAccessIterator const& a, RandomAccessIterator const& b){
			return (a.getPointer() <= b.getPointer());
		}
		bool	operator>(RandomAccessIterator const& a, RandomAccessIterator const& b){
			return (a.getPointer() > b.getPointer());
		}
		bool	operator<(RandomAccessIterator const& a, RandomAccessIterator const& b){
			return (a.getPointer() < b.getPointer());
		}
		//RandomAccessIteratot::value_type operator*()
		*/
}