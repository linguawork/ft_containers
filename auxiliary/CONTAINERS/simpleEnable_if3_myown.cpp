/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simpleEnable_if3_myown.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:44:41 by areggie           #+#    #+#             */
/*   Updated: 2022/04/13 21:17:55 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
МЕТАпрограммирование на этапе компиляции (enable if)

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
    написал свои структуры EnableIf с булевым параметром
    и подключил их ниже вместо std::enable_if
*/

template<bool>
struct EnableIf{}; // структура для всех других случаев кроме true

template<>
struct EnableIf<true> // explicit expression of value true, структура для случая true 
// если
{
    using type = void;  
};


template <class T> // для инта или других типов
void foo(T) { 
    std::cout << "T is signed" << std::endl; 
}

template <class T, class = typename EnableIf<std::is_unsigned<T>::value>::type>  // EnableIf (если у нас unsigned то 
//будет выбрана структура EnabledIf c параметром true и из структуры будет получен type = void )
// иначе false
void foo(T) {
    std::cout << "T is unsigned" << std::endl; 
}


struct A {};

struct B : A {};

template<class T, class = typename EnableIf<std::is_base_of<A, T>::value>::type>
struct C: T {};


int main()
{
    int x = 5;  // EnableIf cработает только если будет unsigned int 
    // unsigned int x = 5;  // EnableIf cработает только если будет unsigned int  (нужно будет закомментить версию для инта)
    foo(x); 

    C<B> c;

    return 0;
}