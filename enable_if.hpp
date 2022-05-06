/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:29:49 by areggie           #+#    #+#             */
/*   Updated: 2022/05/06 14:28:31 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

/*
https://www.cplusplus.com/reference/type_traits/enable_if/


Declared as:
template <bool Cond, class T = void> struct enable_if {};


Somekind of switcher. 

If the condition is true, then some code is activated
if not, the code is ignored

The is the class of std::type_traits library (since std++11)
I need to implement it myself (cause we work only acc std++98)

*/


namespace ft
{
	
	//otherwise = false, it is just an empty structure
	template<bool Cond, class T = void>
	struct enable_if 
	{

	};

	//the true Condition
	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

}
#endif
