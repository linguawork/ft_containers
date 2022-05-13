/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:32:02 by areggie           #+#    #+#             */
/*   Updated: 2022/05/13 17:08:27 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
vector main sample from
https://www.cplusplus.com/reference/vector/vector/vector/

*/

//explanation of ptr_diff in the library
#include <stddef.h>

// constructing vectors
#include <iostream>
#include "ft_vector.hpp"

// for running tests
#include <iterator> // for printing out vector contents
#include <vector> // for comparative test



int main ()
{
  // constructors used in the same order as described above:
  // std::vector<int> first;                                // empty vector of ints
  // std::vector<int> second (4,100);                       // four ints with value 100
  // std::vector<int> third (second.begin(),second.end());  // iterating through second
  // std::vector<int> fourth (third);                       // a copy of third

  // ft::vector<int> first;                                // empty vector of ints
  // ft::vector<int> second (4,100);                       // four ints with value 100
  // ft::vector<int> third (second.begin(),second.end());  // iterating through second
  // ft::vector<int> fourth (third);                       // a copy of third


      ft::vector<int> first_obj; //test for default constructor
      ft::vector<int> second (4,100);//test for constructor with values in vector
        // std::vector<int> second (4,100); 
        // printf("%d", second[0]);// 32 (4 x 8)

      
      ft::vector<int> third (5,20);
      ft::vector<int> fourth (third);// a copy of third
      

  // the iterator constructor can also be used to construct from arrays:
  // this is the test for range constructor
	// int myints[] = {16,2,77,29};
	// std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	// ft::vector<int> my_fifth (myints, myints + sizeof(myints) / sizeof(int) );

	// std::cout << "The contents of std::vector are:";
	// for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// std::cout << "The contents of my::vector are:";
	// for (ft::vector<int>::iterator my_it = my_fifth.begin(); my_it != my_fifth.end(); ++my_it)
	// 	std::cout << ' ' << *my_it;
	// std::cout << '\n';
        

      
  return 0;
}