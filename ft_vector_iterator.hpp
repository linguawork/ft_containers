/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:29:09 by areggie           #+#    #+#             */
/*   Updated: 2022/06/14 20:23:28 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_ITERATOR_HPP
#define FT_VECTOR_ITERATOR_HPP
#include "ft_utility.hpp"

 namespace ft
 {

	template<typename T>
	class vector_iterator: public ft::iterator<std::random_access_iterator_tag, T> 
	{
	public:
		typedef T value_t;
		typedef T* pointer;
		typedef T& reference;

		// typedef T                                                     						 	iterator_type;
		typedef pointer iterator_type;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type            value_type;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type       difference_type;
	public:
		vector_iterator(): ptr(0) {}

		vector_iterator(pointer other): ptr(other) {}

		vector_iterator(vector_iterator const &other): ptr(other.ptr) {}

		virtual ~vector_iterator() {}

		vector_iterator &operator=(const vector_iterator& other) {
			if (this == &other)
				return (*this);
			ptr = other.ptr;
			return (*this);
		}

		pointer base() const {
			return (ptr);
		}

		reference operator*(void) const {
			return (*ptr);
		}

		pointer operator->(void) {
			return &(operator*());
		}

		vector_iterator operator+(difference_type n) const {
			return (ptr + n);
		}

		vector_iterator operator-(difference_type n) const {
			return (ptr - n);
		}

		vector_iterator& operator++() {
			ptr++;
			return (*this);
		}

		vector_iterator operator++(int) {
			vector_iterator temp(*this);
			operator++();
			return (temp);
		}

		vector_iterator& operator--() {
			ptr--;
			return (*this);
		}

		vector_iterator operator--(int) {
			vector_iterator temp(*this);
			operator--();
			return (temp);
		}

		vector_iterator& operator+=(difference_type n) {
			ptr += n;
			return (*this);
		}

		vector_iterator& operator-=(difference_type n) {
			ptr -= n;
			return (*this);
		}

		reference operator[](difference_type n) {
			return (*(ptr + n));
		}
	private:
		pointer ptr;
	};

	 
	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator-(const ft::vector_iterator<T> lhs,
			  const ft::vector_iterator<T> rhs) {
		return (lhs.base() - rhs.base());
	}

	template<typename T>
	ft::vector_iterator<T> operator+(typename ft::vector_iterator<T>::difference_type n,
			typename ft::vector_iterator<T>& rai) {
		return (&(*rai) + n);
	}

	template<typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator-(const ft::vector_iterator<T_LEFT> lhs,
			  const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() - rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator==(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() == rhs.base());
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator==(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() == rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator!=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() != rhs.base());
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator!=(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator<(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() < rhs.base());
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator<=(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() <= rhs.base);
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator<=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() <= rhs.base);
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator<(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() < rhs.base);
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator>(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() > rhs.base());
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator>(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() > rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator>=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator>=(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() >= rhs.base());
	}
};

#endif
