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
	template < class Key, /* map::key_type */
	class T, /* map::mapped_type */
	class Compare = less<Key>, /* map::key_compare*/
	class Alloc = std::allocator<pair<const Key,T> > /* map::allocator_type*/
	> class map{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef less<key_type>							key_compare;
			//value_compare to add

			typedef Alloc allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef ft::BstIterator<value_type>					iterator;
			typedef ft::BstIterator<const value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const iterator>		const_reverse_iterator;
			typedef size_t										size_type;
			typedef ptrdiff_t									difference_type;

//empty 	(1)
			explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());
//range 	(2)	
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());
//copy (	3)	
			map (const map& x);

		private:
			ft::bst<key_type, mapped_type>	_c;
			allocator_type					_alloc;

	};
}