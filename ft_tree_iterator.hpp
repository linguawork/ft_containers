/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:17:18 by areggie           #+#    #+#             */
/*   Updated: 2022/06/14 20:08:56 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_ITERATOR_HPP
# define FT_TREE_ITERATOR_HPP// need to have a gap


//https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators

/*
A red black iterator's pseudocode is explained by Rob Edwards:
https://www.youtube.com/watch?v=-qjrcxVmf2Q (Lecture 1)

this is the description what Bidirectional iterator should do:
https://cplusplus.com/reference/iterator/
https://cplusplus.com/reference/iterator/BidirectionalIterator/


good article about implementing a tree iterator (“in-order” traversal)
https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html
*/



//declaring struct NODE with a template class just like Rob taught
template<class Value>
struct Node
{

	public:
	// default constructor 
	explicit Node(Value *srcval = 0) :	value(srcval),
										parent(0),
										left(0),
										right(0),
										is_black(false), // by default is fault
										is_nil(0){}

	Value	*value; // ptr to template
	Node*	parent; // P node ptr
	Node*	left;
	Node*	right;
	bool	is_black;
	bool	is_nil;

// copy constructor
	Node( Node const & other)
	{
		this->is_black = other.is_black;
		this->value = other.value;
		this->parent = other.parent;
		this->is_nil = other.is_nil;
		this->right = other.right;
		this->left = other.left;
	};

// assign operator
	Node& operator=(const Node& other)
	{
		this->is_black = other.is_black;
		this->value = other.value;
		this->is_nil = other.is_nil;
		this->parent = other.parent;
		this->right = other.right;
		this->left = other.left;
		return *this;
	}
	//virtual distructor
	virtual ~Node()
	{
		
	}
};


//tree iterator with template, it runs bidirectional iterator
template<typename T>
class TreeIter
{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef typename ft::iterator_traits<T*>::value_type 		value_type;
		typedef typename ft::iterator_traits<T*>::reference 		reference;
		typedef typename ft::iterator_traits<T*>::pointer			pointer;
		typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
		//here we use Node struct as node ptr
		typedef Node<typename ft::off_const<value_type>::type >* node_pointer;
		//off_const makes incoming const just a type, which is defined as node_ptr

	private:
		node_pointer _node; // making a node ptr 

		//min element in the node family triangle which is the left element
		node_pointer tree_min(node_pointer n) const 
		{
			while(n->left != NULL && !n->left->is_nil) // no left and left has no NULL node
				n = n->left; // then n will become Left element
			return n;
		}

		node_pointer tree_max(node_pointer n) const // the right elem is bigger than the left
		{
			while (!n->right->is_nil) // while there is no right node in the family triangle and no null node
				n = n->right; // n becomes RIGHT (MAХ)
			return n;
		}

	public:
		TreeIter() 
		{
			
		}

		// init with the value of the NODE struct (static cast)	
		TreeIter(void *node): _node(static_cast<node_pointer>(node))  
		{
			
		}
		
		//copy constructor
		TreeIter(const TreeIter<typename ft::off_const<value_type>::type > & other)
		{
			*this = other;
		}

		TreeIter& operator=(const TreeIter<typename ft::off_const<value_type>::type>& other)
		{
			this->_node = other.node();
			return *this;
		}

		reference operator*() const
		{
			return *(_node->value);
		}

		pointer operator->() const
		{
			return _node->value;
		}

		TreeIter& operator++()
		{
			if (_node->right && !_node->right->is_nil)
			{
				_node = tree_min(_node->right);
			}
			else
			{
				node_pointer y = _node->parent;
				while (y != NULL && _node == y->right)
				{
					_node = y;
					y = y->parent;
				}
				_node = y;
			}
			return *this;
		}

		TreeIter operator++(int)
		{
			TreeIter<value_type> temp = *this; //tmp
			if (!_node->right->is_nil)
			{
				_node = tree_min(_node->right);
			}
			else
			{
				node_pointer y = _node->parent; //like tmp ptr
				while (y != NULL && _node == y->right) //  changing parents
				{
					_node = y;
					y = y->parent;
				}
				_node = y;
			}
			return temp;
		}

		TreeIter& operator--()
		{
			if (_node->left && !_node->left->is_nil)
			{
				_node = tree_max(_node->left);
			}
			else
			{
				node_pointer y = _node->parent;
				while (y != NULL && _node == y->left)
				{
					_node = y;
					y = y->parent;
				}
				_node = y;
			}
			return *this;
		}

		TreeIter operator--(int)
		{
			TreeIter<value_type> temp = *this;
			if (_node->left && !_node->left->is_nil)
			{
				_node = tree_max(_node->left);
			}
			else
			{
				node_pointer y = _node->parent;
				while (y != NULL && _node == y->left)
				{
					_node = y;
					y = y->parent;
				}
				_node = y;
			}
			return temp;
		}

		node_pointer node() const
		{
			return _node;
		}
	};

template<typename A, typename B>
bool operator==(const TreeIter<A> & lhs, const TreeIter<B> & rhs)
{
	return (lhs.node() == rhs.node());
}

template<typename A, typename B>
bool operator!=(const TreeIter<A> & lhs, const TreeIter<B> & rhs)
{
	return (lhs.node() != rhs.node());
}


#endif