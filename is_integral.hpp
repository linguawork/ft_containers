/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:28:36 by areggie           #+#    #+#             */
/*   Updated: 2022/05/06 19:40:46 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP


namespace ft
{

	/*
	реализация enable_if для типа данных в конструкторе vector, который с итератором
	одна структура может наследоваться от другой (по умолчанию наследование public для структур)
	*/
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
	struct is_integral : public ft::integral_constant<T, false> //by default false, the key word public may be omitted
	//https://stackoverflow.com/questions/979211/struct-inheritance-in-c#:~:text=Yes.,inheritance%20is%20public%20by%20default.
	// The inheritance is public by default.
	{
		
	};

	template <> //this is template specialization
	struct is_integral<bool> : public ft::integral_constant<bool, true> 
	{

	};

	template <> 
	struct is_integral<char> : public ft::integral_constant<bool, true> // if is_integral datatype is char, 
	//then true is returned in integral_constant
	{
		
	};
	
	template <> 
	struct is_integral<signed char>	: public ft::integral_constant<bool, true> 
	{
		
	};
	
	template <> 
	struct is_integral<unsigned char> : public ft::integral_constant<bool, true> 
	{
		
	};
	
	template <>
	struct is_integral<wchar_t>	: public ft::integral_constant<bool, true> 
	{

	};
	
	// template <> 
	// struct is_integral<char16_t> : public ft::integral_constant<bool, true> 
	// {
		
	// };
	
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
	struct is_integral<unsigned long long> : public ft::integral_constant<bool, true> 
	{
		
	};


}

#endif

