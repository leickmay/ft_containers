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
			node_ptr research(value_type val)
			{
				node_ptr tmp = _root;

				while (tmp != NULL && tmp != _last) //tant qu'on a pas atteint les feuilles de l'arbre
				{
					if (val->first == tmp->data.first) //égalité -> on a trouvé notre élément
						return tmp; //du coup on le retourne
					else if (val->first < tmp->data.first)// < on va donc chercher dans le sous arbre gauche
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
				node_ptr n = _new_node(val); //on crée le noeud
				node_ptr tmp = _root; //ptr tmp sur root
				node_ptr buf = NULL; //ptr buf qui représente le noeud parent de tmp
				//donc NULL car le parent de la racine est toujours NULL

				while (tmp != NULL && tmp != _last) //on recherche l'endroit ou insérer le nouveau noeud
				{
					buf = tmp;
					if (n->data.first < tmp->data.first) //cherche à gauche
						tmp = tmp->left;
					else if (n->data.first > tmp->data.first) //à droite
						tmp = tmp->right;
					else //si on retrouve le noeud -> erreur, on ne fait rien
					{
						delete n; //ne pas oublier de del le noeud créé
						return ft::make_pair<iterator, bool>(tmp, false);
					}
				}

				//si on a bien trouvé le ptr NULL où placer le nouveau noeud
				//on init tous ses ptrs
				n->parent = buf;
				if (buf == NULL)
				{
					_root = n;
					n->right = _last;
					_last->parent = n;
				}
				else if (n->data.first < buf->data.first)
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

			void	remove(value_type val)
			{
				if (!_root)
					return ;
				if (!research(val->first))
				{
					std::cout << "Error: node <"<< val->first << "> not exist!" << std::endl;
					return ;
				}
				_root = _deepRemove(_root, val->first);
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
				if (val->first < root->val->first)
					root->left = _deepRemove(root->left, val);
				else if (val->first > root->val->first)
					root->right = _deepRemove(root->right, val);
				else
				{
					if (root->left == NULL)
					{
						node_ptr tmp = root->right;
						_alloc.deallocate(root, 1);
						//delete root;
						return tmp;
					}
					else if (root->right == NULL)
					{
						node_ptr tmp = root->left;
						_alloc.deallocate(root, 1);
						//delete root;
						return tmp;
					}
					node_ptr tmp = _min(root->right);

					root->data = tmp->val;

					root->right = _deepRemove(root->right, val);
				}
				_size--;
				return _root;
			}

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
			if (root != NULL)
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

				std::cout << root->data << std::endl;
				_deepPrint(root->left, indent, false);
				_deepPrint(root->right, indent, true);
			}
		}

/*************DEBUG**********/

			void		_deepClear(node_ptr root)
			{
				if (!root)
					return ;
				_deepClear(root->left);
				_deepClear(root->right);
				delete root;
			}
	};
}