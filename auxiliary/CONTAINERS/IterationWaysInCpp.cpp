/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterationWaysInCpp.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:48:33 by areggie           #+#    #+#             */
/*   Updated: 2022/04/11 15:48:35 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
в лекции англичанина о контейнерах: https://www.youtube.com/watch?v=6OoSgY6NVVk
на 9:28 увидел интересный способ итерации по массиву 
и нашел несколько способов на сайте https://en.cppreference.com/w/cpp/language/range-for 
код ниже

Но не все могут скомпилиться

Такой способ итерации скорее всего введен после стандарта 98
*/

#include <iostream>
#include <vector>
 
int main() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5};
 
    for (const int& i : v) // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (auto i : v) // access by value, the type of i is int
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (auto&& i : v) // access by forwarding reference, the type of i is int&
        std::cout << i << ' ';
    std::cout << '\n';
 
    const auto& cv = v;
 
    for (auto&& i : cv) // access by f-d reference, the type of i is const int&
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (int n : {0, 1, 2, 3, 4, 5}) // the initializer may be a braced-init-list
        std::cout << n << ' ';
    std::cout << '\n';
 
    int a[] = {0, 1, 2, 3, 4, 5};
    for (int n : a) // the initializer may be an array
        std::cout << n << ' ';
    std::cout << '\n';
 
    for ([[maybe_unused]] int n : a)  
        std::cout << 1 << ' '; // the loop variable need not be used
    std::cout << '\n';
 
    for (auto n = v.size(); auto i : v) // the init-statement (C++20)
        std::cout << --n + i << ' ';
    std::cout << '\n';
 
    for (typedef decltype(v)::value_type elem_t; elem_t i : v)
    // typedef declaration as init-statement (C++20)
        std::cout << i << ' ';
    std::cout << '\n';
 
#   if __cplusplus > 23'00 + 200000
    for (using elem_t = decltype(v)::value_type; elem_t i : v)
    // alias declaration as init-statement, same as above (C++23)
        std::cout << i << ' ';
    std::cout << '\n';
#   endif
}