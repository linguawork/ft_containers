/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_insert.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:31:33 by areggie           #+#    #+#             */
/*   Updated: 2022/05/20 16:16:02 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_vector.hpp"



#define	_vector 			ft::vector
#include "./ft_containers-unit-test/sources/system/system_methods.ipp"
#include "./ft_containers-unit-test/sources/system/lib.hpp"


template <typename T>
std::vector<int> insert_test_2(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(10, 1);

    vector.insert(vector.end() - 5, 2 * 5 , 2); // put at 1000-50= 950 (where), 42000 000 elementov with value 2
    
        std::cout << vector.size() << " here "<< std::endl;
        
        // std::cout << "The vector elements are : ";
        // for(int i=0; i < vector.size(); i++)
        // std::cout << vector.at(i) << ' ';
        // std::cout <<  std::endl;;



    // v.push_back(vector[2121]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> insert_test_2(_vector<T> vector) {
    std::vector<int> v;
    // vector.assign(1000, 1);

    // vector.insert(vector.end() - 50, 4200 * _ratio , 2);
    vector.assign(10, 1);

    vector.insert(vector.end() - 5, 2 * 5 , 2);

    std::cout << vector.size() << " here "<< std::endl;

        std::cout << "The ft_vector elements are : ";
        for(int i=0; i < vector.size(); i++)
        std::cout << vector.at(i) << ' ';
        std::cout <<  std::endl;;

    // v.push_back(vector[2121]);
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());

    
    
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
    
    // std::cout << res1.size() << std::endl;
    // std::cout << res2.size() << std::endl;;

    //     std::cout << "The vector elements are : ";
    //     for(int i=0; i < res1.size(); i++)
    //     std::cout << res1.at(i) << ' ';
    //    std::cout <<  std::endl;;

    //     std::cout << "The vector elements are : ";
    //     for(int i=0; i < res2.size(); i++)
    //     std::cout << res2.at(i) << ' ';
    //     std::cout <<  std::endl;;

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

    exit(run_vector_unit_test<int>("insert(fill)", insert_test_2, insert_test_2));
}

/*
debug success, the bug was in the allocation, I forgot to allocate for NEW_CAPACITY
*/