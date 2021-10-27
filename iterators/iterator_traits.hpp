#pragma once

namespace ft{
	template <class Iterator> class iterator_traits;
	template <class T> class iterator_traits<T*>{
		typedef Iterator::difference_type	difference_type;
		typedef Iterator::value_type		value_type;
		typedef Iterator::pointer			pointer;
		typedef Iterator::reference			reference;
		typedef Iterator::iterator_category	iterator_category;
	};
	template <class T> class iterator_traits<const T*>{

};
}