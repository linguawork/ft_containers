/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:26:38 by areggie           #+#    #+#             */
/*   Updated: 2022/05/13 17:00:09 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_VECTOR_HPP // defining HEADER
#define FT_VECTOR_HPP
#include <memory> //std::allocator
// #include <iterator> 
#include <iostream>
#include "ft_utility.hpp"


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
			/*
			https://www.quora.com/Why-do-some-C-programs-use-size_t-instead-of-int-What-are-the-advantages
			size_t implies the size of an object, and usually matches 
			the processor address size which is often 64 bits.
			int is a signed integer, and is usually only 32 bits on 64 bit systems which is 
			less than you need to store the size of some objects.

			see print_size.c file
			Stepanov wrote about ptrdiff_t as difference_type in typedef for STL at page 72 (about iterators, iterator_traits)
			*/
			typedef		std::size_t 							size_type; // 8bytes not 4 bytes for signed int(which is not enough for objects)

		private:
			pointer			ptr_first_elem; // pointer from allocator
			size_type 		size_t_not_int;
			size_type		capacity_in_size_t; 
			allocator_type	allocator_kind;	

		//MEMBER TYPES according to std98 documentation https://www.cplusplus.com/reference/vector/vector/
		public:
		
			typedef 	T 										value_type;
//			typedef 	Allocator 								allocator_type; // renamed Allocator
			typedef 	value_type& 							reference; 
			typedef 	const value_type& 						const_reference;
//			typedef 	typename allocator_type::pointer 		pointer; // shortcut to pointer of std::allocator member
			typedef 	typename allocator_type::const_pointer 	const_pointer; // 

			//switched off for a while (not running along vector yet)
			// typedef 	RandomAccessIterator<value_type> 		iterator; // https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
			// typedef		RandomAccessIterator<const value_type> 	const_iterator; //https://en.cppreference.com/w/cpp/iterator/iterator_tags
			// typedef		reverse_iterator<iterator> 				reverse_iterator;
			// typedef		reverse_iterator<const_iterator> 		const_reverse_iterator;	
			
			typedef ft::vector_iterator<value_type> iterator;
			typedef ft::vector_iterator<const value_type> const_iterator;
			// typedef ft::reverse_iterator<iterator> reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;	
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
	- because we want to construct objects of classes explicitely, в явном а не в скрытном виде
	
	
	*/
	//this is the Default constructor
	explicit vector (const allocator_type& alloc = allocator_type()) : ptr_first_elem(0), size_t_not_int(0), capacity_in_size_t(0), allocator_kind(alloc)
	{
		std::cout << "Default vector constructor called" << std::endl; 
	}
	
	/*
	https://www.cplusplus.com/reference/vector/vector/vector/
	(2) fill constructor
		Constructs a container with n elements. Each element is a copy of val.
	*/
	
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : 
	size_t_not_int(n), capacity_in_size_t(n), allocator_kind(alloc)
	{
		std::cout << "Fill in vector constructor called" << std::endl; 
		size_type i;
		ptr_first_elem = allocator_kind.allocate(capacity_in_size_t);
		for(i = 0; i < n; i++)
			allocator_kind.construct(ptr_first_elem + i, val);
	}


	/*
	https://www.cplusplus.com/reference/vector/vector/vector/
	(3) range constructor
		Constructs a container with as many elements as the range [first,last),
		with each element constructed from its corresponding 
		element in that range, in the same order.		

	For this constructor we have to use iterator
	which will work through enable if to work with correct data_types
	correct data_types are filtered via is_integral
	
	so I have to realize ft::is_integral
	ft::enable_if
	*/
	template <class InputIterator>
	vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr): allocator_kind(alloc) 
		{
			if (first > last)
				throw std::length_error("Vector");
			size_t_not_int = last - first;
			capacity_in_size_t = size_t_not_int;
			ptr_first_elem = allocator_kind.allocate(capacity_in_size_t);
			for (difference_type i = 0; i < static_cast<difference_type>(size_t_not_int); i++)
				allocator_kind.construct(ptr_first_elem + i, *(first + i));
		}
		
	//operator of assignation=
	vector& operator=(const vector& x)
	{
		size_type i;
		
		if (this == &x)
			return *this;
		for (i = 0; i < size_t_not_int; i++)
			allocator_kind.destroy(ptr_first_elem + i);
		this->size_t_not_int = x.size_t_not_int;
		if(capacity_in_size_t < size_t_not_int)
		{
			if (capacity_in_size_t != 0)
				allocator_kind.deallocate(ptr_first_elem, capacity_in_size_t);
			capacity_in_size_t = size_t_not_int;
			ptr_first_elem = allocator_kind.allocate(capacity_in_size_t);
		}
		for ( i = 0; i < size_t_not_int; i++)
			allocator_kind.construct(ptr_first_elem + i, x[i]); // the operator [] is not working yet
		return *this;
	}

	//copy constructor
	vector (const vector& x) :  size_t_not_int (0), capacity_in_size_t (0)
	{
		*this = x; // we need to use operator = 
	}

	//distructor
	~vector()
	{
		size_type i;
		for (i = 0; i < size_t_not_int; i++)
			allocator_kind.destroy(ptr_first_elem + i);
		if(capacity_in_size_t)
			allocator_kind.deallocate(ptr_first_elem, capacity_in_size_t);
	}

		
		
		// {
		// difference_type len = last - first;

		// size_t_not_int = 0;
		// capacity_in_size_t = len;
		// ptr_first_elem = allocator_kind.allocate(allocator_kind);
		// assign(first, last);
		// }






	// ~vector()
	// 	{
	// 		size_type i;
			
	// 		i = 0;	
	// 		while (i < ptr_first_elem) // switched of, because so far I dont have camparison operator
	// 		{
	// 			allocator_kind.destroy(ptr_first_elem + i);
	// 		if(capacity_in_size_t)
	// 			allocator_kind.deallocate(ptr_first_elem, capacity_in_size_t);
	// 			i++;
	// 		}
	// 	}
	

		
		
			
	};
}

#endif