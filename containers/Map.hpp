#pragma once
typedef pair<const Key, T> value_type;
namespace ft{
	template < class Key, /* map::key_type */
           class T, /* map::mapped_type */
           class Compare = less<Key>, /* map::key_compare*/
           class Alloc = allocator<pair<const Key,T> > /* map::allocator_type*/
           > class map{
			
			typedef Key key_type;
			typedef T	mapped_type;
			typedef pair<const key_type, mapped_type>	value_type;
			typedef less<key_type>						key_compare;
			
		   };
}