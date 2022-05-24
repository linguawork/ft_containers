/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   STLbook_iterator_code.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:43:45 by areggie           #+#    #+#             */
/*   Updated: 2022/05/10 17:48:10 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
здесь прописан код из книги по контейнерам для понимания

pdf file книги разделил по главам, затем главе перевел
в текстовый формат через Adobe

got English text, which is pure code


This chapter is about ITERATORS

*/



/*
это шаблонный класс (структура) Итератор
который определяет прототип базового класса 

стр 69 книги
*/
template<class C, class T, class Dist = ptrdiff_t, class Pt= T *, class Rt= T&> 
struct iterator 
{
typedef C iterator_category; // для первого параметра здесь исп-ся iterator_tag
typedef T value_type;
typedef Dist difference_type; 
typedef Pt pointer;
typedef Rt reference;
} ;


/* стр 69 
пустые структруры для определения типа итератора
и все 
сделаны только для определения типа

при создании класса any_iter
можно публично наследоваться от шаблонного класса -прототипа итератора (cм выше) 
*/
struct input_iterator_tag {}; 
struct forward_iterator_tag
	: public input_iterator_tag {}; 
struct bidirectional_iterator_tag
	: public forward_iterator_tag {};
struct randorn_access_iterator_tag
	: public bidirectional_iterator_tag {};


/*
	пример
	создания класса мой итер

	он унаслодовал шаблонный класс итератор
	в котором первым параметром идет тип выбранного итератора:
	forward_iter_tag
*/

class My_it
	:public iterator<forward_iterator_tag, char, long>
{ ... }

/*
создавая свои классы Итераторов
мы можем подавать их как шаблоны 
в функции
пример ниже
Bidirectional_iter
стр 70
*/

template<class Bidit> inline
void reverse(Bidit first, Bidit last)
{
	for (; first != last && first != --last; ++first)
		iter_swap(first, last); 
}

/*

	пример 
	стр 71
	Random_access_iter
	он работает еще быстрее
*/

template<class Ranit> inline
void reverse(Ranit first, Ranit last)
{
	for (; first< last; ++first) 
		iter_swap(first, --last);
}

/*если все итераторы это классы 
то можно использовать перегрузку функций с разным видом итераторов*/

template<class Bidit> inline
	void reverse(Bidit first, Bidit last)
	{Reverse(first, last,
		typename Bidit::iterator_category()); //объявляем прототип метода 

template<class Bidit> inline
	void Reverse(Bidit first, Bidit last, bidirectional_iterator_tag)  // перегрузка для типа bidirecti
	{
		for (; first != last && first != --last; ++first) 
		iter_swap(first, last);
	}

template<class Ranit> inline
	void Reverse(Ranit first, Ranit last, random_access_iterator_tag) // перегрузка для типа RAI
	{
		for (; first < last; ++first) 
			iter_swap(first, --last);
	}

/*

Итераторы могут быть простыми указателями

Для обработки неогранич набора объектов указателей
существует механизм iterator_traits

см стр 72
*/


template<class It>
struct iterator_traits
{
	typedef typename It::iterator_category iterator_category;
	typedef typename It::value_type value_type; 
	typedef typename It::distance_type distance_type; 
	typedef typename It::pointer pointer; 
	typedef typename It::reference reference;
} ;

template<class T>
struct iterator_traits<T *> 
{
typedef random_access_iterator_tag 	iterator_cateogry; 
typedef T 							value_type;
typedef ptrdiff_t 					distance_type; 
typedef T*							pointer;
typedef T& 							reference;
};

/*
about iterator_traits typedef in Russian STL of 98 standard by Stepanov:

шаблонный класс iterator_traits в качестве шаблона принимает итератор и наделяет его полями 
которые уже прописаны в основном итераторе 
Хотя эти поля повторяются важность класса iterator_traits в том что они обеспечивают 
частичную специализацию (partial specialization) КОТОРАЯ ОБРАБАТЫВАЕТ ВСЕ ТИПЫ УКАЗАТЕЛЕЙ
(некоторые компиляторы не поддерживают частичную специализацию)

Эта обработка определяет, что все указатели это итераторы произвольного доступа
(RAI) с типом расстояния ptrdiff_t

Ptrdiff - это целый тип который представляет разницу между любыми двумя объектами-указателями
указывающими на элементы одного массива ( typedef in C library <stddef.h>)
(книга С++ STL , стр 72)

*/



/*
теперь можно 
переписать reverse с iterator_traits
чтобы метод мог работать с указателями

*/

template<class Bidit> inline
	void reverse(Bidlt first, Bidlt last)
	{Reverse(first,last, typename iterator traits<Bidlt>:: iterator_category()); } 
	// псевдоним c учетом обработки iterator_traits

/*
на странице 118 реализация random_iterator
и reverse iterator
*/