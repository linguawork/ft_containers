/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:02:25 by areggie           #+#    #+#             */
/*   Updated: 2022/05/06 14:11:54 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

/*
implementing class iterator_traits
https://www.cplusplus.com/reference/iterator/iterator_traits/

For every iterator type, a corresponding specialization of iterator_traits class template shall be defined,
with at least the following member types defined:
*/

namespace ft
{

	//Class iterator_traits works with the template Iterator
	template <class Iterator> //шаблон называем Итератор и будем им пользоваться в классе
	class iterator_traits //название класса
	{
		public:
			typedef typename Iterator::difference_type			difference_type;
			typedef typename Iterator::value_type				value_type;
			typedef typename Iterator::pointer					pointer;
			typedef typename Iterator::reference				reference;
			typedef typename Iterator::iterator_category		iterator_category;
	};

	// Класс iterator_traits работающий с шаблоном: Т
	template <class T> 
	class iterator_traits<T*> //с указателем на T
	{
		public:
			typedef std::ptrdiff_t	difference_type;
			typedef T				value_type;
			typedef T*			pointer;
			typedef T&			reference;
			typedef	std::random_access_iterator_tag	iterator_category;
	};


	// Класс iterator_traits работающий с шаблоном: Т
	template <class T> 
	class iterator_traits<const T*> //с const указателем на T
	{
		public:
			typedef std::ptrdiff_t	difference_type;
			typedef const T				value_type;
			typedef const T*			pointer;
			typedef const T&			reference;
			typedef	std::random_access_iterator_tag	iterator_category;
	};

}

#endif