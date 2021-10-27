#pragma once

#include "iterator_traits.hpp"

namespace ft{
	template <class Iterator> 
	class reverse_iterator{
		public:
			//typedef
			typedef Iterator										iterator_type;
			typedef iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef iterator_traits<Iterator>::value_type			value_type;
			typedef iterator_traits<Iterator>::difference_type		difference_type;
			typedef iterator_traits<Iterator>::pointer				pointer;
			typedef iterator_traits<Iterator>::reference			reference;

			//default (1)	
		reverse_iterator();
		//initialization (2)	
		explicit reverse_iterator (iterator_type it);
		//copy (3)	
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it);
	};
}