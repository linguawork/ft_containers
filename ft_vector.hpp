/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:26:38 by areggie           #+#    #+#             */
/*   Updated: 2022/05/16 10:10:36 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_VECTOR_HPP // defining HEADER
#define FT_VECTOR_HPP
#include <memory> //std::allocator
// #include <iterator> 
#include <iostream>
#include "ft_utility.hpp"
#include "ft_reverse_iterator.hpp"


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
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;	
//			typedef		std::ptrdiff_t 							difference_type;
//			typedef		std::size_t 							size_type;		



/* MEMBER FUNCTIONS acc to https://www.cplusplus.com/reference/vector/vector/ */

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
		std::cout << "Default ft_vector constructor called" << std::endl; 
	}
	
	/*
	https://www.cplusplus.com/reference/vector/vector/vector/
	(2) fill constructor
		Constructs a container with n elements. Each element is a copy of val.
	*/
	
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : 
	size_t_not_int(n), capacity_in_size_t(n), allocator_kind(alloc)
	{
		std::cout << "Fill in ft_vector constructor called" << std::endl; 
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
			std::cout << "Range ft_vector constructor called" << std::endl; 
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
		std::cout << "copy of ft_vector constructor called" << std::endl;
		*this = x; // we need to use operator = 
	}

	//destructor
	~vector()
	{

		std::cout << "ft_vector class obj destructor called" << std::endl;
		size_type i;
		for (i = 0; i < size_t_not_int; i++)
			allocator_kind.destroy(ptr_first_elem + i);
		if(capacity_in_size_t)
			allocator_kind.deallocate(ptr_first_elem, capacity_in_size_t);
	}



	/*
	Now need to iterate along vector
	So I need to implement begin and end
		ITERATORS
	*/

	//https://www.cplusplus.com/reference/vector/vector/begin/
		iterator begin()
		{
			return (iterator(ptr_first_elem));
		}
		
		const_iterator begin() const
		{
			return (const_iterator(ptr_first_elem));
		}
		
		iterator end()
		{
			return (iterator(ptr_first_elem + size_t_not_int));
		}
		
		const_iterator end() const
		{
			return (const_iterator(ptr_first_elem + size_t_not_int));
		}

	//methods for reverse_iterators
	//https://www.cplusplus.com/reference/vector/vector/rbegin/

		reverse_iterator rbegin() 
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const 
		{
			return (const_reverse_iterator(end()));
		}

		reverse_iterator rend() 
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const 
		{
			return (const_reverse_iterator(begin()));
		}
	

	
	/* CAPACITY */
		
		//size() https://www.cplusplus.com/reference/vector/vector/size/
		size_type size() const 
		{
			return (size_t_not_int);
		}
		
		//max_size() https://www.cplusplus.com/reference/vector/vector/max_size/
		//https://stackoverflow.com/questions/5068262/how-do-i-implement-arraymax-size
		size_type max_size() const 
		{
			// return ((size_type)(-1) / sizeof(value_type)); // return size divided by object
			return (allocator_kind.max_size());
		}
		

		//method to help resize
		void reallocate (size_type n)
		{
			size_type i;

			i = 0;
			if (n > this->max_size())
				throw ::std::length_error( "ft::vector::reallocate() exceeded max_size()" );
			if (n < capacity_in_size_t)
				return;
			pointer newarr = allocator_kind.allocate(n);
			try
			{
				while ( i < size_t_not_int)
				{
					allocator_kind.construct(newarr + i, *(ptr_first_elem + i));
					i++;
				}
			}
			catch (std::exception &e)
			{
				i = 0;
				while (newarr + i != NULL && i < size_t_not_int)
				{
					allocator_kind.destroy(newarr + i); //destroy new vector if there is a problem
					i++;
				}
				allocator_kind.deallocate(newarr, n); // free 
				throw;
			}
			i = 0; // if success we get rid of the old
			while( i < size_t_not_int) 
			{
				allocator_kind.destroy(ptr_first_elem + i); // destroy
				i++;
			}
			if(capacity_in_size_t)
				allocator_kind.deallocate(ptr_first_elem, capacity_in_size_t); // free
			capacity_in_size_t = n; // new cap
			ptr_first_elem = newarr; // new arr
		}


		//https://www.cplusplus.com/reference/vector/vector/resize/
		void resize (size_type n, value_type val = value_type())
		{
			if(n < size_t_not_int)
			{
				for(size_type i = n; i < size_t_not_int; i++)
					allocator_kind.destroy(ptr_first_elem + i);
				size_t_not_int = n;
			}
			else if (n > size_t_not_int)
			{
				if (capacity_in_size_t < n)
					this->reallocate(capacity_in_size_t * 2 > n ? capacity_in_size_t * 2 : n);
				for (size_type i = size_t_not_int; i < n; i++)
				{
					allocator_kind.construct(ptr_first_elem + i, val);
					size_t_not_int++;
				}
			}
		}
		
		//https://www.cplusplus.com/reference/vector/vector/capacity/
		size_type capacity(void) const
		{
			return (capacity_in_size_t);
		}

		bool empty() const 
		{
			return (size_t_not_int == 0); 
			// return (ptr_first_elem == 0); // caused problem in pop_back, so I changed
		}


		//https://www.cplusplus.com/reference/vector/vector/reserve/
		void reserve (size_type n) 
		{
			if (n > capacity_in_size_t)
				reallocate(n);
		}

	/* ELEMENT ACCESS */
	
	/* 
	I moved it from the upper part to here
	there should be const and non-const
	https://www.cplusplus.com/reference/vector/vector/operator[]/
	*/
	reference operator[] (size_type n)
	{
		return ( *( this->ptr_first_elem + n ) );
	}	

	
	const_reference operator[] (size_type n) const
	{
		// return(*(ptr_first_elem + n));
		return ( *( this->ptr_first_elem + n ) );
	}

	void check_boundaries( size_type position ) const {
		if ((position < 0 ||position >= this->size() || empty()))
			throw ::std::out_of_range( "ft::vector::at() out of range" );
	}	

	reference at( size_type position ) 
	{
		check_boundaries( position );
		return ( ( *this )[position] );
	}

	const_reference at( size_type position ) const
	{
		check_boundaries( position );
		return ( ( *this )[position] );
	}

	reference front( void )
	{
		 return ( *this->ptr_first_elem ); 
	}

	const_reference front( void ) const 
	{
		 return ( *this->ptr_first_elem ); 
	}

	reference back( void ) 
	{
		 return (ptr_first_elem[size_t_not_int - 1] ); 
	}

	const_reference back( void ) const 
	{
		 return (ptr_first_elem[size_t_not_int - 1] ); 
	}
	
	

		
	

	/* MODIFIER */
	//https://www.cplusplus.com/reference/vector/vector/assign/	
	//fill assign
	void assign (size_type n, const value_type& val) 
    {
		// clear(0);
		resize(0);
		if (n >= capacity_in_size_t)
			reallocate(n); // dealoc is inside the method
		int i;
		
		i = 0;
		while (i < n) 
		{
			allocator_kind.construct(ptr_first_elem + size_t_not_int, val);
			i++;
		}
		size_t_not_int = n;
		
	}
	
	//range assign
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)      
	{
		if(first > last)
			throw std::logic_error("ft_vector::assign error");
		difference_type distance = last - first;
		resize(0); // may be replaced with clear
		if (distance >= static_cast<difference_type>(capacity_in_size_t))
			reallocate(distance);
		while (first != last) 
		{
			allocator_kind.construct(ptr_first_elem + size_t_not_int, *first);
			size_t_not_int++;
			first++;
		}
	}

	//https://www.cplusplus.com/reference/vector/vector/push_back/
	void push_back (const value_type& val)
	{
		if(size_t_not_int == capacity_in_size_t)
			reallocate(capacity_in_size_t == 0 ? 1 : capacity_in_size_t * 2);
		allocator_kind.construct(ptr_first_elem + size_t_not_int, val);
		size_t_not_int++;
	}

	//https://www.cplusplus.com/reference/vector/vector/pop_back/
	void pop_back()
	{
		allocator_kind.destroy(ptr_first_elem + size_t_not_int - 1);
		size_t_not_int--;
	}
    




	/* */




		
		
			
	};
}

#endif