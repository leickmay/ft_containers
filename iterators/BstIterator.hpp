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
			typedef std::random_access_iterator_tag	iterator_category;

		//constructors
			BstIterator():_root(NULL) {};
			BstIterator(node_ptr ptr):_root(root) {};
			~BstIterator() {};
			BstIterator (BstIterator const& other): _root(other._root) {};
			BstIterator &operator=(BstIterator const& other) {
				if (this != &other)
					_ptr = other._root;
				return *this; 
			};

		//Dereference
			reference operator*() {return *_root;}
			pointer operator->() const {return &(operator*());}

		//Incrementation
			BstIterator	&operator++() {
				if (_root->right)
					_root = _root->right;
				while(_root->left)
					_root = _root->left;
				return *this;
			}
			BstIterator	operator++(int) {
				BstIterator ret(*this);
				if (_root->right)
					_root = _root->right;
				while(_root->left)
					_root = _root->left;
				return ret;
			}
			BstIterator	&operator--() {
				if (_root->left)
					_root = _root->left;
				else if (_root->parent)
					_root = _root->parent;
				return *this;
			}
			BstIterator	operator--(int) {
				BstIterator ret(*this);
				if (_root->left)
					_root = _root->left;
				else if (_root->parent)
					_root = _root->parent;
				return ret;
			}

			//comparisons
			bool					operator!=(BstIterator const& a){return (a._root != _root);}
			bool					operator==(BstIterator const& a){return (a._root == _root);}

		private:
			node_ptr _root;
			
	};
}