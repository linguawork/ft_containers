/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:32:02 by areggie           #+#    #+#             */
/*   Updated: 2022/05/15 19:25:30 by areggie          ###   ########.fr       */
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
    // CONSTRUCTOR TESTS used in the same order as described above:
  {
    
      std::cout << "\n" <<"all constructors test" << "\n";
      ft::vector<int> first_obj; //test for default constructor
      ft::vector<int> second (4,100);//test for constructor with values in vector
        // std::vector<int> second (4,100); 
        // printf("%d", second[0]);// 32 (4 x 8)
      ft::vector<int> third (5,20);
      ft::vector<int> fourth (third);// test for copy constructor of third works
      

      // the iterator constructor can also be used to construct from arrays:
      //this is the test for range constructor
      int myints[] = {16,2,77,29};
      std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
      ft::vector<int> my_fifth (myints, myints + sizeof(myints) / sizeof(int) );

      std::cout << "The contents of std::vector are:";
      for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';

      // lack of begin() and end() functions to iterate
      std::cout << "The contents of my ft::vector are:";
      for (ft::vector<int>::iterator my_it = my_fifth.begin(); my_it != my_fifth.end(); ++my_it)
        std::cout << ' ' << *my_it;
      std::cout << '\n';
  }


  //test for reverse_iterator class 
  //rbegin, rend() methods need reverse_iterator
  //https://www.cplusplus.com/reference/vector/vector/rbegin/
  {
       std::cout << "\n"  << "rbegin(), rend() test" << "\n";
      ft::vector<int> myvector (5);  // 5 default-constructed ints

      int i=0;

      ft::vector<int>::reverse_iterator rit = myvector.rbegin();
      for (; rit!= myvector.rend(); ++rit) // putting from the end (which is start) - запись с конца
      // нулевой элемент[] справа 
      *rit = ++i;

      std::cout << "my ft_vector contains:";
      for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      std::cout << ' ' << *it;
      std::cout << '\n';
    }

    /*******************CAPACITY PART TESTS**********************************/
    
    //test for size() https://www.cplusplus.com/reference/vector/vector/size/
    {
       std::cout << "\n" << "size() test" << "\n";
      
      ft::vector<int> myints;
      std::cout << "0. size: " << myints.size() << '\n';

      ft::vector<int> myvector (5);
      std::cout << "0. size: " << myvector.size() << '\n';

      // for (int i=0; i<10; i++) myints.push_back(i);
      // std::cout << "1. size: " << myints.size() << '\n';

      // myints.insert (myints.end(),10,100);
      // std::cout << "2. size: " << myints.size() << '\n';

      // myints.pop_back();
      // std::cout << "3. size: " << myints.size() << '\n';
      
    }


    // test for max_size() https://www.cplusplus.com/reference/vector/vector/max_size/
    {
        std::cout << "\n" << "max_size() test" << "\n";
        // set some content in the vector:   
        ft::vector<int> myvector (4,100);
        std::cout << "size: " << myvector.size() << "\n";
        std::cout << "max_size: " << myvector.max_size() << "\n";
    }


    //test for resize() https://www.cplusplus.com/reference/vector/vector/resize/
    {
      std::cout << "\n" << "resize() test" << "\n";
        // set some content in the vector:   
      ft::vector<int> myvector; // no elements inside

        myvector.resize(5); //5 zeros
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
        
        myvector.resize(8,100); // added 3 elem of value 100 over 5
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
        
        myvector.resize(12, 3); // added 4 elem of value 3 over 8
        std::cout << "myvector contains:";
        for (int i=0;i<myvector.size();i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }


    //https://www.cplusplus.com/reference/vector/vector/capacity/
    {
      std::cout << "\n" << "capacity() test" << "\n";
      
      ft::vector<int> myvector (99, 5);
      std::vector<int> myvector2 (99, 5);

      // need to check with push_back()

      std::cout << "size: " << (int) myvector.size() << '\n';
      std::cout << "capacity: " << (int) myvector.capacity() << '\n';
      std::cout << "max_size: " <<  myvector.max_size() << '\n'; //when we cast to int, we get -1

      std::cout << "size: " << (int) myvector2.size() << '\n';
      std::cout << "capacity: " << (int) myvector2.capacity() << '\n';
      std::cout << "max_size: " <<  myvector2.max_size() << '\n'; //when we cast to int we get -1
    }


    //https://www.cplusplus.com/reference/vector/vector/empty/
    {
      std::cout << "\n" << "empty() test" << "\n";
        // std::vector<int> myvector;
        // int sum (0);
        
        ft::vector<int> myvector (100, 5);
        ft::vector<int> myvector2;
        // std::vector<int> myvector (100, 5);
        // std::vector<int> myvector2;

        // for (int i=1;i<=10;i++) myvector.push_back(i);

        if (!myvector.empty())
        {
          std::cout << "vector is not empty\n" << std::endl;
        }
        else
          std::cout << "vector is empty\n" << std::endl;

        if (!myvector2.empty())
        {
          std::cout << "vector2 is not empty\n" << std::endl;
        }
        else
          std::cout << "vector2 is empty\n" << std::endl;

        // std::cout << "total: " << sum << '\n';
      
    }


  //https://www.cplusplus.com/reference/vector/vector/reserve/
    {
      std::cout << "\n" << "reserve() test" << "\n";
      ft::vector<int>::size_type sz;
      
      ft::vector<int> bar;
      sz = bar.capacity(); // 0
      std::cout << "capacity " << sz << '\n';
      bar.reserve(100);   // this is the only difference with foo above
      // std::cout << "making bar grow:\n";
      // for (int i=0; i<100; ++i) {
      //   bar.push_back(i);
      //  sz = bar.capacity();
      // std::cout << "capacity " << sz << '\n';
      if (sz!=bar.capacity()) // 
      {
        sz = bar.capacity(); // 100
        std::cout << "capacity changed: " << sz << '\n';
      }
    }


/*******************ELEMENT ACCESS TESTS**********************************/

//https://www.cplusplus.com/reference/vector/vector/operator[]/
    {
       std::cout << "\n" << "operator[] test" << "\n";
       std::cout  << "The test is skipped because  the operator= code uses "<< "\n" 
       << " the operator[], it works" << "\n";
    }

//https://www.cplusplus.com/reference/vector/vector/at/
    {
       std::cout << "\n" << "at() test" << "\n";
         std::vector<int> myvector (10);   // 10 zero-initialized ints

       // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
          myvector.at(i)=i;

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector.at(i);
        std::cout << '\n';



        ft::vector<int> ftvector (10);   // 10 zero-initialized ints
                // assign some values:
        for (unsigned i=0; i<ftvector.size(); i++)
          ftvector.at(i)=i;

        std::cout << "ftvector contains:";
        for (unsigned i=0; i<ftvector.size(); i++)
          std::cout << ' ' << ftvector.at(i);
        std::cout << '\n';
    }


//https://www.cplusplus.com/reference/vector/vector/front/
    {
      std::cout << "\n" << "front() test" << "\n";
      std::vector<int> myvector (5, 10);
      ft::vector<int> ftvector (5, 10);
      // myvector.push_back(78);
      // myvector.push_back(16);

      // now front equals 78, and back 16

      // myvector.front() //-= myvector.back();

      std::cout << "myvector.front() is now " << myvector.front() << '\n';
      std::cout << "ftvector.front() is now " << ftvector.front() << '\n';
    }


  //https://www.cplusplus.com/reference/vector/vector/back/
    {
        std::vector<int> myvector (1, 88);
        ft::vector<int> ftvector (1, 99);
        // myvector.push_back(10);

        // while (myvector.back() != 0)
        // {
        //   myvector.push_back ( myvector.back() -1 );
        // }

        std::cout << "myvector last element contains:";
        for (unsigned i=0; i<myvector.size() ; i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';

        std::cout << "ftvector last element contains:";
        for (unsigned i=0; i<ftvector.size() ; i++)
          std::cout << ' ' << ftvector[i];

         std::cout << '\n';
      
    }

    
        

      
  return 0;
}