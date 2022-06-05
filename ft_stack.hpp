/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:52:48 by areggie           #+#    #+#             */
/*   Updated: 2022/06/05 17:03:07 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP

#include "ft_vector.hpp"

namespace ft {

	template<typename T, typename Container = ft::vector<T> >
	class stack {
	public:
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;
		typedef	Container								container_type;


	explicit stack( const container_type &cont_ = container_type()) : c( cont_ ) 
	{
		
	}

	stack( const stack &src_ ) : c( src_.c ) 
	{
		
	}

	stack<T,Container>& operator=( const stack<T,Container> &rhs_ ) //return value
	{
		if (this != &rhs_) 
			this->c = rhs_.c;
		return ( *this );
	}

	~stack( void ) // namespace of destructor
	{
		
	}

	typename stack<T,Container>::reference top( void ) // return_data_type namespace,where the method is, method
	{
		return ( this->c.back() );
	}

	typename stack<T,Container>::const_reference top( void ) const
	{
		return ( this->c.back() );
	}

	bool empty( void ) const 
	{
		return ( this->c.empty() );
	}

	typename stack<T,Container>::size_type /* returning data_type */ size( void ) const /*location of the method*/
	{
		return ( this->c.size() );
	}

	void push( const value_type &val_ ) 
	{
		this->c.push_back( val_ );
	}

	void pop( void ) 
	{
		this->c.pop_back();
	}

	protected:
		container_type	c; // init
	// if we dont add private friend methods of compare, we can not access protected c in the class
	// so we need to have friend prototypes which will call for the methods outside the class 
	private:
		template<typename T_, typename Cont_>
		friend bool
		operator==( const stack<T_,Cont_> &, const stack<T_,Cont_> & );

		template<typename T_, typename Cont_>
		friend bool
		operator<( const stack<T_,Cont_> &, const stack<T_,Cont_> & );
	};


	/*
	Non member functions	
	comparison operators
	*/

	template<typename T, typename Cont>
	inline bool operator==( const stack<T,Cont> &lhs, const stack<T,Cont> &rhs ) 
	{
		return ( lhs.c == rhs.c );
	}

	template<typename T, typename Cont>
	inline bool operator!=( const stack<T,Cont> &lhs, const stack<T,Cont> &rhs ) 
	{
		return ( !( lhs == rhs ) );
	}

	template<typename T, typename Cont>
	inline bool operator<( const stack<T,Cont> &lhs, const stack<T,Cont> &rhs ) 
	{
		return ( lhs.c < rhs.c );
	}

	template<typename T, typename Cont>
	inline bool operator>( const stack<T,Cont> &lhs, const stack<T,Cont> &rhs )
	{
		return ( rhs < lhs );
	}

	template<typename T, typename Cont>
	inline bool operator<=( const stack<T,Cont> &lhs, const stack<T,Cont> &rhs ) 
	{
		return ( !( rhs < lhs ) );
	}

	template<typename T, typename Cont>
	inline bool operator>=( const stack<T,Cont> &lhs, const stack<T,Cont> &rhs ) 
	{
		return ( !( lhs < rhs ) );
	}

}

#endif