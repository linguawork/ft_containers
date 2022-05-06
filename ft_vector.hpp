/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:26:38 by areggie           #+#    #+#             */
/*   Updated: 2022/05/06 14:36:36 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_VECTOR_HPP // defining HEADER
#define FT_VECTOR_HPP
#include <memory> //std::allocator
#include "./enable_if.hpp" // attaching enable_if class
#include "./is_integral.hpp" // attaching structures for enable_if


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
	
	answer: to call for conversion explicitly 
	more:  https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
	
	чтобы данные могли вызываться явно через создание объекта, а не подразумевая.
	*/

	explicit vector (const allocator_type& alloc = allocator_type()) : f_irst(0), s_ize(0), c_apacity(0), a_llocator(alloc)
	{
		std::cout << "Default vector constructor called" << std::endl; 
	}
	
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : s_ize(n), c_apacity(n), a_llocator(alloc)
	{
		std::cout << "Vector constructor with parameters called, size and capacity are given n value\n" << std::endl;
		std::cout << "value_type instance and allocator_type instance are created empty\n" << std::endl; 
		
		size_type i;
		
		//pointer of allocator, new (n elements)
		//https://www.cplusplus.com/reference/memory/allocator/allocate/
		f_irst = _allocator.allocate(n); 
		i = 0;
		while(i < n)
		{
			//https://www.cplusplus.com/reference/memory/allocator/construct/
			a_llocator.construct(f_irst + i, val); // сonstruct method of allocator class, fills vector with values
			i++;
		}
	}

	/*
	library to know about enable_if
	https://www.cplusplus.com/reference/type_traits/

	enable_if
	https://www.cplusplus.com/reference/type_traits/enable_if/


	//using enable_if in iterators
	https://stackoverflow.com/questions/28529376/stdvector-constructor-taking-pair-of-iterators
	
	"it's sufficient for implementations to test for integral types only, but they can do more if they want to."
	 
	in std::vector the Iterator is described as:

	// template <class InputIterator>
	// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	
	*/

	

		
		//vector constructor with iterators
		template <class InputIterator>
        	 vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value>::type* = 0) : a_llocator(alloc)
		{
			if (first > last)
				throw std::length_error("vector");
			s_ize = last - first;
			c_apacity = s_ize;
			f_irst = a_llocator.allocate(c_apacity);
			for (difference_type i = 0; i < static_cast<difference_type>(s_ize); i++)
				a_llocator.construct(f_irst + i, *(first + i));
		 }
		
		
			
	};
}

#endif