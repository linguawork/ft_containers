/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:38:32 by areggie           #+#    #+#             */
/*   Updated: 2022/06/12 17:14:57 by areggie          ###   ########.fr       */
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
		tree_type		rbtree_;
		key_compare		_compare;

	public:

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc), rbtree_(tree_type(comp, alloc)), _compare(comp) {}

		template< class InputIt >
		map(InputIt first, InputIt last, const Compare& compare = Compare(), const Allocator& alloc = Allocator()):
			_alloc(alloc), rbtree_(first, last, compare, _alloc), _compare(compare) {}



		

	/***************ITERATORS methods************/

		iterator begin(void)
		{
			return (this->rbtree_.begin());
		}

		iterator end(void)
		{
			return (this->rbtree_.end());
		}

		reverse_iterator rbegin(void)
		{
			return(this->rbtree_.rbegin());
		}

		reverse_iterator rend(void)
		{
			return(this->rbtree_.rend());
		}



	/***************MAP CAPACITY methods************/
		
		//https://m.cplusplus.com/reference/map/map/size/
		size_type size(void) const
		{
			return (this->rbtree_.size());
		}

		size_type max_size(void) const
		//https://m.cplusplus.com/reference/map/map/max_size/
		{
			return (this->rbtree_.max_size());
		}

		bool empty(void) const
		//https://m.cplusplus.com/reference/map/map/empty/
		{
			return (this->rbtree_.empty());
		}



	/***************MAP ELEMENT ACCESS methods************/
		
		//https://m.cplusplus.com/reference/map/map/operator[]/
		mapped_type& operator[](const key_type& key)
		{
			return (*((this->insert(ft::make_pair(key,mapped_type()))).first)).second;
		}

		//https://www.cplusplus.com/reference/vector/vector/at/
		T& at(const Key &key)
		{
			iterator result = rbtree_.find(ft::make_pair(key, mapped_type()));
			if (result == rbtree_.end())
				throw std::out_of_range("map::at: key not found");
			return (result->second);
		}
		

	/***************MODIFIERS methods************/

		

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
			return (this->rbtree_.insert(value));
		}

		/*
			The versions with a hint (2) return an iterator 
			pointing to either the newly inserted element or 
			to the element that already had an equivalent key in the map.
		*/
		iterator insert(iterator pos, const value_type& value)
		{
			return (this->rbtree_.insert(pos, value));
		}

		/*
			Member type iterator is a bidirectional iterator type that points to elements.
			pair is a class template declared in <utility> (see pair).
		*/
		template<class InputIt>
		void insert(typename enable_if< !is_integral<InputIt>::value, InputIt >::type first, InputIt last)
		{
			this->rbtree_.insert(first, last);
		}
		
		//https://m.cplusplus.com/reference/map/map/erase/
		void erase(iterator iter_pos)  // 1 case: erase where by iter position
		{
			this->rbtree_.erase(iter_pos);
		}

		size_type erase(const Key& key) // erasing a key
		{
			return (this->rbtree_.erase(make_pair(key, mapped_type())));
		}

		void erase(iterator first, iterator last) // erasing range
		{
			this->rbtree_.erase(first, last);
		}

		//https://m.cplusplus.com/reference/map/map/swap/
		void swap(map & other)
		{
			std::swap(this->_compare, other._compare);
			this->rbtree_.swap(other.rbtree_);
		}
		
				/*
        Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
      	*/
      	//https://m.cplusplus.com/reference/map/map/clear/
		void clear(void)
		{
			this->rbtree_.clear(); //method of RBT
		}

	/***************MAP OBSERVERS methods************/

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
		//https://m.cplusplus.com/reference/map/map/key_comp/
		key_compare key_comp(void) const
		{
			return (_compare); // returns whether its first argument compares less than the second
		}
		
		//https://m.cplusplus.com/reference/map/map/value_comp/
		value_compare value_comp(void) const
		{
			return (this->rbtree_.value_comp()); // uses method of RBT
		}



	/***************MAP OPERATIONS methods************/
		//https://m.cplusplus.com/reference/map/map/find/
		iterator	find(const Key& key)
		{
			return (this->rbtree_.find(ft::make_pair(key, mapped_type()))); // it was ambiguous in range constructor of ft_map, so added ft::
		}

		//https://m.cplusplus.com/reference/map/map/count/
		/*
			Searches the container for elements with a key equivalent to k and returns the number of matches.

			Because all elements in a map container are unique, 
			the function can only return 1 (if the element is found) or zero (otherwise).

			Two keys are considered equivalent if the container's comparison object returns false reflexively 
			(i.e., no matter the order in which the keys are passed as arguments).
		*/	
		size_type count( const Key& key ) const
		{
			return (this->rbtree_.count(ft::make_pair(key, mapped_type())));
		}
		
		/*
        https://m.cplusplus.com/reference/map/map/lower_bound/
        
        upper_bound, has the same behavior as lower_bound,
         except in the case that the map contains an element with a key equivalent to k: 
         In this case, lower_bound returns an iterator pointing to that element, 
         whereas upper_bound returns an iterator pointing to the next element.
        
        */
		iterator lower_bound(const key_type& key)
		{
			return (this->rbtree_.lower_bound(make_pair(key, mapped_type())));
		}

		const_iterator lower_bound(const key_type& key) const
		{
			return (this->rbtree_.lower_bound(make_pair(key, mapped_type())));
		}

		iterator upper_bound(const key_type& key)
		{
			return (this->rbtree_.upper_bound(make_pair(key, mapped_type())));
		}

		const_iterator upper_bound(const key_type& key) const
		{
			return (this->rbtree_.upper_bound(make_pair(key, mapped_type())));
		}

		/*
        https://m.cplusplus.com/reference/map/map/equal_range/
        
        Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.

        Because the elements in a map container have unique keys, the range returned will contain a single element at most.

        If no matches are found, the range returned has a length of zero, with both iterators pointing to the first element that has a key considered to go after k according to the container's internal comparison object (key_comp).

        Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).

          
        The function returns a pair, whose member pair::first is the lower bound of the range 
        (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).

        If the map object is const-qualified, the function returns a pair of const_iterator. 
        Otherwise, it returns a pair of iterator.

        Member types iterator and const_iterator are bidirectional iterator types
         pointing to elements (of type value_type).
        Notice that value_type in map containers 
        is itself also a pair type: pair<const key_type, mapped_type>.
        */
		pair<iterator, iterator> equal_range(const key_type & key)
		{
			return (this->rbtree_.equal_range(make_pair(key, mapped_type())));
		}

		pair<const_iterator, const_iterator> equal_range(const key_type & key) const
		{
			return (this->rbtree_.equal_range(make_pair(key, mapped_type())));
		}

	/***************ALLOCATOR method************/

		//https://m.cplusplus.com/reference/map/map/get_allocator/
		allocator_type get_allocator(void) const
		{
			return (this->rbtree_.get_allocator());
		}

		/***************FRIEND methods************/

		//https://m.cplusplus.com/reference/map/map/operator=/
		template<class _Key, class _T, class _Compare, class _Alloc>
		friend bool operator==(const map<_Key, _T, _Compare, _Alloc> & lhs,
				const map<_Key, _T, _Compare, _Alloc>& rhs);

		template<class _Key, class _T, class _Compare, class _Alloc>
		friend bool operator<(const map<_Key, _T, _Compare, _Alloc> & lhs,
				const map<_Key, _T, _Compare, _Alloc>& rhs);
	};
	
	
	/***************OUT OF CLASS methods************/

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> & lhs, 
					const map<Key, T, Compare, Alloc> & rhs)
	{
		return (lhs.rbtree_ == rhs.rbtree_);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> & lhs, 
					const map<Key, T, Compare, Alloc> & rhs)
	{
		return !(lhs == rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> & lhs, 
					const map<Key, T, Compare, Alloc> & rhs)
	{
		return (lhs.rbtree_ < rhs.rbtree_);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> & lhs,
					 const map<Key, T, Compare, Alloc> & rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> & lhs, 
					const map<Key, T, Compare, Alloc> & rhs)
	{
		return !(lhs > rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> & lhs, 
					const map<Key, T, Compare, Alloc> & rhs)
	{
		return !(lhs < rhs);
	}

	/*REDUNDANT METHOD*/
	
	// template<class Key, class T, class Compare, class Alloc>
	// void swap(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	// {
	// 	lhs.swap(rhs);
	// }
};

#endif