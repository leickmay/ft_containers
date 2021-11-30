#pragma once
#include <algorithm>
#include <iostream>
#include "pair.hpp"
#include "../iterators/BstIterator.hpp"
#include "../iterators/ReverseIterator.hpp"
#include "../tools/type_traits.hpp"
#include "../tools/tools.hpp"

namespace ft 
{
	template < class T >
	struct node
	{
		typedef T	value_type;

		value_type	data;
		node		*left;
		node		*right;
		node		*parent;

		node(value_type const &src) : data(src){}
		node(value_type const &src, node *l, node *r, node *p) : data(src), left(l), right(r), parent(p) {}
		node(node *l, node *r, node *p) : left(l), right(r), parent(p) {}
	};


	template <class T, class Compare, class Alloc = std::allocator<node<T> > >
	class bst
	{
		public:
			typedef T		value_type;
			typedef Compare	key_compare;
			typedef Alloc	allocator_type;

			typedef size_t	size_type;

			typedef node<value_type>	node;
			typedef node				*node_ptr;

			typedef ft::BstIterator<node>							iterator;
			typedef ft::BstIterator<node>							const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;


			bst(const key_compare& comp = key_compare(), 
			const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp){
				_size = 0;
				_root = NULL;
			};

			bst(bst const& copy)
			{
				_alloc = copy._alloc;
				_comp = copy._comp;
				_size = copy._size;
				_deepCopy(*this, copy._root);
			}

			bst operator=(bst const& copy)
			{
				if (this != &copy)
				{
					_alloc = copy._alloc;
					_comp = copy._comp;
					_size = copy._size;
					_deepCopy(*this, copy._root);
				}
				return *this;
			}

			~bst()
			{
				if (_root)
					_deepClear(_root);
				
			}

		iterator begin() {
			if (!_root)
				return end();
			return iterator(_min(_root), _root);
		}

		iterator end() {
			return iterator(NULL, _root);
		}

		bool empty() const {return (_size == 0);}
		size_type size() const {return _size;}
		size_type	max_size() const {return _alloc.max_size();}

			node_ptr research(value_type const& val) const
			{
				node_ptr tmp = _root;

				while (tmp != NULL)
				{
					if (val.first == tmp->data.first)
						return tmp;
					else if (_comp(val.first, tmp->data.first))
						tmp = tmp->left;
					else 
						tmp = tmp->right;
				}
				return NULL;
			}

			ft::pair<iterator, bool> insert(value_type val, node_ptr root)
			{
				node_ptr tmp = root;
				node_ptr buf = NULL;

				while (tmp != NULL)
				{
					buf = tmp;
					if (_comp(val.first, tmp->data.first))
						tmp = tmp->left;
					else if (_comp(tmp->data.first, val.first))
						tmp = tmp->right;
					else
						return ft::make_pair<iterator, bool>(iterator(tmp, _root), false);

				}
				node_ptr n = _new_node(val);
				n->parent = buf;
				if (buf == NULL)
				{
					_root = n;
					_root->parent = NULL;
				}
				else if (_comp(n->data.first, buf->data.first))
					buf->left = n;
				else
					buf->right = n;
				_size++;

				return ft::make_pair<iterator, bool>(iterator(n, _root), true);
			}

			iterator insert (iterator position, const value_type& val){
				node_ptr next = _findNext(position.getCurrent());
				if (_comp(position.getCurrent()->data.first, val.first) && _comp(val.first, next->data.first))
				{
					ft::pair<iterator, bool> r = insert(val, position.getCurrent());
					_size++;
					return r.first;
				}
				else
					return insert(val, _root).first;
			}

			void	erase(value_type val)
			{
				if (!_root)
					return ;
				node_ptr tmp = research(val);
				if (!tmp)
					return ;
				_deepRemove(tmp);
			}

			size_type remove(value_type const &k)
			{
				node_ptr tmp = research(k);

				if (tmp)
					_deepRemove(tmp);
				else
					return 0;
				return 1;
			}

			void swap (bst& x){
				node_ptr		tmp_root = _root;
				size_type		tmp_size = _size;
				allocator_type	tmp_alloc = _alloc;
				key_compare		tmp_comp = _comp;

				_root = x._root;
				_size = x._size;
				_alloc = x._alloc;
				_comp = x._comp;

				x._root = tmp_root;
				x._size = tmp_size;
				x._alloc = tmp_alloc;
				x._comp = tmp_comp;
			}

			size_type count (const value_type& val) const
			{
				if (research(val))
					return 1;
				return 0;
			}

		iterator lower_bound(const value_type &k)
		{
			iterator it = begin();
			node_ptr tmp;

			while (it != end())
			{
				tmp = it.getCurrent();
				if (_comp(k, tmp->data) || (!_comp(k, tmp->data) && !_comp(tmp->data, k)))
					return it;
				it++;
			}
			return it;
		}

		const_iterator lower_bound(const value_type &k) const
		{
			iterator it = begin();
			node_ptr tmp;

			while (it != end())
			{
				tmp = it.getCurrent();
				if (_comp(k, tmp->data) || (!_comp(k, tmp->data) && !_comp(tmp->data, k)))
					return it;
				it++;
			}
			return it;
		}

		iterator upper_bound(const value_type &k)
		{
			iterator it = begin();
			node_ptr tmp;

			while (it != end())
			{
				tmp = it.getCurrent();
				if (_comp(k, tmp->data))
					return it;
				it++;
			}
			return it;
		}

		const_iterator upper_bound(const value_type &k) const
		{
			iterator it = begin();
			node_ptr tmp;

			while (it != end())
			{
				tmp = it.getCurrent();
				if (_comp(k, tmp->data))
					return it;
				it++;
			}
			return it;
		}

			//Getters
			node_ptr	getRoot() const {return _root;}
			size_type	getSize() const {return _size;}

		private:
			node_ptr		_root;
			size_type		_size;
			allocator_type	_alloc;
			key_compare		_comp;


			void	_deepCopy(bst &dest, node_ptr croot)
			{
				if (croot != NULL)
				{
					_deepCopy(dest, croot->left);
					dest.insert(croot->data, _root);
					_deepCopy(dest, croot->right);
				}
			}

			node_ptr _new_node(const value_type &val)
			{
				node_ptr ret = _alloc.allocate(1);
				_alloc.construct(ret, val);
				ret->left = NULL;
				ret->right = NULL;
				ret->parent = NULL;

				return ret;
			}

			void _invert(node_ptr old, node_ptr latest)
			{
				if (old->parent == NULL)
					_root = latest;
				else if (old == old->parent->left)
					old->parent->left = latest;
				else
					old->parent->right = latest;
				latest->parent = old->parent;
			}

			void _deepRemove(node_ptr z)
			{
				node_ptr y = z;
				node_ptr x;

				if (z->left == NULL)
				{
					x = z->right;
					_invert(z, z->right);
				}
				else if (z->right == NULL)
				{
					x = z->left;
					_invert(z, z->left);
				}
				else
				{
					y = _min(z->right);
					x = y->right;
					if (y->parent == z)
						x->parent = y;
					else
					{
						_invert(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					_invert(z, y);
					y->left = z->left;
					y->left->parent = y;
				}
				_alloc.destroy(z);
				_alloc.deallocate(z, 1);
				_size--;
			}

			node_ptr	_min(node_ptr root)
			{
				while (root->left != NULL)
					root = root->left;
				return root;
			}

			void		_deepClear(node_ptr root)
			{
				if (!root)
					return ;
				_deepClear(root->left);
				_deepClear(root->right);
				_alloc.destroy(root);
				_alloc.deallocate(root, 1);
			}

			node_ptr _findNext(node_ptr n)
			{
				node_ptr next = NULL;

				if (n->right != NULL)
					return _min(n->right);

				next = n->parent;
				while (next != NULL && n == next->right)
				{
					n = next;
					next = next->parent;
				}
				return next;
			}
	};
}