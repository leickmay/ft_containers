#pragma once
#include <algorithm>
#include <iostream>

namespace ft 
{
	template <class Key, class T>
	class bst
	{
		public:
			typedef T		value_type;
			typedef Key		key_type;
			typedef size_t	size_type;

			struct node
			{
				key_type	key;
				value_type	data;
				node		*left;
				node		*right;
				node		*parent;
			};
			typedef node 	*node_ptr;

			bst() : _size(0), _root(NULL) {};
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
			node_ptr research(key_type key)
			{
				node_ptr tmp = _root;

				while (tmp != NULL) //tant qu'on a pas atteint les feuilles de l'arbre
				{
					if (key == tmp->key) //égalité -> on a trouvé notre élément
						return tmp; //du coup on le retourne
					else if (key < tmp->key)// < on va donc chercher dans le sous arbre gauche
						tmp = tmp->left;
					else // > on regarde donc de le sous arbre droit
						tmp = tmp->right;
				}
				return NULL; //on a pas trouvé l'élément -> return NULL
			}

			void insert(key_type key, value_type val)
			{
				//if (!_root)
				//	return ;
				node_ptr n = _new_node(key, val); //on crée le noeud
				node_ptr tmp = _root; //ptr tmp sur root
				node_ptr buf = NULL; //ptr buf qui représente le noeud parent de tmp
				//donc NULL car le parent de la racine est toujours NULL

				while (tmp != NULL) //on recherche l'endroit ou insérer le nouveau noeud
				{
					buf = tmp;
					if (n->key < tmp->key) //cherche à gauche
						tmp = tmp->left;
					else if (n->key > tmp->key) //à droite
						tmp = tmp->right;
					else //si on retrouve le noeud -> erreur, on ne fait rien
					{
						std::cout << "Error: node <"<< key << "> already exist!" << std::endl;
						delete n; //ne pas oublier de del le noeud créé
						return ;
					}
				}

				//si on a bien trouvé le ptr NULL où placer le nouveau noeud
				//on init tous ses ptrs
				n->parent = buf;
				if (buf == NULL)
					_root = n;
				else if (n->key < buf->key)
					buf->left = n;
				else
					buf->right = n;
				_size++; //size++ évidemment 
			}

			void	remove(key_type key)
			{
				if (!_root)
					return ;
				if (!research(key))
				{
					std::cout << "Error: node <"<< key << "> not exist!" << std::endl;
					return ;
				}
				_root = _deepRemove(_root, key);
			}

		private:
			node_ptr	_root;
			size_type	_size;

			node_ptr _new_node(key_type key, value_type val)
			{
				node_ptr ret = new node;

				ret->left = NULL;
				ret->right = NULL;
				ret->parent = NULL;
				ret->key = key;
				ret->data = val;

				return ret;
			} //fonction qui créée un noeud vierge, et init la key et la value

			node_ptr	_deepRemove(node_ptr root, key_type key)
			{
				if (key < root->key)
					root->left = _deepRemove(root->left, key);
				else if (key > root->key)
					root->right = _deepRemove(root->right, key);
				else
				{
					if (root->left == NULL)
					{
						node_ptr tmp = root->right;
						delete root;
						return tmp;
					}
					else if (root->right == NULL)
					{
						node_ptr tmp = root->left;
						delete root;
						return tmp;
					}
					node_ptr tmp = _min(root->right);

					root->key = tmp->key;
					root->data = tmp->data;

					root->right = _deepRemove(root->right, tmp->key);
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
/*************DEBUG**********/
				std::cout << root->data << std::endl;
				_deepPrint(root->left, indent, false);
				_deepPrint(root->right, indent, true);
			}
		}

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