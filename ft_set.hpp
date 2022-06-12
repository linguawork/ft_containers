/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:17:13 by areggie           #+#    #+#             */
/*   Updated: 2022/06/12 16:51:39 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_HPP
# define FT_SET_HPP
#include "ft_redblacktree.hpp"
#include "ft_utility.hpp"

namespace ft
{
	template<
			class Key,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<Key> >

	class set
	{

	public:
		typedef Key key_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef key_compare value_compare;
		typedef key_type value_type;
		typedef Allocator allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef RBTree<value_type, key_compare, allocator_type> tree_type;
		typedef typename tree_type::iterator iterator;
		typedef typename tree_type::const_iterator const_iterator;
		typedef typename tree_type::reverse_iterator reverse_iterator;
		typedef typename tree_type::const_reverse_iterator const_reverse_iterator;

	private:
		tree_type rbtree_;

	public:

		explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : rbtree_(tree_type(comp, alloc)) {}

		template< class InputIt >
		set(InputIt first, InputIt last, const Compare & comp = Compare(), const Allocator &alloc = Allocator()): rbtree_(tree_type(first, last, comp, alloc)) {}

		set(const set& other): rbtree_(tree_type(other.rbtree_)) {}


		set operator=(const set & other)
		{
			this->rbtree_ = other.rbtree_;
			return (*this);
		}

		allocator_type get_allocator(void) const
		{
			return ( this->rbtree_.get_allocator());
		}

		size_type size(void) const
		{
			return (this->rbtree_.size());
		}

		size_type max_size(void) const
		{
			return (this->rbtree_.max_size());
		}

		bool empty(void) const
		{
			return (this->rbtree_.empty());
		}

		value_compare value_comp(void) const
		{
			return (this->rbtree_.value_comp());
		}

		key_compare key_comp() const
		{
			return (this->value_comp());
		}

		iterator begin(void)
		{
			return (this->rbtree_.begin());
		}

		const_iterator begin(void) const
		{
			return (this->rbtree_.begin());
		}

		iterator end(void)
		{
			return (this->rbtree_.end());
		}

		const_iterator end(void) const
		{
			return (this->rbtree_.end());
		}

		reverse_iterator rbegin(void)
		{
			return (this->rbtree_.rbegin());
		}

		const_reverse_iterator rbegin(void) const
		{
			return (this->rbtree_.rbegin());
		}

		reverse_iterator rend(void)
		{
			return (this->rbtree_.rend());
		}

		const_reverse_iterator rend(void) const
		{
			return (this->rbtree_.rend());
		}

		void clear(void)
		{
			this->rbtree_.clear();
		}

		void swap(set & other)
		{
			this->rbtree_.swap(other.rbtree_);
		}

		iterator find(const Key& key)
		{
			return this->rbtree_.find(key);
		}

		const_iterator find(const Key& key) const
		{
			return this->rbtree_.find(key);
		}

		size_type count(const Key &key) const
		{
			return this->rbtree_.count(key);
		}

		iterator lower_bound(const key_type& k)
		{
			return this->rbtree_.lower_bound(k);
		}

		const_iterator lower_bound(const key_type& k) const
		{
			return this->rbtree_.lower_bound(k);
		}

		iterator upper_bound(const key_type& k)
		{
			return this->rbtree_.lower_bound(k);
		}

		const_iterator upper_bound(const key_type& k) const
		{
			return this->rbtree_.lower_bound(k);
		}

		pair<iterator, iterator> equal_range(const key_type & k)
		{
			return this->rbtree_.equal_range(k);
		}

		pair<const_iterator, const_iterator> equal_range(const key_type & k) const
		{
			return this->rbtree_.equal_range(k);
		}

		ft::pair<iterator, bool> insert( const value_type& val )
		{
			return this->rbtree_.insert(val);
		}

		iterator insert( iterator hint, const value_type& val)
		{
			return this->rbtree_.insert(hint, val);
		}

		template<class InputIt>
		void insert(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last)
		{
			this->rbtree_.insert(first, last);
		}

		void erase(iterator pos)
		{
			this->rbtree_.erase(pos);
		}

		size_type erase(const Key & key)
		{
			return this->rbtree_.erase(key);
		}

		void erase(iterator first, iterator last)
		{
			this->rbtree_.erase(first, last);
		}

		template<class K, class Com, class Al>
		friend bool 
		operator==(const set<K, Com, Al>& lhs, const set<K, Com, Al>& rhs);

		template<class K, class Com, class Al>
		friend bool 
		operator<(const set<K, Com, Al>& lhs, const set<K, Com, Al>& rhs);

	};

	template<class Key, class Compare, class Alloc>
	bool operator==(const set<Key, Compare, Alloc>& lhs,
					 const set<Key, Compare, Alloc>& rhs)
	{
		return (lhs.rbtree_ == rhs.rbtree_);
	}

	template<class Key, class Compare, class Alloc>
	bool operator!=(const set<Key, Compare, Alloc>& lhs,
					 const set<Key, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template<class Key, class Compare, class Alloc>
	bool operator<(const set<Key, Compare, Alloc>& lhs, 
					const set<Key, Compare, Alloc>& rhs)
	{
		return (lhs.rbtree_ < rhs.rbtree_);
	}

	template<class Key, class Compare, class Alloc>
	bool operator>(const set<Key, Compare, Alloc>& lhs, 
					const set<Key, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class Compare, class Alloc>
	bool operator<=(const set<Key, Compare, Alloc>& lhs,
					const set<Key, Compare, Alloc>& rhs)
	{
		return !(lhs > rhs);
	}

	template<class Key, class Compare, class Alloc>
	bool operator>=(const set<Key, Compare, Alloc>& lhs,
					 const set<Key, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}


};

namespace std
{
	template<class Key,class Compare, class Alloc>
	void swap(const ft::set<Key, Compare, Alloc>& lhs,
			const ft::set<Key, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
