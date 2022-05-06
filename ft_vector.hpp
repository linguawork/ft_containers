/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:26:38 by areggie           #+#    #+#             */
/*   Updated: 2022/05/06 10:00:27 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_VECTOR_HPP // defining HEADER
#define FT_VECTOR_HPP
#include <memory> //std::allocator


/*
templates are all used in header files (this is the peculiarity of CPP)

links:
std98 vector
https://www.cplusplus.com/reference/vector/vector/?kw=vector    

std98 allocator
https://www.cplusplus.com/reference/memory/allocator/

In vector container I have to use std::allocator's members

*/


namespace ft
{
	//Template according to std98 documentation
	//https://www.cplusplus.com/reference/memory/allocator/
	//there are fields inside std::allocator and I redefined them via typedef
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		// It is my habit to use private field above public, so I have to typedef certain public fields first
		public:
			typedef 	Allocator 								allocator_type; // renamed Allocator
			typedef 	typename allocator_type::pointer 		pointer; // shortcut to pointer of std::allocator member
			typedef		std::ptrdiff_t 							difference_type;
			typedef		std::size_t 							size_type;

		private:
			pointer			f_irst; // pointer from allocator
			size_type 		s_ize;
			size_type		c_apacity; 
			allocator_type	a_llocator;	

		//MEMBER TYPES according to std98 documentation https://www.cplusplus.com/reference/vector/vector/
		public:
		
			typedef 	T 										value_type;
//			typedef 	Allocator 								allocator_type; // renamed Allocator
			typedef 	value_type& 							reference; 
			typedef 	const value_type& 						const_reference;
//			typedef 	typename allocator_type::pointer 		pointer; // shortcut to pointer of std::allocator member
			typedef 	typename allocator_type::const_pointer 	const_pointer; // 
			typedef 	RandomAccessIterator<value_type> 		iterator; // https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
			typedef		RandomAccessIterator<const value_type> 	const_iterator; //https://en.cppreference.com/w/cpp/iterator/iterator_tags
			typedef		reverse_iterator<iterator> 				reverse_iterator;
			typedef		reverse_iterator<const_iterator> 		const_reverse_iterator;		
//			typedef		std::ptrdiff_t 							difference_type;
//			typedef		std::size_t 							size_type;		


/* CONSTRUCTORS */

	/*
	question1:
	Why are there brackets with allocator_type() in constructor?
 
	The argument to the constructor is an instance of that type. -  Benjamin Lindley

	You might wonder what memory models have to do with algorithms or the container interfaces. 
	If you cannot use things like size_t, you also cannot use things like T* because of different pointer types 
	(T*, T huge *, etc.). Then you cannot use references because with different memory models you have different reference types. 
	There were tremendous ramifications on the library. - Alex Stepanov
	
	source: https://stackoverflow.com/questions/18999088/why-allocator-in-constructor

	Под каждый создаваемый объект вектора создается объект памяти (тип аллокатора)
	 который решает проблему отличий моделей памяти
	*/


	/*
	Question2:
	Why is the keyword "explicit" is used in vector constructors?
	
	
	*/

	explicit vector (const allocator_type& alloc = allocator_type()) : f_irst(0), s_ize(0), c_apacity(0), a_llocator(alloc)
	{
		std::cout << "Default vector constructor called" << std::endl; 
	}
	
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		

		
		
			
	};
}

#endif