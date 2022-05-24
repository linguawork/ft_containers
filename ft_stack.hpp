/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:52:48 by areggie           #+#    #+#             */
/*   Updated: 2022/05/24 15:43:54 by areggie          ###   ########.fr       */
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

		stack( const container_type &cont_ = container_type() );
		stack( const stack &src_ );
		stack	&operator=( const stack &rhs_ );

		~stack( void );

		reference			top( void );
		const_reference		top( void ) const;

		bool 				empty( void ) const;
		size_type 			size( void ) const;

		void 				push( const value_type &val_ );
		void 				pop( void );

	protected:
		container_type		c;
	private:
		template<typename T_, typename Cont_>
		friend bool
		operator==( const stack<T_,Cont_> &, const stack<T_,Cont_> & );

		template<typename T_, typename Cont_>
		friend bool
		operator<( const stack<T_,Cont_> &, const stack<T_,Cont_> & );
	};

	/************************* * Implementation: * *************************/

	template<typename T, typename Container>
	stack<T,Container>::stack( const container_type &cont_ ) : c( cont_ ) 
	{
		
	}

	template<typename T, typename Container>
	stack<T,Container>::stack( const stack &src_ ) : c( src_.c ) 
	{
		
	}

	template<typename T, typename Container>
	stack<T,Container>& stack<T,Container>::operator=( const stack<T,Container> &rhs_ ) //return value
	{
		if (this != &rhs_) 
			this->c = rhs_.c;
		return ( *this );
	}

	template<typename T, typename Container>
	stack<T,Container>::~stack( void ) // namespace of destructor
	{
		
	}

	template<typename T, typename Container>
	typename stack<T,Container>::reference stack<T,Container>::top( void ) // return_data_type namespace,where the method is, method
	{
		return ( this->c.back() );
	}

	template<typename T, typename Container>
	typename stack<T,Container>::const_reference stack<T,Container>::top( void ) const
	{
		return ( this->c.back() );
	}

	template<typename T, typename Container>
	bool stack<T,Container>::empty( void ) const 
	{
		return ( this->c.empty() );
	}

	template<typename T, typename Container> // templates to work with
	typename stack<T,Container>::size_type /* returning data_type */ stack<T,Container>::size( void ) const /*location of the method*/
	{
		return ( this->c.size() );
	}

	template<typename T, typename Container>
	void stack<T,Container>::push( const value_type &val_ ) 
	{
		this->c.push_back( val_ );
	}

	template<typename T, typename Container>
	void stack<T,Container>::pop( void ) 
	{
		this->c.pop_back();
	}

	/*	
	Compares the contents of the underlying containers of two container
	adaptors. 
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