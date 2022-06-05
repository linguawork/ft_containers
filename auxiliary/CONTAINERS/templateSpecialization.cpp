/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templateSpecialization.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:53:24 by areggie           #+#    #+#             */
/*   Updated: 2022/04/14 22:00:14 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

 Специализация шаблонов (типа перегрузка шаблон - классов под определенные типы 
данных)

a few sources of code:

https://www.youtube.com/watch?v=_kJJoWDNvxM (good video of code in Russian)

https://www.geeksforgeeks.org/template-specialization-c/ (good examples of code)

https://ravesli.com/urok-178-yavnaya-spetsializatsiya-shablona-klassa/ (not the best examples)


https://en.cppreference.com/w/cpp/language/template_specialization (theory)


*/

#include <iostream>
using namespace std;

template <class T>
void fun(T a)
{
cout << "The main template fun(): "
		<< a << endl;
}

template<>
void fun(int a)
{
	cout << "Specialized Template for int type: "
		<< a << endl;
}

int main()
{
	fun<char>('a');
	fun<int>(10);
	fun<float>(10.14);
}


