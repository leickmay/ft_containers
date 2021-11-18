#pragma once

#include "iterator_traits.hpp"
#include "../tools/bst.hpp"

namespace ft{
	template < class T >
	class BstIterator{
		public:
		//typedef
			typedef T								value_type;
			typedef T*								node_ptr;
			typedef typename T::value_type			data;

			typedef data&							reference;
			typedef data*							pointer;

			typedef ptrdiff_t						difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;

			

		//constructors
			BstIterator():_it(NULL) {};
			BstIterator(node_ptr it):_it(it) {};
			~BstIterator() {};
			BstIterator (BstIterator const& other): _it(other._it) {};
			BstIterator &operator=(BstIterator const& other) {
				if (this != &other)
					_it = other._it;
				return *this; 
			};

		//Dereference
			reference operator*() {return _it->data;}
			pointer operator->() const {return &_it->data;}

		//Incrementation
			/*BstIterator	&operator++() {
				if (_it->right == NULL)
				{
					node_ptr tmp;
					tmp = _it;
					_it = _it->parent;
					while (_it->key < tmp->key)
						_it = _it->parent;
				}
				else
				{
					_it = _it->right;
					while(_it->left)
					_it = _it->left;
				}
				return *this;
			}*/
			/*BstIterator	operator++(int) {
				BstIterator ret(*this);
				_root = _root->right;
				while(_root->left)
					_root = _root->left;
				return ret;
			}
			BstIterator	&operator--() {
				if (_root->left)
					_root = _root->left;
				else
					_root = _root->parent;
				return *this;
			}
			BstIterator	operator--(int) {
				BstIterator ret(*this);
				if (_root->left)
					_root = _root->left;
				else
					_root = _root->parent;
				return ret;*/
		private:
			node_ptr _it;	
			

			//comparisons
			//bool					operator!=(BstIterator const& a){return (a._root != _root);};
			//bool					operator==(BstIterator const& a){return (a._root == _root);};

		
			
	};
}