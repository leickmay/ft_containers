#pragma once

#include "iterator_traits.hpp"
#include "../tools/bst.hpp"

namespace ft{
	template < class Key, class T >
	class BstIterator{
		public:
		//typedef
			typedef typename ft::bst<Key, T>::node		node;
			typedef *node						node_ptr;
			//typedef T								value_type;
			//typedef T*								node_ptr;
			//typedef typename T::value_type			data;

			//typedef data&							reference;
			//typedef data*							pointer;

			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

			

		//constructors
			BstIterator():_root(NULL) {};
			BstIterator(node_ptr root):_root(root) {};
			~BstIterator() {};
			BstIterator (BstIterator const& other): _root(other._root) {};
			BstIterator &operator=(BstIterator const& other) {
				if (this != &other)
					_root = other._root;
				return *this; 
			};

		//Dereference
			reference operator*() {return *_root;}
			pointer operator->() const {return &(operator*());}

		//Incrementation
			BstIterator	&operator++() {
				if (_root->right == NULL)
				{
					node_ptr tmp;
					tmp = _root;
					_root = _root->parent;
					while (_root->key < tmp->key)
						_root = _root->parent;
				}
				else
				{
					_root = _root->right;
					while(_root->left)
					_root = _root->left;
				}
				return *this;
			}
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
			node_ptr _root;	
			

			//comparisons
			//bool					operator!=(BstIterator const& a){return (a._root != _root);};
			//bool					operator==(BstIterator const& a){return (a._root == _root);};

		
			
	};
}