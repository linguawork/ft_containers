/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContainerTypes.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:00:59 by areggie           #+#    #+#             */
/*   Updated: 2022/05/25 16:11:50 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




/**************************************************************************
  Источник https://www.youtube.com/watch?v=6OoSgY6NVVk


	SET

	source:	https://en.cppreference.com/w/cpp/container/set#:~:text=std%3A%3Aset%20is%20an,implemented%20as%20red%2Dblack%20trees
	Это класс который принимает шаблон ключ, выделяет под него память и сортирует
	
	std::set is an associative container that contains a sorted set of unique objects of type Key.
	Sorting is done using the key comparison function Compare. 
	Search, removal, and insertion operations have logarithmic complexity. 
	Sets are usually implemented as red-black trees
	
	в 98 стандарте
	
*/

	template<
    class Key, // ключ
    class Compare = std::less<Key>, // для сортировки ключа
    class Allocator = std::allocator<Key> // выделение памяти под ключ
> class set;


// класс принимает три шаблона и работает обычно на красном черном дереве
	template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > 
	class set;







/********************************************
MAP 


std::map is a sorted associative container that contains key-value pairs with unique keys. 
Keys are sorted by using the comparison function Compare. 
Search, removal, and insertion operations have logarithmic complexity. (O (log)N) - логорифмическая сложность 
т,е можем проходить по дереву несколько раз

Maps are usually implemented as red-black trees.

*/
// 98 std
template<
    class Key, //ключ
    class T, // значение
    class Compare = std::less<Key>, // упорядочивание
    class Allocator = std::allocator<std::pair<const Key, T> > // выделение памяти под ключ и значение
> class map;