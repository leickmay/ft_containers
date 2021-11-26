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
	template < class T>
	struct node
	{
		typedef T	value_type;

		value_type	data;
		node		*left;
		node		*right;
		node		*parent;

		node(value_type const &src) : data(src){}
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
				_last = _last_node();
			};

			~bst()
			{
				if (_root)
					_deepClear(_root);
				
			}
		/*************DEBUG**********/
		void print()
		{
			if (_root != NULL)
				_deepPrint(_root, "", true);
			std::cout << "size : " << _size << std::endl;
		}
		/*************DEBUG**********/
		iterator begin() {
			if (!_root)
				return _last;
			node_ptr tmp = _root;
			while (tmp->left)
				tmp = tmp->left;
			return tmp;
		}

		iterator end() {
			return _last;
		}

		bool empty() const {return (_size == 0);}
		size_type size() const {return _size;}
		size_type	max_size() const {return _alloc.max_size();}

		//node_ptr root() {return _root;}
			node_ptr research(value_type const& val) const
			{
				node_ptr tmp = _root;

				while (tmp != NULL && tmp != _last) //tant qu'on a pas atteint les feuilles de l'arbre
				{
					if (val.first == tmp->data.first) //égalité -> on a trouvé notre élément
						return tmp; //du coup on le retourne
					else if (_comp(val.first, tmp->data.first))// < on va donc chercher dans le sous arbre gauche
						tmp = tmp->left;
					else // > on regarde donc de le sous arbre droit
						tmp = tmp->right;
				}
				return NULL; //on a pas trouvé l'élément -> return NULL
			}

			ft::pair<iterator, bool> insert(value_type val)
			{
				//if (!_root)
				//	return ;
				//node_ptr n = _new_node(val); //on crée le noeud
				node_ptr tmp = _root; //ptr tmp sur root
				node_ptr buf = NULL; //ptr buf qui représente le noeud parent de tmp
				//donc NULL car le parent de la racine est toujours NULL

				while (tmp != NULL && tmp != _last) //on recherche l'endroit ou insérer le nouveau noeud
				{
					buf = tmp;
					//if (n->data.first < tmp->data.first) //cherche à gauche
					if (_comp(val.first, tmp->data.first))
						tmp = tmp->left;
					//else if (n->data.first > tmp->data.first) //à droite
					else if (_comp(tmp->data.first, val.first))
						tmp = tmp->right;
					else //si on retrouve le noeud -> erreur, on ne fait rien
					{
						//delete n; //ne pas oublier de del le noeud créé
						//_alloc.destroy(n);
						//_alloc.deallocate(n, 1);
						return ft::make_pair<iterator, bool>(tmp, false);
					}
				}

				//si on a bien trouvé le ptr NULL où placer le nouveau noeud
				//on init tous ses ptrs
				node_ptr n = _new_node(val);
				n->parent = buf;
				if (buf == NULL)
				{
					_root = n;
					n->right = _last;
					_last->parent = n;
				}
				//else if (n->data.first < buf->data.first)
				else if (_comp(n->data.first, buf->data.first))
					buf->left = n;
				else
					buf->right = n;
				_size++; //size++ évidemment
				if (tmp == _last)
				{
					n->right = _last;
					_last->parent = n;
				}
				//_set_last();
				return ft::make_pair<iterator, bool>(n, true);
			}

			iterator insert (iterator position, const value_type& val){
				node_ptr next = _findNext(position.getCurrent());
				if (_comp(position.getCurrent()->data.first, val.first) && _comp(val.first, next->data.first))
				{
					ft::pair<iterator, bool> r = _rootInsert(val, position.getCurrent());
					_size++;
					return r.first;
				}
				else
					return insert(val).first;
			}

			//void erase (iterator position){
			//	node_ptr next = _findNext(position.getCurrent());
			//}


			void	remove(value_type val)
			{
				if (!_root)
					return ;
				if (!research(val))
					return ;
				print();
				_deepRemove2(_root, val);
			}

node_ptr	_deepRemove2(node_ptr root, value_type val)//⚠️ fonction récursive
{
		if (root == NULL) return root;
		//Chercher le noeud à supprimer
		if (val.first < root->data.first)
			root->left = _deepRemove(root->left, val);
		else if (val.first > root->data.first)
			root->right = _deepRemove(root->right, val);
		else
		{
			//CAS 1 et 2 - si le noeud a zero ou un enfant
			//Faire l'échange de contenu et le supprimer
			if (root->left == NULL)
			{
				node_ptr temp = root->right;
				//std::cout << "boucle\n";
				delete root;

				return temp;
			}
			else if (root->right == NULL)
			{
				node_ptr temp = root->left;
				//std::cout << "boucle\n";
				delete root;
				return temp;
			}
			//CAS 3 - si le noeud a deux enfants
			//Faire l'échange avec le noeud minimum du sous arbre droit
			node_ptr temp = _min(root->right);

			_alloc.destroy(root);
			_alloc.construct(root, temp->data);
			//root->data.first = temp->data.first;
			//root->data.second = temp->data.second;
				
			//Enfin supprimer le minimum de l'arbre droit
			root->right = _deepRemove(root->right, temp->data);
			
		}
		_size--; //attention à bien décrémenter la size
		node_ptr max = _max(_root);
		max->right = _last;
		_last->parent = max;
		return root;
}

			size_type erase(value_type const &k)
			{
				node_ptr tmp = research(k);

				if (tmp)
					_root = _deepRemove2(_root, k);
				else
					return 0;
				return 1;
			}

			//size_type erase (value_type k){
			//	std::cout << "coucou key : " << k.first << std::endl;
			//}


			void swap (bst& x){
				node_ptr		tmp_root = _root;
				node_ptr		tmp_last = _last;
				size_type		tmp_size = _size;
				allocator_type	tmp_alloc = _alloc;
				key_compare		tmp_comp = _comp;

				_root = x._root;
				_last = x._last;
				_size = x._size;
				_alloc = x._alloc;
				_comp = x._comp;

				x._root = tmp_root;
				x._last = tmp_last;
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
			node_ptr		_last;
			size_type		_size;
			allocator_type	_alloc;
			key_compare		_comp;


			node_ptr	_find_max()
			{
				node_ptr tmp = _root;
				while (tmp != NULL && tmp != _last)
					tmp = tmp->right;
				return tmp;
			}

			void		_set_last()
			{
				node_ptr max = _find_max();
				max->right = _last;
				_last->parent = max;
			}

			ft::pair<iterator, bool> _rootInsert(value_type val, node_ptr root)
			{
				//if (!_root)
				//	return ;
				//node_ptr n = _new_node(val); //on crée le noeud
				node_ptr tmp = root; //ptr tmp sur root
				node_ptr buf = NULL; //ptr buf qui représente le noeud parent de tmp
				//donc NULL car le parent de la racine est toujours NULL

				while (tmp != NULL && tmp != _last) //on recherche l'endroit ou insérer le nouveau noeud
				{
					buf = tmp;
					//if (n->data.first < tmp->data.first) //cherche à gauche
					if (_comp(val.first, tmp->data.first))
						tmp = tmp->left;
					//else if (n->data.first > tmp->data.first) //à droite
					else if (_comp(tmp->data.first, val.first))
						tmp = tmp->right;
					else //si on retrouve le noeud -> erreur, on ne fait rien
					{
						//delete n; //ne pas oublier de del le noeud créé
						return ft::make_pair<iterator, bool>(tmp, false);
					}
				}
				node_ptr n = _new_node(val);
				//si on a bien trouvé le ptr NULL où placer le nouveau noeud
				//on init tous ses ptrs
				n->parent = buf;
				if (buf == NULL)
				{
					_root = n;
					n->right = _last;
					_last->parent = n;
				}
				//else if (n->data.first < buf->data.first)
				else if (_comp(n->data.first, buf->data.first))
					buf->left = n;
				else
					buf->right = n;
				_size++; //size++ évidemment
				if (tmp == _last)
				{
					n->right = _last;
					_last->parent = n;
				}
				return ft::make_pair<iterator, bool>(n, true);
			}

			node_ptr _new_node(const value_type &val)
			{
				node_ptr ret = _alloc.allocate(1);
				_alloc.construct(ret, val);
				ret->left = NULL;
				ret->right = NULL;
				ret->parent = NULL;

				return ret;
			} //fonction qui créée un noeud vierge, et init la key et la value

			node_ptr _last_node()
			{
				node_ptr ret = _alloc.allocate(1);
				ret->left = NULL;
				ret->right = NULL;
				ret->parent = NULL;

				return ret;
			}
			node_ptr	_deepRemove(node_ptr root, value_type val)
			{
				if (_comp(val.first,root->data.first))
					root->left = _deepRemove(root->left, val);
				else if (_comp(root->data.first, val.first))
					root->right = _deepRemove(root->right, val);
				else
				{
					if (root->left == NULL)
					{
						node_ptr tmp = root->right;
						_alloc.destroy(root);
						_alloc.deallocate(root, 1);
						//delete root;
						return tmp;
					}
					else if (root->right == NULL)
					{
						node_ptr tmp = root->left;
						_alloc.destroy(root);
						_alloc.deallocate(root, 1);
						//delete root;
						return tmp;
					}
					node_ptr tmp = _min(root->right);

					//root->data.first = tmp->data.first;
					//root->data.second = tmp->data.second;
					//root->data = tmp->data;
					node_ptr t = _new_node(tmp->data);
					t->parent = root->parent;
					t->left = root->left;
					t->right = root->right;
					_alloc.deallocate(root, 1);

					t->right = _deepRemove(t->right, val);
				}
				_size--;
				return _root;
			}

		/*node_ptr _find(value_type const &val) const
		{
			node_ptr tmp = _root;
			while (tmp != NULL && tmp != _last)
			{
				if (_comp(val.first, tmp->data.first))
					tmp = tmp->left;
				else if (_comp(tmp->data.first, val.first))
					tmp = tmp->right;
				else
					return tmp;
			}
			return NULL;
		}*/

			node_ptr	_min(node_ptr root)
			{
				while (root->left != NULL)
					root = root->left;
				return root;
			}

			node_ptr	_max(node_ptr root)
			{
				while (root->right && root->right != _last)
					root = root->right;
				return root;
			}
			/*************DEBUG**********/
		void	_deepPrint(node_ptr root, std::string indent, bool last)
		{
			if (root != NULL && root != _last)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}

				std::cout << root->data.second << std::endl;
				_deepPrint(root->left, indent, false);
				_deepPrint(root->right, indent, true);
			}
			if (root == _last)
				std::cout << indent << " === LAST === " << std::endl;
		}

/*************DEBUG**********/

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
				//node_ptr n = _it;
				node_ptr next = NULL;

				if (n->right != NULL && n->right != _last)
					return _min(n->right);
				
				next = n->parent;
				while (next != NULL && n == next->right)
				{
					n = next;
					next = next->parent;
				}
				return next;
			}

			/*node_ptr _findPrev()
			{
				node_ptr n = _it;
				node_ptr prev = NULL;

				if (n->left != NULL)
					return _max(n->left);
				
				prev = n->parent;
				while (prev != NULL && n == prev->left)
				{
					n = prev;
					prev = prev->parent;
				}
				return prev;
			}*/
	};
}