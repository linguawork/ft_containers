/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:26:38 by areggie           #+#    #+#             */
/*   Updated: 2022/05/19 18:40:12 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_VECTOR_HPP // defining HEADER
#define FT_VECTOR_HPP
#include <memory> //std::allocator  //
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
			//  return(*(ptr_first_elem + n));
			return ( *( this->ptr_first_elem + n ) );
		}

		void check_boundaries( size_type position ) const {
			if (position < 0 || position >= size() )
				throw ::std::out_of_range( "ft::vector::at() out of range" );
		}	

		reference at( size_type position ) 
		{
			check_boundaries( position );
			// return ( ( *this )[position] );
			return(this->ptr_first_elem[position]);
		}

		const_reference at( size_type position ) const
		{
			check_boundaries( position );
			return(this->ptr_first_elem[position]);
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
			// clear();
			resize(0);
			if (n >= capacity_in_size_t)
				reallocate(n); // dealoc is inside the method
			// int i;
			
			// i = 0;
			while (size_t_not_int < n) 
			{
				allocator_kind.construct(ptr_first_elem + size_t_not_int, val);
				size_t_not_int++;
			}
			// size_t_not_int = n;
			// for (;size_t_not_int < n;) {
			// 	allocator_kind.construct(ptr_first_elem + size_t_not_int, val);
			// 	size_t_not_int++;
			// }
			
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
		
		//this is to make insert() work
		//we can not use std::uninitialized_copy but we can write our own
		//https://en.cppreference.com/w/cpp/memory/uninitialized_copy
		//https://stackoverflow.com/questions/9727556/is-uninitialized-copy-fillin-first-in-last-for-dest-a-a-an-oversight-in-th
		template<class InputIt, class _ForwardIterator>
		_ForwardIterator uninitialized_copy(InputIt first, InputIt last, _ForwardIterator d_first)
		{
			typedef typename ft::iterator_traits<_ForwardIterator>::value_type value_type;  // through iterator_traits I typedefed VALUE_TYPE
			_ForwardIterator current = d_first;
			try {
				for (; first != last; ++first, (void) ++current) 
						allocator_kind.construct (&*current, *first);	
				return current;
			} 
			catch (...) 
			{
				for (; d_first != current; ++d_first) 
					d_first->~value_type();
				throw;
			}
		}


		//https://www.cplusplus.com/reference/vector/vector/insert/
		// single element (1)	iterator insert (iterator position, const value_type& val);	
		// fill (2)	void insert (iterator position, size_type n, const value_type& val);
		// range (3) template <class InputIterator>
		// 			void insert (iterator position, InputIterator first, InputIterator last);
		
		// single element (1)	
		iterator insert (iterator position, const value_type& val)
		{
			if (position < begin() || position > end())
				throw std::logic_error("vector position error when inserting a single element");
			difference_type location = position - begin(); // разница
			if (size_t_not_int >= capacity_in_size_t)
			{
				capacity_in_size_t *= 2;
				pointer new_vec = allocator_kind.allocate(capacity_in_size_t); // malloc of size
				//https://www.cplusplus.com/reference/memory/uninitialized_copy/ (see above)
				uninitialized_copy(begin(), position, iterator(new_vec)); //give memory from at pos (start(begin) to finish (position), insert new vec size
					allocator_kind.construct(new_vec + location, val); // at the correct pos create a new obj for 1 val
				uninitialized_copy(position, end(), iterator(new_vec + location + 1)); // from pos to end inserted new vec size + 1 elem (inserted elem)
				for (size_t i = 0; i < size_t_not_int; i++)
					allocator_kind.destroy(ptr_first_elem + i); // destructor
				if(size_t_not_int)
					allocator_kind.deallocate(ptr_first_elem, size_t_not_int); // free
				size_t_not_int++;
				ptr_first_elem = new_vec;
			}
			else // if the capacity is enough
			{
				for (size_type i = size_t_not_int; i > static_cast<size_type>(location); i--)
				{
					allocator_kind.destroy(ptr_first_elem + i); // destruct
					allocator_kind.construct(ptr_first_elem + i, *(ptr_first_elem + i - 1)); // reconstruct by moving to right
				}
				allocator_kind.destroy(&(*position)); //destruct what is inside the pos
				allocator_kind.construct(&(*position), val); // construct new elem
				size_t_not_int++; // + 1 elem
			}
			return (begin() + location);//
		}

		// fill (2)	void insert (iterator position, size_type n, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val)
		{
			if (n == 0)
				return ;
			else if (max_size() - size_t_not_int < n)
				throw std::length_error("vector length error in fill type insert()");
			difference_type start = position - begin();
			if (size_t_not_int + n > capacity_in_size_t)
			{
				size_type new_capacity = capacity_in_size_t * 2 >= size_t_not_int + n ? capacity_in_size_t * 2 : size_t_not_int + n;
				pointer new_vec = allocator_kind.allocate(capacity_in_size_t);
				uninitialized_copy(begin(), position, iterator(new_vec));
				for (size_type i = 0; i < n; i++)
					allocator_kind.construct(new_vec + start + i, val);
				uninitialized_copy(position, end(), iterator(new_vec + start + n));
				for (size_type i = 0; i < size_t_not_int; i++)
					allocator_kind.destroy(ptr_first_elem + i);
				allocator_kind.deallocate(ptr_first_elem, capacity_in_size_t);
				size_t_not_int += n;
				capacity_in_size_t = new_capacity;
				ptr_first_elem = new_vec;
			}
			else // if the capacity is enough
			{
				for (size_type i = size_t_not_int; i > static_cast<size_type>(start); i--) // bigger than diff
				{
					allocator_kind.destroy(ptr_first_elem + i + n - 1); // destruct one by one
					allocator_kind.construct(ptr_first_elem + i + n - 1, *(ptr_first_elem + i - 1));//put over
				}
				for (size_type i = 0; i < n; i++) //
				{
					allocator_kind.destroy(ptr_first_elem + i + start);
					allocator_kind.construct(ptr_first_elem + i + start, val); // запись на n
				}
				size_t_not_int += n; // increase
			}
		}

		// range (3) template <class InputIterator>
		// 			void insert (iterator position, InputIterator first, InputIterator last);
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
			typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{
			if (position < begin() || position > end() || first > last)
				throw std::logic_error("vector: error in range insert()");
			size_type start = static_cast<size_type>(position - begin());
			size_type count = static_cast<size_type>(last - first);
			if (size_t_not_int + count > capacity_in_size_t)
			{
				size_type new_capacity = capacity_in_size_t * 2 >= size_t_not_int + count ? capacity_in_size_t * 2 : size_t_not_int + count;
				pointer new_vec = allocator_kind.allocate(new_capacity);
				uninitialized_copy(begin(), position, iterator(new_vec));
				try
				{
					for (size_type i = 0; i < static_cast<size_type>(count); i++, first++)
						allocator_kind.construct(new_vec + start + i, *first);
				}
				catch (...)
				{
					for (size_type i = 0; i < count + start; ++i)
						allocator_kind.destroy(new_vec + i);
					allocator_kind.deallocate(new_vec, new_capacity);
					throw;
				}
				uninitialized_copy(position, end(), iterator(new_vec + start + count));
				for (size_type i = 0; i < size_t_not_int; i++)
					allocator_kind.destroy(ptr_first_elem + i);
				allocator_kind.deallocate(ptr_first_elem, capacity_in_size_t);
				size_t_not_int += count;
				capacity_in_size_t = new_capacity;
				ptr_first_elem = new_vec;
			}
			else
			{
				for (size_type i = size_t_not_int; i > static_cast<size_type>(start); i--)
				{
					allocator_kind.destroy(ptr_first_elem + i + count - 1);
					allocator_kind.construct(ptr_first_elem + i + count - 1, *(ptr_first_elem + i - 1));
				}
				for (size_type i = 0; i < static_cast<size_type>(count); i++, first++)
				{
					allocator_kind.destroy(ptr_first_elem + i + count);
					allocator_kind.construct(ptr_first_elem + start + i, *first);
				}
				size_t_not_int += count;
			}
		}

		iterator erase (iterator position) 
		{
			pointer temp = &(*position);

			if (position + 1 == end()) {
				allocator_kind.destroy(&(*position));
			}
			else {
				difference_type dist = end() - position;

				for (int i = 0; i < dist - 1; i++){
					allocator_kind.construct(&(*position) + i, *(&(*position) + i + 1));
					allocator_kind.destroy(&(*position) + i + 1);
				}
			}
			size_t_not_int--;

			return (iterator(temp));
		}

		iterator erase (iterator first, iterator last) 
		{
			iterator iter = begin();
			difference_type start = first - iter;
			size_type size = last - first;
			size_type counter = start;
			for (; counter < start + size; counter++) {
				allocator_kind.destroy(ptr_first_elem + counter);
				size_t_not_int--;
			}
			size_type cnt = 0;
			for (size_type i = start; i < size_t_not_int; i++) {
				allocator_kind.construct(&ptr_first_elem[i], ptr_first_elem[counter + cnt]);
				allocator_kind.destroy(&ptr_first_elem[counter + cnt]);
				cnt++;
			}
			return (iterator(last));
		}


		
		void swap (vector& x) 
		{
			if (*this == x)
				return;

			pointer ptr_first_elem_tmp = x.ptr_first_elem;
			size_type capacity_in_size_t_tmp = x.capacity_in_size_t;
			size_type size_t_not_int_temp = x.size_t_not_int;
			allocator_type allocator_kind_temp = x.allocator_kind;

			x.ptr_first_elem = ptr_first_elem;
			x.capacity_in_size_t = capacity_in_size_t;
			x.size_t_not_int = size_t_not_int;
			x.allocator_kind = x.allocator_kind;

			ptr_first_elem = ptr_first_elem_tmp;
			capacity_in_size_t = capacity_in_size_t_tmp;
			size_t_not_int = size_t_not_int_temp;
			allocator_kind = allocator_kind_temp;
		}

		
		void clear() 
		{
			resize(0);
		}
		//get allocator, call allocator_type inside the original Allocator

		allocator_type get_allocator() const
		{
			return(allocator_type()); //we use () to show that there should be value
		}




	};

	//relational operators
	//https://www.cplusplus.com/reference/vector/vector/operators/
	// non member methods, operator of class comparison
	// this is need for swap ==
	template< class T, class Alloc >
	bool operator==( const ft::vector<T, Alloc>& lhs,
					 const ft::vector<T, Alloc>& rhs ) {
		if (lhs.size() == rhs.size()) {
			for (size_t i = 0; i < lhs.size(); i++) {
				if (lhs[i] != rhs[i])
					return (false);
			}
			return (true);
		}
		return (false);
	}

		template<class T, class Alloc>
	bool operator!=(const ft::vector<T,Alloc>& lhs,
					 const ft::vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	//https://www.cplusplus.com/reference/algorithm/lexicographical_compare/

	/*
	*/
	template<class T, class Alloc>
	bool operator<(const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
	bool operator>(const ft::vector<T,Alloc>& lhs,
					const ft::vector<T,Alloc>& rhs) {
		return (rhs < lhs); // make it the other way and it is wrong
	}

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T,Alloc>& lhs,
					 const ft::vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}
	
	template<class T, class Alloc>
	bool operator>=(const ft::vector<T,Alloc>& lhs,
					 const ft::vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}
}

#endif