/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_swap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:32:57 by areggie           #+#    #+#             */
/*   Updated: 2022/05/22 17:12:52 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"



#define	_vector 			ft::vector
#include "./ft_containers-unit-test/sources/system/system_methods.ipp"
#include "./ft_containers-unit-test/sources/system/lib.hpp"


template <typename T>
std::vector<int> swap_test(std::vector<T> vector) // подаем вектор и возвращаем вектор
{
    std::vector<int> v; // создаем новый вектор

    vector.assign(1100 * _ratio, 11); // в подаваемый вектор засовываем 11000 000 elem cо знач 11

    std::vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
	//tmp with 5 000 000 эл по 5
	//tmp2 with 10 000 000 по 10
	//tmp3 with 15 000 000 по 15
	//tmp4 with 30 000 000 по 30


    // g_start1 = timer();

    v.push_back(vector[2]); //добавили 3 эл из vector ( 11 mlm el with 11) - первый элемент v [11]
    v.push_back(vector.size()); // добавили размер 11 mln как элемент - втор элемент [11 000 000]
    v.push_back(vector.capacity()); // вместимость как элемент - третий элемент [cаpacity]

    long *adr1 = reinterpret_cast<long *>(&vector); // создали указатель типа лонг на адрес vector with 11 mln with 11
    long *adr2 = reinterpret_cast<long *>(&tmp); // создали указатель типа лонг на адрес tmp with 5 mln elements with 5
    vector.swap(tmp);// обмен значениями, tmp должен иметь 11 млн элем по 11 и vector 5 млн по 5

	// если указатели создались успешно
    if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2) 
    	v.push_back(1); // добавляем 4й элемент [1]
    v.push_back(vector[2]); // 5ый элемент [5]
    v.push_back(vector.size()); // 6ый элемент [5 000 000]
    v.push_back(vector.capacity()); // 7ой элемент [cаpacity - 5 млн с лишним]
    vector.swap(tmp3); //vector обменял элементы на 15 mln по 15 и отдал 5 mln по 5 
    v.push_back(vector[2]); //8ой элемент [15]
    v.push_back(vector.size()); // 9 -  [15 000 000]
    v.push_back(vector.capacity()); // 10 - [15 000 000]
    std::swap(vector, tmp2); // 15 млн по 15 поменял на 10 млн по 10
    v.push_back(vector[2]); //11 элемент - [10]
    v.push_back(vector.size()); //12 - [10 000 000]
    v.push_back(vector.capacity()); // 13 - [10 000 000]!!!
    std::swap(vector, tmp4);  // vector принял 30mln по 30
    // g_end1 = timer();
    v.push_back(vector[2]); // 14 элемент - [30]
    v.push_back(vector.size()); // 15 - [30 000 000]
    v.push_back(vector.capacity()); // 16 - [capacity]
    return v;
}
//  11, 11000000, 11000000, 1, 5, 5000000, 5000000, 15, 15000000, 15000000, 10, 1000000, 10000000, 30, 30000000, 30000000



template <typename T>
std::vector<int> swap_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(1100 * _ratio, 11);
    _vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);
    // g_start2 = timer();
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    long *adr1 = reinterpret_cast<long *>(&vector);
    long *adr2 = reinterpret_cast<long *>(&tmp);
    vector.swap(tmp);
    if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
    	v.push_back(1);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.swap(tmp3);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::swap(vector, tmp2);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());// 13 - [10 000 000]!!!
    std::swap(vector, tmp4);
    // g_end2 = timer();
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}


template <class T>
int run_vector_unit_test(std::string test_name, std::vector<int> (func1)(std::vector<T>), std::vector<int> (func2)(_vector<T>)) {
    int    result;
    int    leaks;
    time_t t1;
    time_t t2;
    std::vector<int > res1;
    std::vector<int > res2;
    std::vector<int> vector;
    _vector<int> my_vector;

	printElement(test_name);
	res1 = func1(vector);
	res2 = func2(my_vector);
    
    std::cout << res1.size() << std::endl;
    std::cout << res2.size() << std::endl;;

        std::cout << "The vector elements are : ";
        for(int i=0; i < res1.size(); i++)
        std::cout << res1.at(i) << ' ';
       std::cout <<  std::endl;;

        std::cout << "The ft_vect elements are: ";
        for(int i=0; i < res2.size(); i++)
        std::cout << res2.at(i) << ' ';
        std::cout <<  std::endl;;

	if (res1 == res2) {
	    printElement("OK");
	    result = 0;
	}
	else {
	    printElement("FAILED");
	    result = 1;
	}
	t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;
	(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);
	(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);
	leaks = leaks_test(getpid());
	cout << endl;

	return !(!result && !leaks);
}



int main() {

    exit(run_vector_unit_test<int>("swap()", swap_test, swap_test));
}