/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:40:31 by areggie           #+#    #+#             */
/*   Updated: 2022/06/13 12:40:47 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_HPP
#define FT_REVERSE_ITERATOR_HPP


#include "ft_utility.hpp"
/*
acc to subj I need to implement reverse_iterator (making class)
random_access_iterator should not be implemented 
as subject does not require to implement random_access_iterator
random access iterator can be just replaced by pointer from std::Allocator
in ft::vector
which I am going to implement

but tests of the RAI on pointers from Allocators (one peer's realization)
showed that there were problems with method resize()

so I decided to switch back to RAI class

to pass the tester I made ft_reverse_iterator.hpp file without making
a different file for RAI class (it probably is nested for the sake of unit tester)
*/



namespace ft {
	template<class Iterator>
	class reverse_iterator {
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::value_type      value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer     pointer;
		typedef typename ft::iterator_traits<Iterator>::reference   reference;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
	public:
		reverse_iterator(): ptr(nullptr) {}

		reverse_iterator(iterator_type iter): ptr(iter) {}

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& other): ptr(other.base()) {}

		reverse_iterator operator+ (difference_type n) const {
			return (reverse_iterator(ptr - n));
		}
		virtual ~reverse_iterator() {}

		iterator_type base() const {
			return (ptr);
		}

		reference operator*() const {
			iterator_type temp = ptr;
			return (*(--temp));
		}

		pointer operator->() const {
			return ft::addressof(operator*());
		}

		reverse_iterator& operator++() {
			--ptr;
			return (*this);
		}

		reverse_iterator operator++(int) {
			reverse_iterator temp = *this;
			++(*this);
			return (temp);
		}

		reverse_iterator& operator+=(difference_type n) {
			ptr -= n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const {
			return (reverse_iterator(ptr + n));
		}

		reverse_iterator& operator--() {
			++ptr;
			return (*this);
		}

		reverse_iterator operator--(int) {
			reverse_iterator temp = *this;
			--(*this);
			return (temp);
		}

		reverse_iterator& operator-=(difference_type n) {
			ptr += n;
			return (*this);
		}

		reference operator[](difference_type n) const {
			return (this->base()[-n - 1]);
		}
	private:
		iterator_type ptr;
	};

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class Iterator_LEFT, class Iterator_RIGHT>
	bool operator==(const reverse_iterator<Iterator_LEFT>& lhs,
					const reverse_iterator<Iterator_RIGHT>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class Iterator_LEFT, class Iterator_RIGHT>
	bool operator!=(const reverse_iterator<Iterator_LEFT>& lhs,
					const reverse_iterator<Iterator_RIGHT>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator< (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() > rhs.base());
	}

	template <class Iterator_LEFT, class Iterator_RIGHT>
	bool operator<(const reverse_iterator<Iterator_LEFT>& lhs,
				   const reverse_iterator<Iterator_RIGHT>& rhs) {
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator_LEFT, class Iterator_RIGHT>
	bool operator<=(const reverse_iterator<Iterator_LEFT>& lhs,
					const reverse_iterator<Iterator_RIGHT>& rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs,
				   const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() < rhs.bash());
	}

	template <class Iterator_LEFT, class Iterator_RIGHT>
	bool operator>(const reverse_iterator<Iterator_LEFT>& lhs,
				   const reverse_iterator<Iterator_RIGHT>& rhs) {
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator_LEFT, class Iterator_RIGHT>
	bool operator>=(const reverse_iterator<Iterator_LEFT>& lhs,
					const reverse_iterator<Iterator_RIGHT>& rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() - rhs.base());
	}

	template <class Iterator_LEFT, class Iterator_RIGHT>
	bool operator-(const reverse_iterator<Iterator_LEFT>& lhs,
				   const reverse_iterator<Iterator_RIGHT>& rhs) {
		return (lhs.base() - rhs.base());
	}

}

#endif