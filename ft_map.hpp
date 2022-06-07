/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:38:32 by areggie           #+#    #+#             */
/*   Updated: 2022/06/07 17:46:31 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP// need to have a gap

#include "ft_redblacktree.hpp"
#include "ft_utility.hpp"

namespace ft
{

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >

	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef pair<const Key, T> value_type;
		typedef Allocator allocator_type;
		typedef const value_type & reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

	private:
		class pair_compare
		{
			key_compare _compare;

			public:
				pair_compare(const key_compare & compare) : _compare(compare) 
				{
					
				}

				bool operator()(const value_type & x, const value_type & y) const
				{
					return (_compare(x.first, y.first));
				}
		};
	public:
		typedef pair_compare value_compare;
		typedef RBTree<value_type, pair_compare, allocator_type> tree_type; // using RBT
		typedef typename tree_type::iterator				iterator;
		typedef typename tree_type::const_iterator			const_iterator;
		typedef typename tree_type::reverse_iterator		reverse_iterator; // using reverse iter from RBT=tree type
		typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;

	private:
		allocator_type	_alloc;
		tree_type		_tree;
		key_compare		_compare;

	public:

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _tree(tree_type(comp, alloc)), _compare(comp) {}

		template< class InputIt >
		map(InputIt first, InputIt last, const Compare& compare = Compare(), const Allocator& alloc = Allocator()):
			_alloc(alloc), _tree(first, last, compare, _alloc), _compare(compare) {}



		//https://m.cplusplus.com/reference/map/map/get_allocator/
		allocator_type get_allocator() const
		{
			return (_tree.get_allocator());
		}
		
		/***************MAP CAPACITY methods************/
		
		//https://m.cplusplus.com/reference/map/map/size/
		size_type size() const
		{
			return (_tree.size());
		}

		size_type max_size() const
		//https://m.cplusplus.com/reference/map/map/max_size/
		{
			return (_tree.max_size());
		}

		bool empty() const
		//https://m.cplusplus.com/reference/map/map/empty/
		{
			return (_tree.empty());
		}
		
		/***************MAP ELEMENT ACCESS methods************/
		
		//https://m.cplusplus.com/reference/map/map/operator[]/
		mapped_type& operator[](const key_type& key)
		{
			return (*((this->insert(ft::make_pair(key,mapped_type()))).first)).second;
		}


		


		iterator begin()
		{
			return (_tree.begin());
		}

		iterator end()
		{
			return (_tree.end());
		}

		reverse_iterator rbegin()
		{
			return(_tree.rbegin());
		}

		reverse_iterator rend()
		{
			return(_tree.rend());
		}

		/*
        Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
      	*/
      	//https://m.cplusplus.com/reference/map/map/clear/
		void clear()
		{
			_tree.clear(); //method of RBT
		}

		//https://m.cplusplus.com/reference/map/map/insert/
		/*
		 The single element versions (1) return a pair, 
		 with its member pair::first set to an iterator pointing to either the newly inserted element or
		 to the element with an equivalent key in the map. 
		 The pair::second element in the pair is set to true 
		 if a new element was inserted or false if an equivalent key already existed
		*/
		pair<iterator, bool> insert(const value_type& value)
		{
			return (_tree.insert(value));
		}

		/*
			The versions with a hint (2) return an iterator 
			pointing to either the newly inserted element or 
			to the element that already had an equivalent key in the map.
		*/
		iterator insert(iterator pos, const value_type& value)
		{
			return (_tree.insert(pos, value));
		}

		/*
			Member type iterator is a bidirectional iterator type that points to elements.
			pair is a class template declared in <utility> (see pair).
		*/
		template<class InputIt>
		void insert(typename enable_if< !is_integral<InputIt>::value, InputIt >::type first, InputIt last)
		{
			_tree.insert(first, last);
		}
		
		//https://m.cplusplus.com/reference/map/map/erase/
		void erase(iterator iter_pos)  // 1 case: erase where by iter position
		{
			_tree.erase(iter_pos);
		}

		size_type erase(const Key& key) // erasing a key
		{
			return (_tree.erase(make_pair(key, mapped_type())));
		}

		void erase(iterator first, iterator last) // erasing range
		{
			_tree.erase(first, last);
		}

		iterator	find(const Key& key)
		{
			return _tree.find(ft::make_pair(key, mapped_type())); // it was ambiguous in range constructor of ft_map, so added ft::
		}

		size_type count( const Key& key ) const
		{
			return (_tree.count(ft::make_pair(key, mapped_type())));
		}
		
		//https://m.cplusplus.com/reference/map/map/swap/
		void swap(map & other)
		{
			std::swap(this->_compare, other._compare);
			_tree.swap(other._tree);
		}

		/***************MAP OBSERVERS methods************/
		//https://m.cplusplus.com/reference/map/map/key_comp/
		/*
			Returns a copy of the comparison object used by the container to compare keys.
		*/
		// https://www.cplusplus.com/reference/functional/less/
		/*
			Binary function object class 
			whose call returns whether its first argument compares less 
			than the second (as returned by operator <).

			Generically, function objects are instances of a class with member function operator() defined. 
			This member function allows the object to be used with the same syntax as a function call
		*/
	
		key_compare key_comp() const
		{
			return (_compare); // returns whether its first argument compares less than the second
		}
		
		value_compare value_comp() const
		{
			return (_tree.value_comp());
		}


		
		iterator lower_bound(const key_type& key)
		{
			return (_tree.lower_bound(make_pair(key, mapped_type())));
		}

		const_iterator lower_bound(const key_type& key) const
		{
			return (_tree.lower_bound(make_pair(key, mapped_type())));
		}

		iterator upper_bound(const key_type& key)
		{
			return (_tree.upper_bound(make_pair(key, mapped_type())));
		}

		const_iterator upper_bound(const key_type& key) const
		{
			return (_tree.upper_bound(make_pair(key, mapped_type())));
		}

		pair<iterator, iterator> equal_range(const key_type & key)
		{
			return (_tree.equal_range(make_pair(key, mapped_type())));
		}

		pair<const_iterator, const_iterator> equal_range(const key_type & key) const
		{
			return (_tree.equal_range(make_pair(key, mapped_type())));
		}

		//https://www.cplusplus.com/reference/vector/vector/at/
		T& at(const Key &key)
		{
			iterator res = _tree.find(ft::make_pair(key, mapped_type()));
			if (res == _tree.end())
				throw std::out_of_range("map::at: key not found");
			return (res->second);
		}
		//https://m.cplusplus.com/reference/map/map/operator=/
		template<class _Key, class _T, class _Compare, class _Alloc>
		friend bool operator==(const map<_Key, _T, _Compare, _Alloc> & lhs,
				const map<_Key, _T, _Compare, _Alloc>& rhs);

		template<class _Key, class _T, class _Compare, class _Alloc>
		friend bool operator<(const map<_Key, _T, _Compare, _Alloc> & lhs,
				const map<_Key, _T, _Compare, _Alloc>& rhs);
	};

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
	{
		return (lhs._tree == rhs._tree);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
	{
		return !(lhs == rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
	{
		return (lhs._tree < rhs._tree);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
	{
		return !(lhs > rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs)
	{
		return !(lhs < rhs);
	}


	template<class Key, class T, class Compare, class Alloc>
	void swap(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
};

#endif