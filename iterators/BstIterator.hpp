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
				{
					_it = other._it;
				}
				return *this; 
			};

		//Dereference
			reference operator*() {return _it->data;}
			pointer operator->() const {return &_it->data;}

		//Incrementation
			BstIterator &operator++()
			{
				if (_it != NULL)
					_it = _findNext();
				return *this;
			}

			BstIterator operator++(int)
			{
				BstIterator tmp(*this);
				++(*this);
				return tmp;
			}

			BstIterator &operator--()
			{
				if (_it != NULL)
					_it = _findPrev();
				else
				{
					while (_it->parent)
						_it = _it->parent;
					_it = _findMax(_it);
				}
				return *this;
			}
	
			BstIterator operator--(int)
			{
				BstIterator tmp(*this);
				--(*this);
				return tmp;
			}

		//Comparisons
			bool					operator!=(BstIterator const& a){return (a._it != _it);};
			bool					operator==(BstIterator const& a){return (a._it == _it);};

		//Getter

			node_ptr getCurrent () const { return _it; }

		private:
			node_ptr _it;

			node_ptr _findMin(node_ptr n)
			{
				while (n->left)
					n = n->left;
				return n;
			}

			node_ptr _findMax(node_ptr n)
			{
				while (n->right)
					n = n->right;
				return n;
			}

			node_ptr _findNext()
			{
				node_ptr n = _it;
				node_ptr next = NULL;

				if (n->right != NULL)
					return _findMin(n->right);
				
				next = n->parent;
				while (next != NULL && n == next->right)
				{
					n = next;
					next = next->parent;
				}
				return next;
			}

			node_ptr _findPrev()
			{
				node_ptr n = _it;
				node_ptr prev = NULL;

				if (n->left != NULL)
					return _findMax(n->left);
				
				prev = n->parent;
				while (prev != NULL && n == prev->left)
				{
					n = prev;
					prev = prev->parent;
				}
				return prev;
			}

	};
}