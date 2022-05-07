/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomaccessiterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:49:32 by areggie           #+#    #+#             */
/*   Updated: 2022/05/06 19:40:26 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iterator> //	std::random_access_iterator_tag

#include "iterator_traits.hpp"

namespace ft
{

template<class T> // why remove const
struct remove_const 
{ 
	typedef T type; 
};

template<class T> 
struct remove_const <const T> 
{ 
	typedef T type; 
};

template< typename T>
class RandomAccessIterator
{
	public:
		typedef	typename ft::iterator_traits<T*>::value_type		value_type;
		typedef	typename ft::iterator_traits<T*>::pointer			pointer;
		typedef	typename ft::iterator_traits<T*>::reference			reference;
		typedef	typename ft::iterator_traits<T*>::difference_type	difference_type;
		//this is for std::functions
		typedef	std::random_access_iterator_tag iterator_category;
		
	//maybe protected???
	private:
		pointer _ptr;
		//CONSTRUCTORS
	public:
		RandomAccessIterator() : _ptr(){}
		RandomAccessIterator(pointer a) : _ptr(a){};
		virtual ~RandomAccessIterator() {}	
		RandomAccessIterator(const RandomAccessIterator<typename ft::remove_const<T>::type> & src) : _ptr(src._ptr){}
		
		pointer base(void) const
        {
			return _ptr;
		}
		// removed IsConst
		RandomAccessIterator<T> & operator=(RandomAccessIterator<typename ft::remove_const<T>::type> const & src)
		{
				_ptr = src._ptr;
				return (*this);
		}
		
		// operator RandomAccessIterator<T, true>() const{
		// 	return (RandomAccessIterator<T, true>(_ptr));
		// };

		
		//OPERATORS
		RandomAccessIterator & operator++(){
			++_ptr;
			return (*this);
		}
		RandomAccessIterator  operator++(int){
			RandomAccessIterator tmp(*this);
			++_ptr;
			return(tmp);
		}
		RandomAccessIterator & operator--(){
			--_ptr;
			return (*this);

		}
		RandomAccessIterator  operator--(int){
			RandomAccessIterator tmp = *this;
			--_ptr;
			return(tmp);
		}
		RandomAccessIterator operator+(const difference_type & a) const{
			return (_ptr + a);
		}
	
		RandomAccessIterator operator-(const difference_type & a) const{
			return(_ptr - a);
		}
		
		 difference_type operator-(const RandomAccessIterator<T> & b){
		 	return(_ptr - b.base());
		 }
		
		// difference_type operator-(const RandomAccessIterator<T, false> & b){
		// 	return(_ptr - b.base());
		// }
		
		RandomAccessIterator & operator+=(const difference_type & a){
			_ptr += a;
			return (*this);
		}
		RandomAccessIterator & operator-=(const difference_type & a){
			_ptr -= a;
			return (*this);
		}
		pointer operator->(){
			return(_ptr);
		}
		value_type & operator*(){
			return(*_ptr);
		}
		reference operator[](difference_type n) const{
			return(*(_ptr + n));
		}
};

//COMPARISON OPERATORS

template<typename A, typename B>
bool operator==(const RandomAccessIterator<A> & lhs, const RandomAccessIterator<B> & rhs){
	return &(*lhs) == &(*rhs);
}

template<typename A, typename B>
bool operator!=(const RandomAccessIterator<A> & lhs, const RandomAccessIterator<B> & rhs){
	return !(lhs == rhs);
}

template<typename A, typename B>
bool operator>(const RandomAccessIterator<A> & lhs, const RandomAccessIterator<B> & rhs){
	return !(lhs == rhs);
}


// template<typename L, bool IsConst>
// RandomAccessIterator<L, IsConst> operator +(const typename RandomAccessIterator<L, IsConst>::difference_type & a, const RandomAccessIterator<L, IsConst> & iter){
// 		return	(iter + a);	
// 	}

// template<typename L, bool IsConst>
// RandomAccessIterator<L, IsConst> operator -(const typename RandomAccessIterator<L, IsConst>::difference_type & a, const RandomAccessIterator<L, IsConst> & iter){
// 		return	(iter - a);	
// 	}

};


#endif