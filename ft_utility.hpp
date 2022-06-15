/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:17:27 by areggie           #+#    #+#             */
/*   Updated: 2022/06/15 11:47:33 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITY_HPP
#define FT_UTILITY_HPP


/*
about iterator_traits typedef in Russian STL of 98 standard by Stepanov:

шаблонный класс iterator_traits в качестве шаблона принимает итератор и наделяет его полями 
которые уже прописаны в основном итераторе 
Хотя эти поля повторяются важность класса iterator_traits в том что они обеспечивают 
частичную специализацию (partial specialization) КОТОРАЯ ОБРАБАТЫВАЕТ ВСЕ ТИПЫ УКАЗАТЕЛЕЙ
(некоторые компиляторы не поддерживают частичную специализацию)

Эта обработка определяет что все указатели это итератора произвольного доступа
(RAI) с типом расстояния ptrdiff_t

Ptrdiff - это целый тип который представляет разницу между любыми двумя объектами-указателями
указывающими на элементы одного массива ( typedef in C library <stddef.h>)
(книга С++ STL , стр 72)

*/


/*
iterator traits

*/

#include <iterator>
#include <iostream>


namespace ft 
{
	//struct off_const
	template<class T> 
	struct off_const 
	{ 
		typedef T type; 
	};

	template<class T> 
	struct off_const <const T>
	{ 
		 typedef T type; 
	};


	template<class iterator>
	struct iterator_traits 
	{
		typedef iterator iterator_type;
		typedef typename iterator::difference_type difference_type;
		typedef typename iterator::value_type value_type;
		typedef typename iterator::pointer pointer;
		typedef typename iterator::reference reference;
		typedef typename iterator::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T *> 
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<class T>
	struct iterator_traits<const T *> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	// struct pair
	template<class T1, class T2> struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;
		pair() : first(), second() {}
		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}
		pair(const pair & pr) : first(pr.first), second(pr.second) {}
		pair(const first_type &a, const second_type &b) : first(a), second(b) {}
		pair &operator=(const pair &pr)
		{
			first = pr.first;
			second = pr.second;
			return (*this);
		}

	};
		//operators of comparison with pair 
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first ||
			(!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}

	//make pair method
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}



	/*
		https://www.cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator

		implementation of iterator for vector, which inher  random_access_iterator
	*/




	/*
	is_integral
	*/
	//Проверяет, является ли T целочисленным типом. Предоставляет постоянное value члена, равное true,
	// если T - это тип bool , char , char8_t , char16_t , char32_t , wchar_t , short , int , long ,
	// long long или любые расширенные целочисленные типы, определенные реализацией, включая любые
	// подписанные, неподписанные и cv-квалифицированные варианты. В противном случае value равно false

	template<class T, bool v>
		struct integral_constant
		{
			static const bool value = v;
			typedef T value_type;
			typedef integral_constant type;
			operator value_type() const 
			{ 
				return value; 
			}
		};

	template <class T> 
	struct is_integral : public ft::integral_constant<T, false> 
	{
		
	};
	
	template <> 
	struct is_integral<bool> : public ft::integral_constant<bool, true> 
	{
		
	};
	
	template <> 
	struct is_integral<char> : public ft::integral_constant<bool, true> 
	{
		
	};

	template <> 
	struct is_integral<signed char>	: public ft::integral_constant<bool, true> 
	{
		
	};
	
	template <> 
	struct is_integral<unsigned char>: public ft::integral_constant<bool, true> 
	{

	};
	
	template <> 
	struct is_integral<wchar_t>	: public ft::integral_constant<bool, true> 
	{

	};
	
	template <> struct is_integral<char16_t> : public ft::integral_constant<bool, true> 
	{

	};
	
	template <> 
	struct is_integral<short> : public ft::integral_constant<bool, true> 
	{
		
	};

	template <> 
	struct is_integral<unsigned short> : public ft::integral_constant<bool, true> 
	{

	};
	
	template <> 
	struct is_integral<int>	: public ft::integral_constant<bool, true> 
	{
		
	};
	template <> 
	struct is_integral<unsigned int> : public ft::integral_constant<bool, true> 
	{
		
	};

	template <> 
	struct is_integral<long> : public ft::integral_constant<bool, true> 
	{
		
	};
	
	template <> 
	struct is_integral<unsigned long> : public ft::integral_constant<bool, true> 
	{
		
	};
	
	template <> 
	struct is_integral<long long> : public ft::integral_constant<bool, true>
	{
		
	};
	
	template <> 
	struct is_integral<unsigned long long>	: public ft::integral_constant<bool, true> 
	{
		
	};


	/*
	block enable if

	*/
	
	template<bool Cond, class T = void> 
	struct enable_if 
	{
		
	};
	
	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	/*
	lexicographical compare
	*/
	template<class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2) {
		for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return (first1 == last1) && (first2 != last2);//?
	}
	//https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
	template<class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2,
								 Compare comp) {
		for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	//equal
	template <class InputIterator1, class InputIterator2>
  	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
			return true;
	}


	//template class Iterator
	template<class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T *, class Reference = T &>
	class iterator {
	public:
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	// template<class T>
	// class bidirectional_iterator: ft::iterator<std::bidirectional_iterator_tag, T> {
	// 	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category iterator_category;
	// 	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type value_type;
	// 	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type difference_type;
	// 	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer pointer;
	// 	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference reference;
	// private:
	// 	pointer _elem;
	// };

	// this is needed in reverse iterator for 	pointer operator->() const
	template<class T>
	typename std::enable_if<std::is_object<T>::value, T*>::type  addressof(T& arg) {
		return reinterpret_cast<T*>(&const_cast<char&>(reinterpret_cast<const volatile char&>(arg)));
	}

	template<class T>
	typename std::enable_if<!std::is_object<T>::value, T*>::type addressof(T& arg) {
		return &arg;
	}


	
};


#endif








