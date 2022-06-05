/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simpleEnable_if2.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:44:41 by areggie           #+#    #+#             */
/*   Updated: 2022/04/13 19:14:04 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
источник:
https://www.youtube.com/watch?v=H-m23Vvzcug

код автора доступен здесь:
https://github.com/schostac/CppIdioms/blob/master/EnableIf/enableif.cpp 

Оказывается автор продает свой курс на Udemy: 
https://www.udemy.com/course/cpp-in-detail-common-idioms/

код по стандарту С++11

*/

#include <iostream>
#include <type_traits>

/*
 * Enable-if
 * It is used to allow function overloading based on 
 * arbitrary properties of type. Relies on SFINE
 * (if invalid argument or return type is formed during 
 * instantiation of function template, the instantiation 
 * is removed instead of compilation error).
 * Often used in C++ template metaprogramming, 
 * Boost libraries, and C++ STL.
 */


/*
	если убрать функцию foo для signed, то работать будет только с версией функции foo для unsigned
*/

// template <class T>
// void foo(T) { 
//     std::cout << "T is signed" << std::endl; 
// }

template <class T, class = typename std::enable_if<std::is_unsigned<T>::value>::type>
void foo(T) {
    std::cout << "T is unsigned" << std::endl; 
}


struct A {};

struct B : A {};

template<class T, class = typename std::enable_if<std::is_base_of<A, T>::value>::type>
struct C: T {};


int main()
{
    unsigned int x = 5;
    foo(x);

    C<B> c;

    return 0;
}