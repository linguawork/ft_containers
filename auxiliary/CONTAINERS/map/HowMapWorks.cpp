/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HowMapWorks.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:19:25 by areggie           #+#    #+#             */
/*   Updated: 2022/05/25 16:04:08 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
источник:
     https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/

     пример работы контейнера MAP

     можем подавать в pair рандомные значение для KEY  и для VALUE
     и контейнер отсортирует по значениям ключа

     используем pair и соответственно внутри два итератора для ключа и значения

     UpperBound - первый среди следующих который >

     LowerBound - первый среди следующих, который < =
*/




//CPP Program to demonstrate the implementation in Map
#include <iostream>
#include <iterator>
#include <map>
using namespace std;
  
int main()
{
  
    // empty map container
    map<int, int> gquiz1;
  
    // insert elements in random order
	// we may put keys and values in random order
	// map will sort the keys not the values
    gquiz1.insert(pair<int, int>(1, 40)); // key, value 
    gquiz1.insert(pair<int, int>(4, 30)); // values are random
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(0, 20));
    gquiz1.insert(pair<int, int>(5, 50));
    gquiz1.insert(pair<int, int>(8, 50));
    gquiz1.insert(pair<int, int>(7, 10));
  
    // printing map gquiz1
    map<int, int>::iterator itr;
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) 
	{
				// itr->first prints KEYS after tab
				// itr->second prints VALUES after tab
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
  
    // assigning the elements from gquiz1 to gquiz2
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
  
    // print all elements of the map gquiz2
    cout << "\nThe map gquiz2 after"
         << " assign from gquiz1 is : \n";
    cout << "\tKEY!\tELEMENT!\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
  
    // remove all elements up to
    // element with key=3 in gquiz2
    cout << "\ngquiz2 after removal of"
            " elements less than key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
  
    // remove all elements with key = 4
    int num;
    num = gquiz2.erase(4);
    cout << "\ngquiz2.erase(4) : ";
    cout << num << " removed \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
  
    // lower bound and upper bound for map gquiz1 key = 5
    cout << "gquiz1.lower_bound(5) : "
         << "\tKEY = ";
    cout << gquiz1.lower_bound(5)->first << '\t'; // первое значение следующее после элемента которое < =
    cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second
         << endl;
    cout << "gquiz1.upper_bound(5) : "
         << "\tKEY = ";
    cout << gquiz1.upper_bound(5)->first << '\t'; // первое значение следующее после элемента которое >
    cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second
         << endl;
  
    return 0;
}