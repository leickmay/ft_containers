#pragma once
#include <algorithm>
#include "../tools/pair.hpp"
#include "../tools/bst.hpp"
#include "../tools/tools.hpp"
#include "../tools/type_traits.hpp"
#include "../iterators/RandomAccessIterator.hpp"
#include "../iterators/ReverseIterator.hpp"
#include "../iterators/BstIterator.hpp"


namespace ft{
	template < class Key,
	class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > 
	> class map{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef std::less<key_type>						key_compare;

			class value_compare
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				protected:
					Compare comp;
					//value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			typedef Alloc allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef typename ft::bst<value_type, value_compare>::iterator				iterator;
			typedef typename ft::bst<value_type, value_compare>::const_iterator			const_iterator;
			typedef typename ft::bst<value_type, value_compare>::reverse_iterator		reverse_iterator;
			typedef typename ft::bst<value_type, value_compare>::const_reverse_iterator	const_reverse_iterator;

			typedef size_t										size_type;
			typedef ptrdiff_t									difference_type;

//empty 	(1)
			explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _alloc(alloc), _key_comp(comp){
				_value_comp = value_compare();
			}
//range 	(2)	
			/*template <class InputIterator>
			map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());
//copy (	3)	
			map (const map& x);*/
			iterator begin(){return _c.begin();}
			const_iterator begin() const{return _c.begin();}
			iterator end() {return _c.end();}
			const_iterator end() const {return _c.end();}

			ft::pair<iterator,bool> insert (const value_type& val)
			{
				pair<iterator, bool> ret;
				ret = _c.insert(val);
				return ret;
			};



		private:
			ft::bst<value_type, key_compare>	_c;
			allocator_type						_alloc;
			key_compare							_key_comp;
			value_compare						_value_comp;

	};
}