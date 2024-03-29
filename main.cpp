/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:32:02 by areggie           #+#    #+#             */
/*   Updated: 2022/06/14 17:32:15 by areggie          ###   ########.fr       */
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
#include "ft_stack.hpp"
#include "ft_map.hpp"
#include "ft_tree_iterator.hpp"
#include "ft_utility.hpp"
#include "ft_set.hpp"

// for running tests
#include <iterator> // for printing out vector contents
#include <vector> // for comparative test
#include <stack> 
#include <map>
#include <set>


//this is color definition for printing
#define RED "\033[1;31m" // red color
#define GREEN "\033[1;32m" // green color
#define BLUE "\033[1;34m" // blue color
#define YELLOW "\033[1;33m" // yellow color
#define DEFAULT "\033[0;37m"

// this is for calculating time
// #include <machine/types.h> /* __darwin_time_t */ this does not work on mac
# include <sys/time.h>/* __darwin_time_t, this works */ 
typedef __darwin_time_t         time_t;


time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

volatile static time_t g_start1;
volatile static time_t g_start2;
volatile static time_t g_end1;
volatile static time_t g_end2;


int main ()
{
  




    // CONSTRUCTOR TESTS used in the same order as described above:
  {
    
      std::cout << RED << "\n" <<"VECTOR all constructors test" << "\n" <<DEFAULT;

      time_t t1;
      g_start1 = timer();

      std::vector<int> first_obj; //test for default constructor
      std::vector<int> second (4,100);//test for constructor with values in vector
        // std::vector<int> second (4,100); 
        // printf("%d", second[0]);// 32 (4 x 8)
      std::vector<int> third (5,20);
      std::vector<int> fourth (third);// test for copy constructor of third works
      // the iterator constructor can also be used to construct from arrays:
      //this is the test for range constructor
      int myints[] = {16,2,77,29};
      std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

      std::cout << "The contents of std::vector are:";
      for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';


      g_end1 = timer();
      t1 = g_end1 - g_start1;
     


    
      g_start2 = timer();
      ft::vector<int> first_obj1; //test for default constructor
      ft::vector<int> second1 (4,100);//test for constructor with values in vector
        // std::vector<int> second (4,100); 
        // printf("%d", second[0]);// 32 (4 x 8)
      ft::vector<int> third1 (5,20);
      ft::vector<int> fourth1 (third1);// test for copy constructor of third works
      int myints1[] = {16,2,77,29};      
      ft::vector<int> my_fifth (myints1, myints1 + sizeof(myints1) / sizeof(int) );


      // lack of begin() and end() functions to iterate
      std::cout << "The contents of my ft::vector are:";
      for (ft::vector<int>::iterator my_it = my_fifth.begin(); my_it != my_fifth.end(); ++my_it)
        std::cout << ' ' << *my_it;
      std::cout << '\n';
  
      
      time_t t2;
      g_end2 = timer();
      t2 = g_end2 - g_start2;

      (t1 >= t2) ? (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT);
      (t2 >= t1) ? (std::cout << "ft::" << GREEN + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< RED + std::to_string(t2) + "ms " + DEFAULT);
     std::cout << '\n';
  }


  //test for reverse_iterator class 
  //rbegin, rend() methods need reverse_iterator
  //https://www.cplusplus.com/reference/vector/vector/rbegin/
  {
      std::cout << RED << "\n"  << "VECTOR rbegin(), rend() test" << "\n" << DEFAULT;

      time_t t1;
      g_start1 = timer();
      
      std::vector<int> myvector1 (5);  // 5 default-constructed ints

      int i1=0;

      std::vector<int>::reverse_iterator rit1 = myvector1.rbegin();
      for (; rit1!= myvector1.rend(); ++rit1) // putting from the end (which is start) - запись с конца
      // нулевой элемент[] справа 
      *rit1 = ++i1;

      std::cout << "std::vector contains:";
      for (std::vector<int>::iterator it1 = myvector1.begin(); it1 != myvector1.end(); ++it1)
      std::cout << ' ' << *it1;
      std::cout << '\n';
      
      g_end1 = timer();
      t1 = g_end1 - g_start1;
      
      g_start2 = timer();
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

      time_t t2;
      g_end2 = timer();
      t2 = g_end2 - g_start2;

      (t1 >= t2) ? (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT);
      (t2 >= t1) ? (std::cout << "ft::" << GREEN + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< RED + std::to_string(t2) + "ms " + DEFAULT);
      
      std::cout << '\n';
    }

    /*******************CAPACITY PART TESTS**********************************/
    
    //test for size() https://www.cplusplus.com/reference/vector/vector/size/
    {
       std::cout << RED << "\n" << "VECTOR size() test" << "\n" << DEFAULT;
       
      time_t t1;
      g_start1 = timer();
      
      std::vector<int> myints1;
      std::cout << "0. size: " << myints1.size() << '\n';

      std::vector<int> myvector1 (5);
      std::cout << "0. size: " << myvector1.size() << '\n';

      for (int i=0; i<10; i++) myints1.push_back(i);
      std::cout << "1. size: " << myints1.size() << '\n';

      myints1.insert (myints1.end(),10,100);
      std::cout << "2. size: " << myints1.size() << '\n';

      myints1.pop_back();
      std::cout << "3. size: " << myints1.size() << '\n';

      std::cout << '\n';
      g_end1 = timer();
      t1 = g_end1 - g_start1;
      g_start2 = timer();
    

      ft::vector<int> myints;
      std::cout << "0. size: " << myints.size() << '\n';

      ft::vector<int> myvector (5);
      std::cout << "0. size: " << myvector.size() << '\n';

      for (int i=0; i<10; i++) myints.push_back(i);
      std::cout << "1. size: " << myints.size() << '\n';

      myints.insert (myints.end(),10,100);
      std::cout << "2. size: " << myints.size() << '\n';

      myints.pop_back();
      std::cout << "3. size: " << myints.size() << '\n';
      std::cout << '\n';

      time_t t2;
      g_end2 = timer();
      t2 = g_end2 - g_start2;

      (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
      (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
      
      std::cout << '\n';
      
    }


    // test for max_size() https://www.cplusplus.com/reference/vector/vector/max_size/
    {
        std::cout << RED << "\n" << "VECTOR max_size() test" << "\n" << DEFAULT;
        
        time_t t1;
        g_start1 = timer();
        std::vector<int> myvector (100000000,4);
        std::cout << "size: " << myvector.size() << "\n";
        std::cout << "max_size: " << myvector.max_size() << "\n";
        
        std::cout << '\n';
        g_end1 = timer();
        t1 = g_end1 - g_start1;
        g_start2 = timer();
        
        
        // set some content in the vector:   
        ft::vector<int> myvector1 (100000000,4);
        std::cout << "size: " << myvector1.size() << "\n";
        std::cout << "max_size: " << myvector1.max_size() << "\n";

        std::cout << '\n';
        time_t t2;
        g_end2 = timer();
        t2 = g_end2 - g_start2;
        (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
      (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
        std::cout << '\n';
    }


    //test for resize() https://www.cplusplus.com/reference/vector/vector/resize/
    {
      std::cout << RED << "\n" << "VECTOR resize() test" << "\n" << DEFAULT;

      
        std::vector<int> myvector1; // no elements inside

        time_t t1;
        g_start1 = timer();
        myvector1.resize(5000000); //5 zeros
        // std::cout << "std::myvector contains:";
        // for (unsigned long i=0;i<myvector1.size();i++)
        //   std::cout << ' ' << myvector1[i];
        // std::cout << '\n';
        
        myvector1.resize(8000000,100); // added 3 elem of value 100 over 5
        // std::cout << "std::myvector contains:";
        // for (unsigned long i=0;i<myvector1.size();i++)
        //   std::cout << ' ' << myvector1[i];
        // std::cout << '\n';
        
        myvector1.resize(12000000, 3); // added 4 elem of value 3 over 8
        // std::cout << "std::myvector contains:";
        // for (unsigned long i=0;i<myvector1.size();i++)
        //   std::cout << ' ' << myvector1[i];
        // std::cout << '\n';

        std::cout << '\n';
        g_end1 = timer();
        t1 = g_end1 - g_start1;
        g_start2 = timer();
       
       
       
        // set some content in the vector:   
      ft::vector<int> myvector; // no elements inside

        myvector.resize(5000000); //5 zeros
        // std::cout << "myvector contains:";
        // for (unsigned long i=0;i<myvector.size();i++)
        //   std::cout << ' ' << myvector[i];
        // std::cout << '\n';
        
        myvector.resize(8000000,100); // added 3 elem of value 100 over 5
        // std::cout << "myvector contains:";
        // for (unsigned long i=0;i<myvector.size();i++)
        //   std::cout << ' ' << myvector[i];
        // std::cout << '\n';
        
        myvector.resize(12000000, 3); // added 4 elem of value 3 over 8
        // std::cout << "myvector contains:";
        // for (unsigned long i=0;i<myvector.size();i++)
        //   std::cout << ' ' << myvector[i];
        // std::cout << '\n';

        std::cout << '\n';
        time_t t2;
        g_end2 = timer();
        t2 = g_end2 - g_start2;
        (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
        (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
        std::cout << '\n';
    }


    //https://www.cplusplus.com/reference/vector/vector/capacity/
    {
      std::cout << RED << "\n" << "VECTOR capacity() test" << "\n" << DEFAULT;
      
      time_t t1;
      g_start1 = timer();
      
      std::vector<int> myvector2 (99000000, 5);
      std::cout << "size: " << (int) myvector2.size() << '\n';
      std::cout << "capacity: " << (int) myvector2.capacity() << '\n';
      std::cout << "max_size: " <<  myvector2.max_size() << '\n'; //when we cast to int we get -1
      
      std::cout << '\n';
      g_end1 = timer();
      t1 = g_end1 - g_start1;
      g_start2 = timer();
      
      // need to check with push_back()
      ft::vector<int> myvector (99000000, 5);
      std::cout << "size: " << (int) myvector.size() << '\n';
      std::cout << "capacity: " << (int) myvector.capacity() << '\n';
      std::cout << "max_size: " <<  myvector.max_size() << '\n'; //when we cast to int, we get -1
      
      std::cout << '\n';
      time_t t2;
      g_end2 = timer();
      t2 = g_end2 - g_start2;
      (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
      (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
      std::cout << '\n';
      
    }


    //https://www.cplusplus.com/reference/vector/vector/empty/
    {
      std::cout << RED << "\n" << "VECTOR empty() test" << "\n" << DEFAULT;      
              
        time_t t1;
        g_start1 = timer();
        std::vector<int> myvector3 (100000000, 5);
        std::vector<int> myvector4;
        for (int i=1;i<=10000000;i++) myvector3.push_back(i);
        if (!myvector3.empty())
        {
          std::cout << "std::vector3 is not empty\n" << std::endl;
        }
        else
          std::cout << "std::vector3 is empty\n" << std::endl;

        if (!myvector4.empty())
        {
          std::cout << "std::vector4 is not empty\n" << std::endl;
        }
        else
          std::cout << "std::vector4 is empty\n" << std::endl;
          
        std::cout << '\n';
        g_end1 = timer();
        t1 = g_end1 - g_start1;
        g_start2 = timer();
        
        ft::vector<int> myvector (100000000, 5);
        ft::vector<int> myvector2;
        for (int i=1;i<=10000000;i++) myvector.push_back(i);
        if (!myvector.empty())
        {
          std::cout << "ft::vector is not empty\n" << std::endl;
        }
        else
          std::cout << "ft::vector is empty\n" << std::endl;

        if (!myvector2.empty())
        {
          std::cout << "ftvector2 is not empty\n" << std::endl;
        }
        else
          std::cout << "vector2 is empty\n" << std::endl;
        std::cout << '\n';
        time_t t2;
        g_end2 = timer();
        t2 = g_end2 - g_start2;
        (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
        (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
        std::cout << '\n';    
    }


  //https://www.cplusplus.com/reference/vector/vector/reserve/
    {
      std::cout << RED << "\n" << "VECTOR reserve() test" << "\n" << DEFAULT;
      
      time_t t1;
      g_start1 = timer();
      std::vector<int>::size_type sz1;
      std::vector<int> bar1;
      sz1 = bar1.capacity(); // 0
      std::cout << "std::capacity " << sz1 << '\n';
      bar1.reserve(100000000);   // this is the only difference with foo above
      std::cout << "making bar grow:\n";
      for (int i=0; i<1000000; ++i) 
        bar1.push_back(i);
      sz1 = bar1.capacity();
      std::cout << "capacity " << sz1 << '\n';
      if (sz1 !=bar1.capacity()) // 
      {
        sz1 = bar1.capacity(); // 100
        std::cout << "capacity changed: " << sz1 << '\n';
      }

      std::cout << '\n';
      g_end1 = timer();
      t1 = g_end1 - g_start1;
      g_start2 = timer();
      
      
      
      
      
      
      
      ft::vector<int>::size_type sz;
      ft::vector<int> bar;
      sz = bar.capacity(); // 0
      std::cout << "capacity " << sz << '\n';
      bar.reserve(100000000);   // this is the only difference with foo above
      std::cout << "making bar grow:\n";
      for (int i=0; i<1000000; ++i) 
        bar.push_back(i);
      sz = bar.capacity();
      std::cout << "capacity " << sz << '\n';
      if (sz!=bar.capacity()) // 
      {
        sz = bar.capacity(); // 100
        std::cout << "capacity changed: " << sz << '\n';
      }

      std::cout << '\n';
      time_t t2;
      g_end2 = timer();
      t2 = g_end2 - g_start2;
      (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
      (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
      std::cout << '\n';


      
    }


/*******************ELEMENT ACCESS TESTS**********************************/

//https://www.cplusplus.com/reference/vector/vector/operator[]/
    {
       std::cout << RED << "\n" << "VECTOR operator[] test" << "\n"<< DEFAULT;
       std::cout  << "The test is skipped because  the operator= code uses "<< "\n" 
       << " the operator[], it works" << "\n";
    }

//https://www.cplusplus.com/reference/vector/vector/at/
    {
       std::cout << RED <<  "\n" << "at() test" << "\n" << DEFAULT;
        time_t t1;
        g_start1 = timer();
         std::vector<int> myvector (100000000);   // 10 zero-initialized ints
       // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
          myvector.at(i)=i;

        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<myvector.size(); i++)
        //   std::cout << ' ' << myvector.at(i);
        // std::cout << '\n';

                std::cout << '\n';
        g_end1 = timer();
        t1 = g_end1 - g_start1;
        g_start2 = timer();



        ft::vector<int> ftvector (100000000);   // 10 zero-initialized ints
        // assign some values:
        for (unsigned i=0; i<ftvector.size(); i++)
          ftvector.at(i)=i;

        // std::cout << "ftvector contains:";
        // for (unsigned i=0; i<ftvector.size(); i++)
        //   std::cout << ' ' << ftvector.at(i);
        // std::cout << '\n';

                std::cout << '\n';
        time_t t2;
        g_end2 = timer();
        t2 = g_end2 - g_start2;
        (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
      (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
        std::cout << '\n';
    }



//https://www.cplusplus.com/reference/vector/vector/front/
    {
      std::cout << RED << "\n" << "VECTOR front() test" << "\n"<< DEFAULT;
              
      time_t t1;
      g_start1 = timer();
      std::vector<int> myvector (5000000, 10);
      myvector.push_back(78); // adds from the end
      std::cout << "myvector.front() is now " << myvector.front() << '\n';
      // now front equals 10, and back 78
      
      std::cout << '\n';
      g_end1 = timer();
      t1 = g_end1 - g_start1;
      g_start2 = timer();

      
      ft::vector<int> ftvector (5000000, 10);
      ftvector.push_back(78);
      std::cout << "ftvector.front() is now " << ftvector.front() << '\n';   

      std::cout << '\n';
      time_t t2;
      g_end2 = timer();
      t2 = g_end2 - g_start2;
      (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
      (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
      std::cout << '\n';
    }


  //https://www.cplusplus.com/reference/vector/vector/back/
    {
      std::cout << RED << "\n" << "VECTOR back() test" << "\n"<< DEFAULT;
    
      time_t t1;
      g_start1 = timer();
    
      std::vector<int> myvector (1, 42);
      myvector.push_back(1000000);
      while (myvector.back() != 1)
      {
        myvector.push_back (myvector.back() -1);
      }
      std::cout << "myvector.back() is now " << myvector.back() << '\n'; 
        
      // std::cout << "myvector last element contains:";
      // for (unsigned i=0; i<myvector.size() ; i++)
      //   std::cout << ' ' << myvector[i];
      // std::cout << '\n';

      std::cout << '\n';
      g_end1 = timer();
      t1 = g_end1 - g_start1;
      g_start2 = timer();


      ft::vector<int> ftvector (1, 42);
      ftvector.push_back(1000000);
      while (ftvector.back() != 1)
      {
        ftvector.push_back (ftvector.back() -1);
      }
      std::cout << "ftvector.back() is now " << ftvector.back() << '\n';
          
      // std::cout << "ftvector last element contains:";
      // for (unsigned i=0; i<ftvector.size() ; i++)
      //   std::cout << ' ' << ftvector[i];

      std::cout << '\n';
      time_t t2;
      g_end2 = timer();
      t2 = g_end2 - g_start2;
      (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
      (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
      std::cout << '\n';

    }

    /*******************MODIFIERS**********************************/
    //https://www.cplusplus.com/reference/vector/vector/
    //Unit-tests mainly require assign() method, so one can start testing 
    {
      std::cout << RED << "\n" << "VECTOR assign() test" << "\n" << DEFAULT;
            time_t t1;
      g_start1 = timer();

      std::vector<int> first;
      std::vector<int> second;
      std::vector<int> third;
      first.assign (7000000,100);// 7 ints with a value of 100
      std::vector<int>::iterator it;
      it=first.begin()+1; // making iterator on the second cell (+1)
      second.assign (it,first.end()-1); // from 2nd cell to the prefinal cell
      // the 5 central values of first
      int myints[] = {1776,7,4};
      third.assign (myints,myints+3);  // assigning from array.
      std::cout << "Size of std::vector first: " << int (first.size()) << '\n';
      std::cout << "Size of std::vector second: " << int (second.size()) << '\n';
      std::cout << "Size of std::vector third: " << int (third.size()) << '\n';
      

      std::cout << '\n';
      g_end1 = timer();
      t1 = g_end1 - g_start1;
      g_start2 = timer();



      
      ft::vector<int> first1;
      ft::vector<int> second1;
      ft::vector<int> third1;
      first1.assign (7000000,100);             // 7 ints with a value of 100
      ft::vector<int>::iterator it1;
      it1=first1.begin()+1; // making iterator on the second cell (+1)
      second1.assign (it1,first1.end()-1); // from 2nd cell to the prefinal cell
      // the 5 central values of first
      int myints1[] = {1776,7,4};
      third1.assign (myints1,myints1+3);  // assigning from array.
      std::cout << "Size of ft::vector first1: " << int (first1.size()) << '\n';
      std::cout << "Size of ft::vector second1: " << int (second1.size()) << '\n';
      std::cout << "Size of ft::vector third1: " << int (third1.size()) << '\n';
      
      std::cout << '\n';
      time_t t2;
      g_end2 = timer();
      t2 = g_end2 - g_start2;
      (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
      (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
      std::cout << '\n';

      
    }   


  //https://www.cplusplus.com/reference/vector/vector/push_back/
    {
        std::cout << RED << "\n" << "VECTOR pushback() test" << "\n"<< DEFAULT;

        time_t t1;
        g_start1 = timer();
        
        std::vector<int> myvector(1000000, 4);
        int myint = 4;

        // std::cout << "Please enter some integers for vector (enter 0 to end):\n";

        do 
        {
          for (; myint > 0; myint--)
          // std::cin >> myint;
            myvector.push_back (myint);
        } while (myint);

        std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
              
        std::vector<int>::size_type sz;
        sz = myvector.capacity(); 
        std::cout << "capacity of vector changed: " << sz << '\n';


        std::cout << '\n';
        g_end1 = timer();
        t1 = g_end1 - g_start1;
        g_start2 = timer();


        ft::vector<int> ftvector(1000000, 4);;
        int ftint = 4;

        // std::cout << "Please enter some integers for ft_vector (enter 0 to end):\n";

        do 
        {
          for (; ftint > 0; ftint--)
          // std::cin >> ftint;
            ftvector.push_back (ftint);
        } while (ftint);

        std::cout << "ft::vector stores " << int(ftvector.size()) << " numbers.\n";
        ft::vector<int>::size_type sz1;
        sz1 = ftvector.capacity(); 
        std::cout << "capacity of ft_vector changed: " << sz1 << '\n';
        
        std::cout << '\n';
        time_t t2;
        g_end2 = timer();
        t2 = g_end2 - g_start2;
        (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
        (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
        std::cout << '\n';  
    }


  //https://www.cplusplus.com/reference/vector/vector/pop_back/
  /*
    Removes the last element in the vector, 
    effectively reducing the container size by one.
    This destroys the removed element
  */
    {
        std::cout << RED << "\n" << "VECTOR pop_back() test" << "\n"<< DEFAULT;
        
        time_t t1;
        g_start1 = timer();
        
        std::vector<int> myvector;
        int sum (0);
        // myvector.push_back (100);
        // myvector.push_back (200);
        // myvector.push_back (300);
        for(int i = 1; i < 1000000; i++)
          myvector.push_back (i);

        while (!myvector.empty()) 
        {
          sum+=myvector.back();
          myvector.pop_back();
        }
        std::cout << "The sum of indexes in myvector add up to " << sum << '\n';
        std::cout << "Size of std::myvector now: " << (myvector.size()) << '\n';

        //additional test
        std::vector<int> myvector1;
        myvector1.push_back (1); //removed
        myvector1.push_back (2);
        myvector1.push_back (3);
        myvector1.pop_back();
        myvector1.pop_back();
        std::cout << "Size of ft::vector after pop_back now: " << (myvector1.size()) << '\n';

        

        std::cout << '\n';
        g_end1 = timer();
        t1 = g_end1 - g_start1;
        g_start2 = timer();

        ft::vector<int> ft_vector;
        int sum1 (0);
        // ft_vector.push_back (100);
        // ft_vector.push_back (200);
        // ft_vector.push_back (300);
        for(int i = 1; i < 1000000; i++)
          ft_vector.push_back (i);

        while (!ft_vector.empty()) //debugged size = 0 there
        {
          sum1+=ft_vector.back();
          ft_vector.pop_back(); //removes and min size
        }

        std::cout << "The elements of myvector add up to " << sum1 << '\n';
        std::cout << "Size of ft::vector now: " << (ft_vector.size()) << '\n';

        //additional test
        ft::vector<int> vector;
        vector.push_back (1);
        vector.push_back (2);
        vector.push_back (3);
        vector.pop_back();
        vector.pop_back();
        std::cout << "Size of ft::vector after pop_back now: " << (vector.size()) << '\n';

        std::cout << '\n';
        time_t t2;
        g_end2 = timer();
        t2 = g_end2 - g_start2;
        (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
        (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
        std::cout << '\n';   
        
    }

    //https://www.cplusplus.com/reference/vector/vector/insert/
    {
      std::cout << RED << "\n" << "VECTOR insert() test" << "\n"<< DEFAULT;
      std::vector<int> myvector (3,100); //100 100 100
      std::vector<int>::iterator it;
      // it = myvector.begin();
      //     for (it=myvector.begin(); it<myvector.end(); it++)
      //   std::cout << ' ' << *it;
      // std::cout << '\n';
      time_t t1;
      g_start1 = timer();
      
    

      it = myvector.begin();
      it = myvector.insert ( it , 200 ); // it is one the first, inserted on the first place  
      //200 100 100 100

      myvector.insert (it,2000000,300); // it is on the first  and inserts two elements from the pos of it
      //  300 300 200 100 100 100
    
      // for (it=myvector.begin(); it < myvector.end(); it++) // it went to the last position
      //   std::cout << ' ' << *it;
      // std::cout << '\n';


      // // "it" no longer valid, get a new one: we returned it to the beginning
      it = myvector.begin();

      std::vector<int> anothervector (2,400); // new vec 
      myvector.insert (it+2,anothervector.begin(),anothervector.end()); 
      //inserted the new vec from it+2: 300 300 400 400 200 100 100 100



      int myarray [] = { 501,502,503 };// one more new vec
      myvector.insert (myvector.begin(), myarray, myarray+3);
      // insert the whole vec from the beginning of the vector where we insert
      // myarray - beginning of the vector
      // myarray + 3 - inserting 3 elements of myarray

      
      // std::cout << "myvector contains:";
      // for (it=myvector.begin(); it<myvector.end(); it++)
      //   std::cout << ' ' << *it;
      // std::cout << '\n';


      std::cout << '\n';
      g_end1 = timer();
      t1 = g_end1 - g_start1;
      g_start2 = timer();


      ft::vector<int> ft_vector (3,100);
      ft::vector<int>::iterator it1;

      it1 = ft_vector.begin();
      it1 = ft_vector.insert ( it1 , 200 ); // insert one element

      ft_vector.insert (it1,2000000,300); // insert fill with 2 

      // "it" no longer valid, get a new one:
      it1 = ft_vector.begin();


      //insert range
      std::vector<int> anothervector1 (2,400);
      ft_vector.insert (it1+2,anothervector1.begin(),anothervector1.end());

      int myarray1 [] = { 501,502,503 };
      ft_vector.insert (ft_vector.begin(), myarray1, myarray1+3);

      // std::cout << "ft_vector contains:";
      // for (it1=ft_vector.begin(); it1<ft_vector.end(); it1++)
      //   std::cout << ' ' << *it1;
      // std::cout << '\n';

      std::cout << '\n';
      time_t t2;
      g_end2 = timer();
      t2 = g_end2 - g_start2;
      (t1 >= t2) ? (std::cout <<"std::"<< RED + std::to_string(t1) + "ms " + DEFAULT) : (std::cout <<"std::"<< GREEN + std::to_string(t1) + "ms " + DEFAULT);
      (t2 > t1) ? (std::cout << "ft::" << RED + std::to_string(t2) + "ms " + DEFAULT) : (std::cout <<"ft::"<< GREEN + std::to_string(t2) + "ms " + DEFAULT);
      std::cout << '\n';   
    }


    //https://www.cplusplus.com/reference/vector/vector/erase/
    {
      std::cout << RED << "\n" << "VECTOR erase() test" << "\n"<< DEFAULT;
      std::vector<int> myvector;

      // set some values (from 1 to 10)
      for (int i=1; i<=10; i++) 
        myvector.push_back(i);

      // erase the 6th element
      myvector.erase (myvector.begin()+5);//1 2 3 4 5 [] 7 8 9 10

      // erase the first 3 elements:
      myvector.erase (myvector.begin(),myvector.begin()+3); //[] [] [] 4 5 [] 7 8 9 10

      std::cout << "myvector contains:";
      for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';


      ft::vector<int> myvector1;
      // set some values (from 1 to 10)
      for (int i=1; i<=10; i++) 
        myvector1.push_back(i);

      // erase the 6th element
      myvector1.erase (myvector1.begin()+5);//1 2 3 4 5 [] 7 8 9 10

      // erase the first 3 elements:
      myvector1.erase (myvector1.begin(),myvector1.begin()+3); //[] [] [] 4 5 [] 7 8 9 10

      std::cout << "ft_vector contains:";
      for (unsigned i=0; i<myvector1.size(); ++i)
        std::cout << ' ' << myvector1[i];
      std::cout << '\n';
        
    }

  // https://www.cplusplus.com/reference/vector/vector/swap/
    {
      std::cout << RED << "\n" << "VECTOR swap() test" << "\n"<< DEFAULT;
      std::vector<int> foo (3,100);   // three ints with a value of 100
      std::vector<int> bar (5,200);   // five ints with a value of 200

      foo.swap(bar);

      std::cout << "foo contains:";
      for (unsigned i=0; i<foo.size(); i++)
        std::cout << ' ' << foo[i];
      std::cout << '\n';

      std::cout << "bar contains:";
      for (unsigned i=0; i<bar.size(); i++)
        std::cout << ' ' << bar[i];
      std::cout << '\n';
      


      ft::vector<int> foo1 (3,100);   // three ints with a value of 100
      ft::vector<int> bar1 (5,200);   // five ints with a value of 200

      foo1.swap(bar1);

      std::cout << "ft foo contains:";
      for (unsigned i=0; i<foo1.size(); i++)
        std::cout << ' ' << foo1[i];
      std::cout << '\n';

      std::cout << "ft bar contains:";
      for (unsigned i=0; i<bar1.size(); i++)
        std::cout << ' ' << bar1[i];
      std::cout << '\n';
    }

  //https://www.cplusplus.com/reference/vector/vector/clear/
    {
        std::cout << RED << "\n" << "VECTOR clear() test" << "\n"<< DEFAULT;
        std::vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';

        myvector.clear(); // clear the whole vector
        myvector.push_back (1101);
        myvector.push_back (2202);

        std::cout << "vector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';


        ft::vector<int> myvector1;
        myvector1.push_back (100);
        myvector1.push_back (200);
        myvector1.push_back (300);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector1.size(); i++)
          std::cout << ' ' << myvector1[i];
        std::cout << '\n';

        myvector1.clear(); // clear the whole vector
        myvector1.push_back (1101);
        myvector1.push_back (2202);

        std::cout << "vector contains:";
        for (unsigned i=0; i<myvector1.size(); i++)
          std::cout << ' ' << myvector1[i];
        std::cout << '\n';
      
    }

  // https://www.cplusplus.com/reference/vector/vector/get_allocator/
    {
      // << RED << DEFAULT
        std::cout << RED << "\n" << "VECTOR get_allocator() test" << "\n"<< DEFAULT;
        std::vector<int> myvector;
        int * p;
        unsigned int i;

        // allocate an array with space for 5 elements using vector's allocator:
        p = myvector.get_allocator().allocate(5);

        // construct values in-place on the array:
        for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

        std::cout << "The allocated array contains:";
        for (i=0; i<5; i++) std::cout << ' ' << p[i];
        std::cout << '\n';

        // destroy and deallocate:
        for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
        myvector.get_allocator().deallocate(p,5);


        ft::vector<int> ft_vector;
        int * p1;
        unsigned int a;

        // allocate an array with space for 5 elements using vector's allocator:
        p1 = ft_vector.get_allocator().allocate(5);

        // construct values in-place on the array:
        for (a=0; a<5; a++) ft_vector.get_allocator().construct(&p1[a],a);

        std::cout << "The allocated array contains:";
        for (a=0; a<5; a++) std::cout << ' ' << p1[a];
        std::cout << '\n';

        // destroy and deallocate:
        for (a=0; a<5; a++) ft_vector.get_allocator().destroy(&p1[a]);
        ft_vector.get_allocator().deallocate(p1,5);
    }

    

    // METHODS finished and now we ADD RELATIONAL OPERATORS
    {
      std::cout << RED << "\n" << "VECTOR relational operators() test" << "\n" << DEFAULT;
        ft::vector<int> foo (2,250);   // three ints with a value of 100
        ft::vector<int> bar (2,200);   // two ints with a value of 200

        if (foo==bar) std::cout << "foo and bar are equal\n";
        if (foo!=bar) std::cout << "foo and bar are not equal\n";
        if (foo< bar) std::cout << "foo is less than bar\n";
        if (foo> bar) std::cout << "foo is greater than bar\n";
        if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
        if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

        
      
    }

    {
      std::cout <<RED << "\n" << "redundant VECTOR equal test" << "\n" << DEFAULT;
      //https://m.cplusplus.com/reference/algorithm/equal/
        int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
        std::vector<int>myvector (myints, myints+5);     // myvector: 20 40 60 80 100

        // using default comparison:
        if ( std::equal (myvector.begin(), myvector.end(), myints) )
          std::cout << "The contents of both sequences of std::vector are equal.\n";
        else
          std::cout << "The contents of both sequences of std::vector differ.\n";
        std::cout << '\n';

        


        int myints1[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
        ft::vector<int>myvector1 (myints1, myints1+5);     // myvector: 20 40 60 80 100

        // using default comparison:
        if ( ft::equal (myvector1.begin(), myvector1.end(), myints1) )
          std::cout << "The contents of both sequences of ft::vector are equal.\n";
        else
          std::cout << "The contents of both sequences of ft::vector differ.\n";
    }


      
  {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

    std::cout <<RED<< "\t\tV E C T O R EXTRA TESTS \nconstructors/begin/end tests\n" <<DEFAULT;
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100
    std::vector<int> third (second.begin(),second.end());  // iterating through second
    std::vector<int> fourth (third);                       // a copy of third

    ft::vector<int> my_first;                                // empty vector of ints
    ft::vector<int> my_second (4,100);                       // four ints with value 100
    ft::vector<int> my_third (my_second.begin(),my_second.end());  // iterating through second
    ft::vector<int> my_fourth (my_third);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
    ft::vector<int> my_fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "The contents of std::vector are:";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "The contents of my::vector are:";
    for (ft::vector<int>::iterator my_it = my_fifth.begin(); my_it != my_fifth.end(); ++my_it)
      std::cout << ' ' << *my_it;
    std::cout << '\n';
    }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

    {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
    std::cout <<RED<< "\nsize/operator= tests\n" <<DEFAULT;

    std::vector<int> vec1 (3,0);			ft::vector<int> vec3 (3,0);
    std::vector<int> vec2 (5,0);			ft::vector<int> vec4 (5,0);

    vec1 = vec2;							vec3 = vec4;
    vec2 = std::vector<int>();				vec4 = ft::vector<int>();
    std::cout << "std::vector:\nSize of vec1: " << int(vec1.size()) << '\n';
    std::cout << "Size of vec2: " << int(vec2.size()) << '\n';
    std::cout << "ft::vector:\nSize of vec3: " << int(vec3.size()) << '\n';
    std::cout << "Size of vec4: " << int(vec4.size()) << '\n';
    }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

    {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
    std::cout <<RED<< "\nempty/front/back/capacity tests\n" <<DEFAULT;
    std::vector<int> vec1;					ft::vector<int> vec2;
    std::cout  << "std::vector:\nis vec1 Empty? " << std::boolalpha << vec1.empty() << '\n';
    std::cout << "ft::vector:\nis vec2 Empty? " << std::boolalpha << vec2.empty() << '\n';
    vec1.push_back(111);					vec2.push_back(111);
    vec1.push_back(222);					vec2.push_back(222);
    std::cout << "std::vector:\nis vec1 Empty? " << std::boolalpha << vec1.empty() << '\n';
    std::cout << "ft::vector:\nis vec2 Empty? " << vec2.empty() << '\n';
    std::cout << "std::vector:\ncapacity of vec1: " << int(vec1.capacity()) << '\n';
    std::cout << "ft::vector:\ncapacity of vec2: " << int(vec2.capacity()) << '\n';
    std::cout << "std::vector:\nfirst of vec1: " << int(vec1.front()) << '\n';
    std::cout << "ft::vector:\nfirst of vec2: " << int(vec2.front()) << '\n';
    std::cout << "std::vector:\nlast of vec1: " << int(vec1.back()) << '\n';
    std::cout << "ft::vector:\nlast of vec2: " << int(vec2.back()) << '\n';
    }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

    {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
    std::cout <<RED<< "\ninsert/operator[] tests\n" <<DEFAULT;

    std::vector<int> myvector (3,100);		ft::vector<int> myvector1 (3,100);
    std::vector<int>::iterator it;			ft::vector<int>::iterator ft_it;
    it = myvector.begin();					ft_it = myvector1.begin();
    it = myvector.insert ( it , 2 );		ft_it = myvector1.insert ( ft_it , 2 );

    std::cout << "std::vector contains: " << myvector.front() << " " <<
      myvector.back() << " size: " << myvector.size() << "\n";
    std::cout << "ft::vector contains: " << myvector1.front() << " " <<
      myvector1.back() << " size: " << myvector1.size() << "\n";

    myvector.insert (it,2,300);				myvector1.insert (ft_it,2,300);

    std::cout << "std::vector contains: " << myvector.front() << " " <<
      myvector.back() << " size: " << myvector.size() << "\n";
    std::cout << "ft::vector contains: " << myvector1.front() << " " <<
      myvector1.back() << " size: " << myvector1.size() << "\n";

    // "it" no longer valid, get a new one:
    it = myvector.begin();					ft_it = myvector1.begin();

    std::vector<int> anothervec(2,400);

    myvector.insert (it+2,anothervec.end(),anothervec.begin());
      try
      {
      myvector1.insert (ft_it+2,anothervec.end(),anothervec.begin());
      }
      catch(const std::exception& e)
      {
      std::cerr << e.what() << '\n'; //vector: Invalid iterator
      }

    std::cout << "std::vector contains: " << myvector[0] << " " <<  myvector[1]
      << " " << myvector[2] << " " << myvector[3] << " " << myvector[4] <<
      "... size: " << myvector.size() << "\n";
    std::cout << "ft::vector contains: " << myvector1[0] << " " <<  myvector1[1]
      << " " << myvector1[2] << " " << myvector1[3] << " " << myvector1[4] <<
      "... size: " << myvector1.size() << "\n";

    myvector.insert (it+2,anothervec.begin(),anothervec.end());
    myvector1.insert (ft_it+2,anothervec.begin(),anothervec.end());

    std::cout << "std::vector contains: " << myvector[0] << " " <<  myvector[1]
      << " " << myvector[2] << " " << myvector[3] << " " << myvector[4] <<
      "... size: " << myvector.size() << "\n";
    std::cout << "ft::vector contains: " << myvector1[0] << " " <<  myvector1[1]
      << " " << myvector1[2] << " " << myvector1[3] << " " << myvector1[4] <<
      "... size: " << myvector1.size() << "\n";
    }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

    {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
    std::cout <<RED<< "\nmax_size/reserve/resize tests\n" <<DEFAULT;
    std::vector<int> myvector (3,100);			ft::vector<int> myvector1 (3,100);
    std::cout << "std::vector max_size: " << myvector.max_size() << "\n";
    std::cout << "ft::vector max_size: " << myvector1.max_size() << "\n";
    std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
    std::cout << "ft::vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
    myvector.reserve(10000);								myvector1.reserve(10000);
    std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
    std::cout << "ft::vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
    myvector.resize(100);						myvector1.resize(100);
    myvector.resize(1);							myvector1.resize(1);
    std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
    std::cout << "ft::vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
    }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

    {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
      std::cout <<RED<< "\nat/operator >< = != tests\n" <<DEFAULT;
      std::vector<int> vec(5);				std::vector<int> vec1(10, 2);
      if (vec == vec1)
        std::cout << "std:: vec = vec1\n";
      if (vec != vec1)
        std::cout << "std:: vec != vec1\n";
      if (vec > vec1)
        std::cout << "std:: vec > vec1\n";
      if (vec < vec1)
        std::cout << "std:: vec < vec1\n";
      ft::vector<int> vec2(1 , 20);			ft::vector<int> vec3(3, 10);
      if (vec2 == vec3)
        std::cout << "ft:: vec2 = vec3\n";
      if (vec2 != vec3)
        std::cout << "ft:: vec2 != vec3\n";
      if (vec2 > vec3)
        std::cout << "ft:: vec2 > vec3\n";
      if (vec2 < vec3)
        std::cout << "ft:: vec2 < vec3\n";

      try
      {
        std::cout << "std::vector: ";
        std::cout << vec1.at(8) << "\n";
        std::cout << vec1.at(20) << "\n";
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
      try
      {
        std::cout << "ft::vector: ";
        std::cout << vec3.at(2) << "\n";
        std::cout << vec3.at(20) << "\n";
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
    }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

    {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
    std::cout <<RED<< "\nerase/clear/assign/push_back/pop_back tests\n" <<DEFAULT;
    std::vector<int> myvector (3,100);			ft::vector<int> myvector1 (3,100);
    std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
    std::cout << "ft::vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
    myvector.erase(myvector.begin());			myvector1.erase(myvector1.begin());
    std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
    std::cout << "ft::vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
    myvector.clear();							myvector1.clear();
    std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
    std::cout << "ft::vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
    myvector.assign(5, 10);			myvector1.assign(5, 10);
    std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
    std::cout << "ft::vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
    myvector.push_back(1);			myvector1.push_back(1);
    myvector.push_back(1);			myvector1.push_back(1);
    myvector.pop_back();			myvector1.pop_back();
    std::cout << "std::vector size/capacity: " << myvector.size() << " " << myvector.capacity() << "\n";
    std::cout << "ft::vector size/capacity: " << myvector1.size()<< " " << myvector1.capacity() << "\n";
    }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

      std::cout << RED << "\n" << "VECTOR cases finished" << "\n" << DEFAULT;
      /**************VECTOR cases finished******************/


      
      /*****************STACK test cases start************************/
      std::cout << GREEN << "\n" << "STACK test cases start" << "\n" << DEFAULT;

  

    {
      // <<GREEN << DEFAULT
      //https://en.cppreference.com/w/cpp/container/stack/top
      std::cout << GREEN << "\n" << "STACK top() test" << "\n" << DEFAULT;
      /*Returns reference to the top element in the stack. 
      This is the most recently pushed element. 
      This element will be removed on a call to pop(). 
      Effectively calls c.back().*/
            
      std::stack<int> s;
      s.push(2);
      s.push(6);
      s.push(51);

      std::cout << s.size() << " elements on std::stack\n";
      s.pop();// kicks out one element
      std::cout << "Top element of std::stack: " << s.top() << '\n';


      ft::stack<int> s2;
      s2.push(2);
      s2.push(6);
      s2.push(51);

      std::cout << s2.size() << " elements on ft::stack\n";
      s2.pop(); // kicks out one element
      std::cout << "Top element of ft::stack is: " << s.top() << '\n';
    }


    {
      //https://en.cppreference.com/w/cpp/container/stack/empty
      //Checks if the underlying container has no elements, i.e. whether c.empty()
      std::cout <<GREEN << "\n" << "STACK empty() test" << "\n"<< DEFAULT;
      std::cout << std::boolalpha;

      std::stack<int> container;
  
      std::cout << "Initially, std::stack container.empty(): " << container.empty() << '\n';
  
      container.push(42);
      std::cout << "After adding elements, std::stack container.empty(): " << container.empty() << '\n';
      std::cout << "\n";

      
      std::cout << std::boolalpha;
      ft::stack<int> container2;
      std::cout << "Initially, ft::stack container.empty(): " << container2.empty() << '\n';
  
      container2.push(42);
      std::cout << "After adding elements, ft::stack container.empty(): " << container2.empty() << '\n';
    }


      
    { 
      std::cout <<GREEN << "\n" << "STACK size() test" << "\n"<< DEFAULT;
      //https://en.cppreference.com/w/cpp/container/stack/size
      //Returns the number of elements in the underlying container, that is, c.size()
      std::stack<int> container;
      std::cout << "Initially, std::stack container.size(): " << container.size() << '\n';
      for (int i = 0; i < 7; ++i)
          container.push(i);
      std::cout << "After adding elements, std::stack container.size(): " << container.size() << '\n';
      std::cout << "\n";

      ft::stack<int> container2;
      std::cout << "Initially, ft::stack container.size(): " << container2.size() << '\n';
      for (int i = 0; i < 7; ++i)
          container2.push(i);
      std::cout << "After adding elements, ft::stack container.size(): " << container2.size() << '\n';
    }

    {
      //https://m.cplusplus.com/reference/stack/stack/push/
      std::cout <<GREEN << "\n" << "STACK push() and pop() test" << "\n"<< DEFAULT;
      //Pushes the given element value to the top of the stack.
      //Removes the element on top of the stack, effectively reducing its size by one.
      std::stack<int> mystack;

      for (int i=0; i<5; ++i)
        mystack.push(i);

      std::cout << "Popping out elements std::stack...";
      while (!mystack.empty())
      {
        std::cout << ' ' << mystack.top();
        mystack.pop();
      }
      std::cout << '\n';


      ft::stack<int> mystack1;

      for (int i=0; i<5; ++i)
        mystack1.push(i);

      std::cout << "Popping out elements of ft::stack...";
      while (!mystack1.empty())
      {
        std::cout << ' ' << mystack1.top();
        mystack1.pop();
      }
      std::cout << '\n';
    }
      
    {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
      std::cout <<GREEN<< "\n\t\tS T A C K EXTRA TESTS\nconstructors/size/push/pop/operator >< = != tests\n" <<DEFAULT;
      std::stack<int> first;                    // empty stack
      ft::stack<int> first1;


      std::cout << "std::stack:\nis first Empty? " << std::boolalpha <<first.empty() << std::endl;
      std::cout << "ft::stack:\nis first1 Empty? "<< std::boolalpha <<first1.empty() << std::endl;
      first.push(1); first.push(2); first.push(3); first.push(4);
      first1.push(1); first1.push(2); first1.push(3); first1.push(4);

      std::cout << "size of first: " << first.size() << '\n';
      std::cout << "size of first1: " << first1.size() << '\n';

      std::stack<int> second(first);		// stack initialized to copy of first
      ft::stack<int> second1(first1);		//4 3 2 1

      std::cout << "top of second: " << second.top() << '\n';
      std::cout << "top of second1: " << second1.top() << '\n';

      second.pop(); //3 2 1
      second1.pop(); //3 2 1

      std::cout << "top of second: " << second.top() << '\n';
      std::cout << "top of second1: " << second1.top() << '\n';


      if (first == second)						//first/4 3 2 1  second/3 2 1
        std::cout << "std:: first = second\n";
      if (first != second)
        std::cout << "std:: first != second\n";
      if (first > second)
        std::cout << "std:: first > second\n";
      if (first < second)
        std::cout << "std:: first < second\n";

      if (first1 == second1)
        std::cout << "ft:: first1 = second1\n";
      if (first1 != second1)
        std::cout << "ft:: first1 != second1\n";
      if (first1 > second1)
        std::cout << "ft:: first1 > second1\n";
      if (first1 < second1)
        std::cout << "ft:: first1 < second1\n";

    }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
    
      std::cout <<GREEN << "\n" << "STACK TESTS finished" << "\n"<< DEFAULT;
      /**************VECTOR cases finished******************/
      



//  << BLUE << DEFAULT
      /*****************MAP test cases start************************/
      std::cout  << BLUE << "\n" << "MAP TESTS start" << "\n"<< DEFAULT;

    

    {
       std::cout  << BLUE << "\n" << "MAP default constructor test" << "\n"<< DEFAULT;
      //https://en.cppreference.com/w/cpp/container/map/map

      // (1) Default constructor
      std::map<std::string, int> map1;
      map1["something"] = 69;
      map1["anything"] = 199;
      map1["that thing"] = 50;
      std::cout << "map1 = "; 
      std::cout << '{';
      std::map<std::string, int>::iterator itr;  
      for (itr = map1.begin(); itr != map1.end(); ++itr) 
        std::cout << itr->first << ':' << itr->second << ' ';      
      std::cout << "}\n";

      ft::map<std::string, int> map2;
      map2["something"] = 69;
      map2["anything"] = 199;
      map2["that thing"] = 50;
      std::cout << "map2 = "; 

      std::cout << '{';
      ft::map<std::string, int>::iterator itr2;  
      for (itr2 = map2.begin(); itr2 != map2.end(); ++itr2) 
        std::cout << itr2->first << ':' << itr2->second << ' ';      
      std::cout << "}\n";

      //clang++ ft_map.hpp ft_stack.hpp main.cpp
    }
      
    {
    //   // (2) Range constructor
      std::cout << BLUE  << "\n" << "Range constructor to make" << "\n"<< DEFAULT;

      std::map<std::string, int> map3;
      map3["something"] = 69;
      map3["anything"] = 199;
      map3["that thing"] = 50;

      // here is range constructor used
      std::map<std::string, int> iter(map3.find("anything"), map3.end());

      std::cout << "map3 (key found) = "; 
            std::cout << '{';
      std::map<std::string, int>::iterator itr2;  
      for (itr2 = map3.find("anything"); itr2 != map3.end(); ++itr2) 
        std::cout << itr2->first << ':' << itr2->second << ' ';      
      std::cout << "}\n";



     ft::map<std::string, int> map4;
      map4["something"] = 69;
      map4["anything"] = 199;
      map4["that thing"] = 50;

      // here is range constructor used
      ft::map<std::string, int> iter2(map4.find("anything"), map4.end());
      std::cout << "range constructor works" << "\n";
        
      std::cout << "map3 (key found) = "; 
            std::cout << '{';
      ft::map<std::string, int>::iterator it;  
      for (it = map4.find("anything"); it != map4.end(); ++it) 
        std::cout << it->first << ':' << it->second << ' ';      
      std::cout << "}\n";


    }




    {
      //write methods
       std::cout << BLUE << "\n" << "MAP operator = test" << "\n"<< DEFAULT ;
      //https://m.cplusplus.com/reference/map/map/operator=/
        std::map<char,int> first;
        std::map<char,int> second;

        first['x']=8;
        first['y']=16;
        first['z']=32;

        second=first;                // second now contains 3 ints
        first=std::map<char,int>();  // and first is now empty

        std::cout << "Size of std::map first: " << first.size() << '\n';
        std::cout << "Size of std::map second: " << second.size() << '\n';

        
        
        ft::map<char,int> first1;
        ft::map<char,int> second1;


        first1['x']=8;
        first1['y']=16;
        first1['z']=32;

        //the operator = works here
        second1=first1; // second had zero elements now contains 3 ints
        first1 = ft::map<char,int>();

        std::cout << "Size of ft::map first: " << first.size() << '\n';
        std::cout << "Size of ft::map second: " << second.size() << '\n';
      
    }


    
    {
      //https://m.cplusplus.com/reference/map/map/size/
      std::cout  << BLUE << "\n" << "MAP capacity: size() test" << "\n"<< DEFAULT;
      
      std::map<char,int> mymap;
      mymap['a']=101;
      mymap['b']=202;
      mymap['c']=302;

      std::cout << "std::map mymap.size() is " << mymap.size() << '\n';


      ft::map<char,int> mymap1;
      mymap1['a']=101;
      mymap1['b']=202;
      mymap1['c']=302;

      std::cout << "ft::map mymap.size() is " << mymap1.size() << '\n';
      
    }

    {
      std::cout  << BLUE << "\n" << "MAP capacity: max_size() test" << "\n"<< DEFAULT;
      //https://m.cplusplus.com/reference/map/map/max_size/
        int i;
        std::map<int,int> mymap;

        if (mymap.max_size()>1000)
        {
          for (i=0; i<1000; i++) mymap[i]=0;
          std::cout << "The std::map contains 1000 elements.\n";
        }
        else std::cout << "The std::map could not hold 1000 elements.\n";
    


        int i1;
        ft::map<int,int> mymap1;

        if (mymap1.max_size()>1000)
        {
          for (i1=0; i1<1000; i1++) mymap1[i1]=0;
          std::cout << "The ft::map contains 1000 elements.\n";
        }
        else std::cout << "The ft::map could not hold 1000 elements.\n";
        //clang++ ft_map.hpp ft_stack.hpp main.cpp 
    } 
    
    {
      std::cout  << BLUE << "\n" << "MAP capacity: empty() test" << "\n"<< DEFAULT;
      //https://m.cplusplus.com/reference/map/map/empty/
      std::map<char,int> mymap;

      mymap['a']=10;
      mymap['b']=20;
      mymap['c']=30;
      
      std::cout << "The std::map is not empty and has 3 pairs of elements\n";
      while (!mymap.empty())
      {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        mymap.erase(mymap.begin());
      }

      
      ft::map<char,int> mymap1;

      mymap1['a']=10;
      mymap1['b']=20;
      mymap1['c']=30;

      std::cout << "The ft::map is not empty and has 3 pairs of elements\n";
      while (!mymap1.empty())
      {
        std::cout << mymap1.begin()->first << " => " << mymap1.begin()->second << '\n';
        mymap1.erase(mymap1.begin());
      }
    }

    {
      std::cout  << BLUE << "\n" << "MAP element access method: operator[] test" << "\n"<< DEFAULT;
      //https://m.cplusplus.com/reference/map/map/operator[]/
      std::map<char,std::string> mymap;

      mymap['a']="an element";
      mymap['b']="another element";
      mymap['c']=mymap['b'];

      std::cout << "mymap['a'] is " << mymap['a'] << '\n';
      std::cout << "mymap['b'] is " << mymap['b'] << '\n';
      std::cout << "mymap['c'] is " << mymap['c'] << '\n';
      std::cout << "mymap['d'] is " << mymap['d'] << '\n';// has no elements

      std::cout << "std::map mymap now contains " << mymap.size() << " elements.\n";


      ft::map<char,std::string> mymap1;

      mymap1['a']="an element";
      mymap1['b']="another element";
      mymap1['c']=mymap1['b'];

      std::cout << "mymap1['a'] is " << mymap1['a'] << '\n';
      std::cout << "mymap1['b'] is " << mymap1['b'] << '\n';
      std::cout << "mymap1['c'] is " << mymap1['c'] << '\n';
      std::cout << "mymap1['d'] is " << mymap1['d'] << '\n';// has no elements

      std::cout << "ft::map mymap1 now contains " << mymap1.size() << " elements.\n"; 
    }

    {
      std::cout  << BLUE << "\n" << "MAP element access method: at() test" << "\n"<< DEFAULT;
      //https://m.cplusplus.com/reference/map/map/at/
      std::map<std::string, int> map1;
      map1["alpha"] = 0;
      map1["beta"] = 0;
      map1["gamma"] = 0;

      map1.at("alpha") = 10;
      map1.at("beta") = 20;
      map1.at("gamma") = 30;

      
      std::cout << "map1 = "; 
      std::cout << '{';
      std::map<std::string, int>::iterator itr;  
      for (itr = map1.begin(); itr != map1.end(); ++itr) 
        std::cout << itr->first << ':' << itr->second << ' ';      
      std::cout << "}\n";



      ft::map<std::string, int> map2;
      map2["alpha"] = 0;
      map2["beta"] = 0;
      map2["gamma"] = 0;

      map2.at("alpha") = 10;
      map2.at("beta") = 20;
      map2.at("gamma") = 30;

      
      std::cout << "map1 = "; 
      std::cout << '{';
      ft::map<std::string, int>::iterator it; // dont forget to use ft:: 
      for (it = map2.begin(); it != map2.end(); ++it) 
        std::cout << it->first << ':' << it->second << ' ';      
      std::cout << "}\n";
    }


     /***************MAP MODIFIERS********************/ 
    {
      //https://m.cplusplus.com/reference/map/map/insert/
     /*
      Extends the container by inserting new elements,
      effectively increasing the container size by the number of elements inserted.

      Because element keys in a map are unique, the insertion operation checks
      whether each inserted element has a key equivalent to the one of an element already in the container, 
      and if so, the element is not inserted, 
      returning an iterator to this existing element (if the function returns a value)
     */

      std::cout  << BLUE << "\n" << "MAP modifier method: insert() test" << "\n"<< DEFAULT;
      //https://m.cplusplus.com/reference/map/map/insert/

      std::map<char,int> mymap;

      // first insert function version (single parameter):
      /*
      The single element versions (1) return a pair, 
      with its member pair::first set to an iterator pointing to either the newly inserted element or
      to the element with an equivalent key in the map. 
      The pair::second element in the pair is set to true 
      if a new element was inserted or false if an equivalent key already existed
      */
      mymap.insert ( std::pair<char,int>('a',100) );
      mymap.insert ( std::pair<char,int>('z',200) );

      std::pair<std::map<char,int>::iterator,bool> ret;
      ret = mymap.insert ( std::pair<char,int>('z',500) );
      if (ret.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
      }

      // second insert function version (with hint position):
      /*
        The versions with a hint (2) return an iterator 
        pointing to either the newly inserted element or 
        to the element that already had an equivalent key in the map.
      */
      std::map<char,int>::iterator it = mymap.begin();
      mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
      mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

      // third insert function version (range insertion):
      /*
        Member type iterator is a bidirectional iterator type that points to elements.
        pair is a class template declared in <utility> (see pair).
      */
      std::map<char,int> anothermap;
      anothermap.insert(mymap.begin(),mymap.find('c')); // inserted up to c key (but excluding it)

      // showing contents:
      std::cout << "std::map mymap contains:\n";
      for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

      std::cout << "ft::map anothermap contains:\n";
      for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';





      ft::map<char,int> mymap1;

      // first insert function version (single parameter):
      mymap1.insert ( ft::pair<char,int>('a',100) );
      mymap1.insert ( ft::pair<char,int>('z',200) );

      ft::pair<ft::map<char,int>::iterator,bool> ret1;
      ret1 = mymap1.insert ( ft::pair<char,int>('z',500) );
      if (ret1.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret1.first->second << '\n'; // the second element in the pair
      }

      // second insert function version (with hint position):
      ft::map<char,int>::iterator it1 = mymap1.begin();
      mymap1.insert (it1, ft::pair<char,int>('b',300));  // max efficiency inserting
      mymap1.insert (it1, ft::pair<char,int>('c',400));  // no max efficiency inserting

      // third insert function version (range insertion):
      ft::map<char,int> anothermap1;
      anothermap1.insert(mymap1.begin(),mymap1.find('c')); // inserted up to c key (but excluding it)

      // showing contents:
      std::cout << "ft::map mymap1 contains:\n";
      for (it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
        std::cout << it1->first << " => " << it1->second << '\n';

      std::cout << "ft::map anothermap1 contains:\n";
      for (it1=anothermap1.begin(); it1!=anothermap1.end(); ++it1)
        std::cout << it1->first << " => " << it1->second << '\n';
    }



    {
       std::cout  << BLUE << "\n" << "MAP modifier method: erase() test" << "\n"<< DEFAULT;
       //https://m.cplusplus.com/reference/map/map/erase/
        std::map<char,int> mymap;
        std::map<char,int>::iterator it;

        // assign some values:
        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;
        mymap['d']=40;
        mymap['e']=50;
        mymap['f']=60;

        it=mymap.find('b');
        mymap.erase (it);                   // erasing by iterator

        mymap.erase ('c');                  // erasing by key

        it=mymap.find ('e');
        mymap.erase ( it, mymap.end() );    // erasing by range

        // show content: a and d keys should be left
         std::cout << "std::map mymap has after erasing b, c, e - f" << "\n";
        for (it=mymap.begin(); it!=mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';



        ft::map<char,int> mymap1;
        ft::map<char,int>::iterator it1;

        // assign some values:
        mymap1['a']=10;
        mymap1['b']=20;
        mymap1['c']=30;
        mymap1['d']=40;
        mymap1['e']=50;
        mymap1['f']=60;

        it1=mymap1.find('b');
        mymap1.erase (it1);                   // erasing by iterator

        mymap1.erase ('c');                  // erasing by key

        it1=mymap1.find ('e');
        mymap1.erase ( it1, mymap1.end() );    // erasing by range

        // show content: a and d keys should be left
        std::cout << "ft::map mymap1 has after erasing b, c, e - f" << "\n";
        for (it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
          std::cout << it1->first << " => " << it1->second << '\n';
    }

    {
        std::cout  << BLUE << "\n" << "MAP modifier method: swap() test" << "\n"<< DEFAULT;
        //https://m.cplusplus.com/reference/map/map/swap/
        /*
        Another map container of the same type as this (i.e., with the same template parameters, Key, T, Compare and Alloc) 
        whose content is swapped with that of this container.

        swaps maps
        */
        std::map<char,int> foo,bar;

        foo['x']=100;
        foo['y']=200;

        bar['a']=11;
        bar['b']=22;
        bar['c']=33;

        foo.swap(bar);

        std::cout << "std::map foo contains:\n";
        for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';

        std::cout << "std::map bar contains:\n";
        for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';




       
        ft::map<char,int> foo1;
        ft::map<char,int> bar1;
        

        foo1['x']=100;
        foo1['y']=200;

        bar1['a']=11;
        bar1['b']=22;
        bar1['c']=33;

        foo1.swap(bar1);

        std::cout << "ft::map foo1 contains:\n";
        for (ft::map<char,int>::iterator it1=foo1.begin(); it1!=foo1.end(); ++it1)
          std::cout << it1->first << " => " << it1->second << '\n';

        std::cout << "ft::map bar1 contains:\n";
        for (ft::map<char,int>::iterator it2=bar1.begin(); it2!=bar1.end(); ++it2)
          std::cout << it2->first << " => " << it2->second << '\n';
    }

    {
      /*
        Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
      */
      //https://m.cplusplus.com/reference/map/map/clear/
      std::cout  << BLUE << "\n" << "MAP modifier method: clear() test" << "\n"<< DEFAULT;

      std::map<char,int> mymap;

      mymap['x']=100;
      mymap['y']=200;
      mymap['z']=300;

      std::cout << "std::map mymap contains:\n";
      for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

      mymap.clear(); // cleared everything
      mymap['a']=1101;
      mymap['b']=2202;

      std::cout << "std::map mymap contains:\n";
      for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';


      ft::map<char,int> mymap1;

      mymap1['x']=100;
      mymap1['y']=200;
      mymap1['z']=300;

      std::cout << "ft::map mymap contains:\n";
      for (ft::map<char,int>::iterator it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
        std::cout << it1->first << " => " << it1->second << '\n';

      mymap1.clear(); // cleared everything
      mymap1['a']=1101;
      mymap1['b']=2202;

      std::cout << "ft::map mymap contains:\n";
      for (ft::map<char,int>::iterator it2=mymap1.begin(); it2!=mymap1.end(); ++it2)
        std::cout << it2->first << " => " << it2->second << '\n';
     
    }

    /***************MAP OBSERVERS methods************/

    {   		
      //https://m.cplusplus.com/reference/map/map/key_comp/
      /*
        Returns a copy of the comparison object used by the container to compare keys.
      */ 
      std::cout  << BLUE << "\n" << "MAP observer method: key_comp() test" << "\n"<< DEFAULT;
      std::map<char,int> mymap;

      std::map<char,int>::key_compare mycomp = mymap.key_comp();

      mymap['a']=100;
      mymap['b']=200;
      mymap['c']=300;
      

      std::cout << "std::map mymap contains:\n";

      char highest = mymap.rbegin()->first;     // key value of last element: 300

      std::map<char,int>::iterator it = mymap.begin();
      do {
        std::cout << it->first << " is less than or equal to => " << it->second << '\n';
      } while ( mycomp((*it++).first, highest) ); //print out while the first iter value is less than the second
      // https://www.cplusplus.com/reference/functional/less/
      /*
        Binary function object class 
        whose call returns whether its first argument compares less 
        than the second (as returned by operator <).

        Generically, function objects are instances of a class with member function operator() defined. 
        This member function allows the object to be used with the same syntax as a function call
      */

      std::cout << '\n';



  
      ft::map<char,int> mymap1;

      ft::map<char,int>::key_compare mycomp1 = mymap1.key_comp();

      mymap1['a']=100;
      mymap1['b']=200;
      mymap1['c']=300;
      

      std::cout << "ft::map mymap1 contains:\n";

      char highest1 = mymap1.rbegin()->first;     // key value of last element: 300

      ft::map<char,int>::iterator it1 = mymap1.begin();
      do {
        std::cout << it1->first << " is less than or equal to => " << it1->second << '\n';
      } while ( mycomp1((*it1++).first, highest1) ); //print out while the first iter value is less than the second
      // https://www.cplusplus.com/reference/functional/less/
      /*
        Binary function object class 
        whose call returns whether its first argument compares less 
        than the second (as returned by operator <).

        Generically, function objects are instances of a class with member function operator() defined. 
        This member function allows the object to be used with the same syntax as a function call
      */

      std::cout << '\n';
    }

    {
      std::cout  << BLUE << "\n" << "MAP observer method: value_comp() test" << "\n"<< DEFAULT;
      //https://m.cplusplus.com/reference/map/map/value_comp/

      /* this method is also based on less  https://www.cplusplus.com/reference/functional/less/  so the code is almost the same here */
      std::map<char,int> mymap;

      mymap['x']=1001;
      mymap['y']=2002;
      mymap['z']=3003;

      std::cout << "std::map mymap contains:\n";

      std::pair<char,int> highest = *mymap.rbegin();          // last element

      std::map<char,int>::iterator it = mymap.begin();
      do {
        std::cout << it->first << " => " << it->second << '\n';
      } while ( mymap.value_comp()(*it++, highest) );


 
      ft::map<char,int> mymap1;

      mymap1['x']=1001;
      mymap1['y']=2002;
      mymap1['z']=3003;

      std::cout << "ft::map mymap contains:\n";

      ft::pair<char,int> highest1 = *mymap1.rbegin();// last element

      ft::map<char,int>::iterator it1 = mymap1.begin();
      do {
        std::cout << it1->first << " => " << it1->second << '\n';
      } while ( mymap1.value_comp()(*it1++, highest1) );
    }


    /***************MAP OPERATIONS methods************/
    {
       /*Searches the container for an element with a key equivalent to k 
       and returns an iterator to it if found, otherwise it returns an iterator to map::end. */
       // https://m.cplusplus.com/reference/map/map/find/
      std::cout  << BLUE << "\n" << "MAP OPERATIONS method: find() test" << "\n"<< DEFAULT;
      std::map<char,int> mymap;
      std::map<char,int>::iterator it;

      mymap['a']=50;
      mymap['b']=100;
      mymap['c']=150;
      mymap['d']=200;

      it = mymap.find('b');
      if (it != mymap.end())
        mymap.erase (it);

      // print content:
      std::cout << "elements in std::map mymap:" << '\n';
      std::cout << "a => " << mymap.find('a')->second << '\n';
      std::cout << "c => " << mymap.find('c')->second << '\n';
      std::cout << "d => " << mymap.find('d')->second << '\n';


      ft::map<char,int> mymap1;
      ft::map<char,int>::iterator it1;

      mymap1['a']=50;
      mymap1['b']=100;
      mymap1['c']=150;
      mymap1['d']=200;

      it1 = mymap1.find('b');
      if (it1 != mymap1.end())
        mymap1.erase (it1);

      // print content:
      std::cout << "elements in ft::map mymap:" << '\n';
      std::cout << "a => " << mymap1.find('a')->second << '\n';
      std::cout << "c => " << mymap1.find('c')->second << '\n';
      std::cout << "d => " << mymap1.find('d')->second << '\n';
    }


    {
      //https://m.cplusplus.com/reference/map/map/count/
      // T think this method should be called search (not count)
      std::cout  << BLUE << "\n" << "MAP OPERATIONS method: count() test" << "\n"<< DEFAULT;
      /*
        Searches the container for elements with a key equivalent to k and returns the number of matches.

        Because all elements in a map container are unique, 
        the function can only return 1 (if the element is found) or zero (otherwise).

        Two keys are considered equivalent if the container's comparison object returns false reflexively 
        (i.e., no matter the order in which the keys are passed as arguments).
      */
      
      std::map<char,int> mymap;
      char c;

      mymap ['a']=101;
      mymap ['c']=202;
      mymap ['f']=303;

      for (c='a'; c<'h'; c++)
      {
        std::cout << c;
        if (mymap.count(c)>0) // if found it will return 1
          std::cout << " is an element of std::map mymap.\n";
        else // returns 0
          std::cout << " is not an element of std::map mymap.\n";
      }
       std::cout << '\n';

      ft::map<char,int> mymap1;
      char c1;

      mymap1 ['a']=101;
      mymap1 ['c']=202;
      mymap1 ['f']=303;

      for (c1='a'; c1<'h'; c1++) // up to h but excluding h
      {
        std::cout << c1;
        if (mymap1.count(c1)>0) // if found it will return 1
          std::cout << " is an element of ft::map mymap.\n";
        else // returns 0
          std::cout << " is not an element of ft::map mymap.\n";
      }
      std::cout << '\n';


    }

    {
       std::cout  << BLUE << "\n" << "MAP OPERATIONS method: lower/upper_bound() test" << "\n"<< DEFAULT;
        /*
        https://m.cplusplus.com/reference/map/map/lower_bound/
        
        upper_bound, has the same behavior as lower_bound,
         except in the case that the map contains an element with a key equivalent to k: 
         In this case, lower_bound returns an iterator pointing to that element, 
         whereas upper_bound returns an iterator pointing to the next element.
        
        */
       
        std::map<char,int> mymap;
        std::map<char,int>::iterator itlow,itup;

        mymap['a']=20;
        mymap['b']=40;
        mymap['c']=60;
        mymap['d']=80;
        mymap['e']=100;

        //returns a pointer to the key
        itlow=mymap.lower_bound ('b');  // itlow points to b 
        //returns a pointer next to the key
        itup=mymap.upper_bound ('d');   // itup points to e (not d!)

        mymap.erase(itlow,itup);        // erases [itlow,itup)

        // print content:
        for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';


        ft::map<char,int> mymap1;
        ft::map<char,int>::iterator itlow1,itup1;

        mymap1['a']=20;
        mymap1['b']=40;
        mymap1['c']=60;
        mymap1['d']=80;
        mymap1['e']=100;

        //returns a pointer to the key
        itlow1 =mymap1.lower_bound ('b');  // itlow points to b 
        //returns a pointer next to the key
        itup1=mymap1.upper_bound ('d');   // itup points to e (not d!)

        mymap1.erase(itlow1,itup1);        // erases [itlow,itup)

        // print content:
        for (ft::map<char,int>::iterator it1=mymap1.begin(); it1!=mymap1.end(); ++it1)
          std::cout << it1->first << " => " << it1->second << '\n';
    }

    {
        std::cout  << BLUE << "\n" << "MAP OPERATIONS method: equal_range() test" << "\n"<< DEFAULT;
        /*
        https://m.cplusplus.com/reference/map/map/equal_range/
        
        Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.

        Because the elements in a map container have unique keys, the range returned will contain a single element at most.

        If no matches are found, the range returned has a length of zero, with both iterators pointing to the first element that has a key considered to go after k according to the container's internal comparison object (key_comp).

        Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).

          
        The function returns a pair, whose member pair::first is the lower bound of the range 
        (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).

        If the map object is const-qualified, the function returns a pair of const_iterator. 
        Otherwise, it returns a pair of iterator.

        Member types iterator and const_iterator are bidirectional iterator types
         pointing to elements (of type value_type).
        Notice that value_type in map containers 
        is itself also a pair type: pair<const key_type, mapped_type>.
        */
        std::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20; 
        mymap['c']=30;

        std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b'); //iterator will point to 20

        std::cout << "std::map lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "std::map upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';


        ft::map<char,int> mymap1;

        mymap1['a']=10;
        mymap1['b']=20; 
        mymap1['c']=30;

        ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret1;
        ret1 = mymap1.equal_range('b'); //iterator will point to 20

        std::cout << "ft::map lower bound points to: ";
        std::cout << ret1.first->first << " => " << ret1.first->second << '\n';

        std::cout << "ft::map upper bound points to: ";
        std::cout << ret1.second->first << " => " << ret1.second->second << '\n';
    }


    {
        std::cout  << BLUE << "\n" << "MAP get_allocator() test" << "\n"<< DEFAULT;
        //https://m.cplusplus.com/reference/map/map/get_allocator/
        int psize;
        std::map<char,int> mymap;
        std::pair<const char,int>* p;

        // allocate an array of 5 elements using mymap's allocator:
        p=mymap.get_allocator().allocate(5);

        // assign some values to array
        psize = sizeof(std::map<char,int>::value_type)*5;

        std::cout << "The allocated std::map has a size of " << psize << " bytes.\n";

        mymap.get_allocator().deallocate(p,5);



        int psize1;
        ft::map<char,int> mymap1;
        ft::pair<const char,int>* p1;

        // allocate an array of 5 elements using mymap's allocator:
        p1=mymap1.get_allocator().allocate(5);

        // assign some values to array
        psize1 = sizeof(ft::map<char,int>::value_type)*5;

        std::cout << "The allocated ft::map has a size of " << psize1 << " bytes.\n";

        mymap1.get_allocator().deallocate(p1,5);
    }

                                      /*Additional map tests*/
        
    {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
      std::cout <<BLUE<< "\n\t\t\t\tM A P EXTRA TESTS\nconstructors/size/maxsize/empty/lower_bound/upper_bound tests\n" <<DEFAULT;
      std::map<char,int> first;		ft::map<char,int> first1;
      first['a']=10;					first1['a']=10;
      first['b']=30;					first1['b']=30;
      first['c']=50;					first1['c']=50;
      first['d']=70;					first1['d']=70;
      first['f']=90;					first1['f']=90;
      //begin/end
      std::cout << "std::map<char,int> first: " << first.begin()->first << " " << first.begin()->second << std::endl;
      std::cout << "ft::map<char,int> first1: " << first1.begin()->first << " " << first1.begin()->second << std::endl;
      //range contructor
      std::map<char,int> second (first.begin(),first.end());
      ft::map<char,int> second1 (first1.begin(),first1.end());
      //size/maxsize/empty
      std::cout << "std::map<char,int> second: " << second.size() << " " << second.max_size() << " " << std::boolalpha << second.empty() << std::endl;
      std::cout << "ft::map<char,int> second1: " << second1.size() << " " << second1.max_size() << " " << std::boolalpha << second1.empty() << std::endl;
      //copy contructor
      std::map<char,int> third (second);
      ft::map<char,int> third1 (second1);
      // lower_bound/upper_bound
      std::cout << "std::map<char,int> first: " << third.lower_bound('e')->second << " " << third.upper_bound('b')->second << std::endl;
      std::cout << "ft::map<char,int> first1: " << third1.lower_bound('e')->second << " " << third1.upper_bound('b')->second << std::endl;
      }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

      {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
      std::cout <<BLUE<< "operator[]/at/pair/insert/swap tests\n" <<DEFAULT;
      std::map<float,std::string> first;		ft::map<float,std::string> first1;
      first[0.1]="You ";						first1[0.1]="much ";
      first[0.2]="have ";						first1[0.2]="I ";
      first[0.3]="no ";						first1[0.3]="hate ";
      first[0.4]="idea ";						first1[0.4]="the ";
      first[0.5]="how ";						first1[0.5]="ft_containers ";
      //[]
      std::cout << "std::map<float,std::string> first: " << first[0.1] << first[0.2] << first[0.3]<< first[0.4] << first[0.5] << first[42] << std::endl;
      std::cout << "ft::map<float,std::string> first1: " << first1[0.1] << first1[0.2] << first1[0.3]<< first1[0.4] << first1[0.5] << first[42] << std::endl;
      //at
      try
      {
        std::cout << "std::map<float,std::string> first: " << first.at(0.5) << std::endl << first.at(0.6) << std::endl;
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
      try
      {
        std::cout << "ft::map<float,std::string> first1: " << first1.at(0.5) << std::endl << first1.at(0.6) << std::endl;
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
      //pair/insert
      first.insert(std::pair<float, std::string>(99.9, "hello!"));
      first1.insert(ft::pair<float, std::string>(99.9, "hello!"));
      std::cout << "std::map<float,std::string> first: " << first[99.9] << std::endl;
      std::cout << "ft::map<float,std::string> first1: " << first1[99.9] << std::endl;
      //swap
      std::map<float,std::string> second;		ft::map<float,std::string> second1;
      second[1]="one ";						second1[1]="one ";
      second[2]="two ";						second1[2]="two ";
      second[3]="three ";						second1[3]="three ";
      second[4]="four ";						second1[4]="four ";
      second[5]="five ";						second1[5]="five ";
      first.swap(second);
      first1.swap(second1);
      std::cout << "std::map: after swap first-second: " << first[1] << first[2] << second[0.1]<< second[0.2] << std::endl;
      std::cout << "ft::map: after swap first-second: " << first1[1] << first1[2] << second1[0.1]<< second1[0.2] << std::endl;

      //~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
      std::cout <<BLUE<< "operator >< = !=/erase/count tests\n" <<DEFAULT;
      if (first == second)
        std::cout << "std:: first = second\n";
      if (first != second)
        std::cout << "std:: first != second\n";
      if (first > second)
        std::cout << "std:: first > second\n";
      if (first < second)
        std::cout << "std:: first < second\n";

      if (first1 == second1)
        std::cout << "ft:: first1 = second1\n";
      if (first1 != second1)
        std::cout << "ft:: first1 != second1\n";
      if (first1 > second1)
        std::cout << "ft:: first1 > second1\n";
      if (first1 < second1)
        std::cout << "ft:: first1 < second1\n";
      //erase
      std::cout << "first element of std::map before erase 1: "<< first.begin()->first << std::endl;
      std::cout << "first element of ft::map before erase 1: "<< first1.begin()->first << std::endl;
      first.erase(first.begin());
      first1.erase(first1.begin());
      std::cout << "first element of std::map after erase 1: " << first.begin()->first << std::endl;
      std::cout << "first element of ft::map after erase 1: " << first1.begin()->first << std::endl;

      //cout
      std::cout << "first.count(2): " << first.count(2) << std::endl;
      std::cout << "first1.count(2): " << first1.count(2) << std::endl;
      std::cout << "first.count(35): " << first.count(35) << std::endl;
      std::cout << "first1.count(35): " << first1.count(35) << std::endl;
	  }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/





    /**************SET container tests start*******************/

    {
      // <<YELLOW << DEFAULT;
      std::cout <<YELLOW << "\n" << "SET constructors test" << "\n" << DEFAULT;
      // https://m.cplusplus.com/reference/set/set/set/
      std::set<int> first;                           // empty set of ints

      int myints[]= {10,20,30,40,50};
      std::set<int> second(myints,myints+5);        // range

      std::set<int> third(second);                  // a copy of second

      std::set<int> fourth(second.begin(), second.end());  // iterator ctor.

      std::set<int>::iterator iter = second.begin();
      std::cout << "std::set array second (used range constructor with iterators from myints) is" << std::endl;
      for(; iter != second.end(); iter++)
        std::cout << *iter << " ";
      std::cout << '\n';
      
      std::set<int>::iterator iter2 = third.begin();
      std::cout << "std::set array third (used copy constructor from second) is" << std::endl;
      for(; iter2 != third.end(); iter2++)
          std::cout << *iter2 << " ";
       std::cout << '\n';


      
      ft::set<int> first1;                           // empty set of ints

      int myints1[]= {10,20,30,40,50};
      ft::set<int> second1(myints1,myints1+5);        // range

      ft::set<int> third1(second1);                  // a copy of second

      ft::set<int> fourth1(second1.begin(), second1.end());  // iterator ctor.

      ft::set<int>::iterator iter1 = second1.begin();
      std::cout << "ft::set array second (used range constructor with iterators from myints) is" << std::endl;
      for(; iter1 != second1.end(); iter1++)
        std::cout << *iter1 << " ";
      std::cout << '\n';


      ft::set<int>::iterator iter21 = third1.begin();
      std::cout << "ft::set array third (used copy constructor from second) is" << std::endl;
      for(; iter21 != third1.end(); iter21++)
          std::cout << *iter21 << " ";
      std::cout << '\n';
      
    }

    {
        std::cout <<YELLOW << "\n" << "SET operator= test" << "\n" << DEFAULT;
        //https://m.cplusplus.com/reference/set/set/operator=/
      
        int myints[]={ 12,82,37,64,15 };
        std::set<int> first (myints,myints+5);   // set with 5 ints
        std::set<int> second;                    // empty set

        second = first;                          // now second contains the 5 ints
        first = std::set<int>();                 // and first is empty

        std::cout << "Size of std::first: " << int (first.size()) << '\n';
        std::cout << "Size of std::second: " << int (second.size()) << '\n';
        std::cout << '\n';
        

        int myints1[]={ 12,82,37,64,15 };
        std::set<int> first1 (myints1,myints1+5);   // set with 5 ints
        std::set<int> second1;                    // empty set

        second1 = first1;                          // now second contains the 5 ints
        first1 = std::set<int>();                 // and first is empty

        std::cout << "Size of ft::first: " << int (first1.size()) << '\n';
        std::cout << "Size of ft::second: " << int (second1.size()) << '\n';
      
    }

    {
        std::cout <<YELLOW << "\n" << "SET CAPACITY empty() test" << "\n" << DEFAULT;
        //https://cplusplus.com/reference/set/set/empty/
        std::set<int> myset;

        myset.insert(20);
        myset.insert(30);
        myset.insert(10);

        std::cout << "std::set myset contains:";
        while (!myset.empty())
        {
          std::cout << ' ' << *myset.begin();
          myset.erase(myset.begin());
        }
        std::cout << '\n';


        ft::set<int> myset1;

        myset1.insert(20);
        myset1.insert(30);
        myset1.insert(10);

        std::cout << "ft::set myset contains:";
        while (!myset1.empty())
        {
          std::cout << ' ' << *myset1.begin();
          myset1.erase(myset1.begin());
        }
        std::cout << '\n';    
    }

    {
      std::cout <<YELLOW<< "\n" << "SET CAPACITY size() test" << "\n"<< DEFAULT;
      //https://cplusplus.com/reference/set/set/size/

        std::set<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<10; ++i) myints.insert(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.insert (100);
        std::cout << "2. size: " << myints.size() << '\n';

        myints.erase(5);
        std::cout << "3. size: " << myints.size() << '\n';


        ft::set<int> myints1;
        std::cout << "ft:set 0. size: " << myints1.size() << '\n';

        for (int i = 0; i < 10; ++i) myints1.insert(i);
        std::cout << "ft:set 1. size: " << myints1.size() << '\n';

        myints1.insert (100);
        std::cout << "ft:set 2. size: " << myints1.size() << '\n';

        myints1.erase(5);
        std::cout << "ft:set 3. size: " << myints1.size() << '\n';
    }

    {
        std::cout << YELLOW  "\n" << "SET CAPACITY max_size() test" << "\n" << DEFAULT;
        //https://cplusplus.com/reference/set/set/max_size/
        int i;
        std::set<int> myset;

        if (myset.max_size()>1000) 
        //Here, member max_size is used to check beforehand whether the set will allow for 1000 elements to be inserted.
        {
          for (i=0; i<1000; i++) 
            myset.insert(i);
          std::cout << "The set contains 1000 elements.\n";
        }
        else 
          std::cout << "The set could not hold 1000 elements.\n";
        std::cout << '\n';
        

        ft::set<int> myset1;
        if (myset1.max_size()>1000) 
        //Here, member max_size is used to check beforehand whether the set will allow for 1000 elements to be inserted.
        {
          for (i = 0; i < 1000; i++) 
            myset1.insert(i);
          std::cout << "The ft::set myset contains 1000 elements.\n";
        }
        else 
          std::cout << "The ft::set myset could not hold 1000 elements.\n";
    }

    {
        std::cout <<YELLOW << "\n" << "SET MODIFIERS insert() test" << "\n" << DEFAULT;
        //https://cplusplus.com/reference/set/set/insert/

        std::set<int> myset;
        std::set<int>::iterator it;
        std::pair<std::set<int>::iterator,bool> ret;

        // set some initial values:
        for (int i=1; i<=5; ++i) 
          myset.insert(i*10);    // set: 10 20 30 40 50

        ret = myset.insert(20);               // no new element inserted
        
        //The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent element already existed.
        if (ret.second==false)     
          it=ret.first;  // "it" now points to element 20

        myset.insert (it,25);                 // max efficiency inserting
        myset.insert (it,24);                 // max efficiency inserting
        myset.insert (it,26);                 // no max efficiency inserting

        int myints[]= {5,10,15};              // 10 already in set, not inserted
        myset.insert (myints,myints+3);

        std::cout << "std::set myset contains:";
        for (it=myset.begin(); it!=myset.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
        

        ft::set<int> myset1;
        ft::set<int>::iterator it1;
        ft::pair<ft::set<int>::iterator,bool> ret1;

        // set some initial values:
        for (int i=1; i<=5; ++i) 
          myset1.insert(i*10);    // set: 10 20 30 40 50

        ret1 = myset1.insert(20);               // no new element inserted
        
        //The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent element already existed.
        if (ret1.second==false)     
          it1=ret1.first;  // "it" now points to element 20

        myset1.insert (it1,25);                 // max efficiency inserting
        myset1.insert (it1,24);                 // max efficiency inserting
        myset1.insert (it1,26);                 // no max efficiency inserting

        int myints1[]= {5,10,15};              // 10 already in set, not inserted
        myset1.insert (myints1,myints1+3);

        std::cout << "ft::set myset1 contains:";
        for (it1=myset1.begin(); it1!=myset1.end(); ++it1)
          std::cout << ' ' << *it1;
        std::cout << '\n';
    }

    {
      std::cout <<YELLOW << "\n" << "!!!SET MODIFIERS erase() test" << "\n" << DEFAULT;
      // https://m.cplusplus.com/reference/set/set/erase/
      std::set<int> myset;
      std::set<int>::iterator it;

      // insert some values:
      for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

      it = myset.begin();
      ++it;                                         // "it" points now to 20

      myset.erase (it); 

      myset.erase (40);

      it = myset.find (60);
      myset.erase (it, myset.end());

      std::cout << "std::set myset contains:";
      for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';


      ft::set<int> myset1;
      ft::set<int>::iterator it1;

      // insert some values:
      for (int i=1; i<10; i++) 
        myset1.insert(i*10);  // 10 20 30 40 50 60 70 80 90

      it1 = myset1.begin();
      ++it1;                               // "it" points now to 20

      //does not erase in upper_bound()
      //myset1.erase (it1); //		void erase_fixup(node_pointer x) there is segfault

      myset1.erase (40);

      it1 = myset1.find(60);
      myset1.erase (it1, myset1.end());

      std::cout << "ft::set myset contains:";
      for (it1=myset1.begin(); it1!=myset1.end(); ++it1)
        std::cout << ' ' << *it1;
      std::cout << '\n';
    }

    {
        std::cout <<YELLOW << "\n" << "SET MODIFIERS swap() test" << "\n"<< DEFAULT;
        //https://m.cplusplus.com/reference/set/set/swap/

        int myints[]={12,75,10,32,20,25};
        std::set<int> first (myints,myints+3);     // 10,12,75
        std::set<int> second (myints+3,myints+6);  // 20,25,32

        first.swap(second);

        std::cout << "first contains:";
        for (std::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "second contains:";
        for (std::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';



        int myints1[]={12,75,10,32,20,25};
        ft::set<int> first1 (myints1,myints1+3);     // 10,12,75
        ft::set<int> second1 (myints1+3,myints1+6);  // 20,25,32

        first1.swap(second1);

        std::cout << "ft::set first contains:";
        for (ft::set<int>::iterator it1=first1.begin(); it1!=first1.end(); ++it1)
          std::cout << ' ' << *it1;
        std::cout << '\n';

        std::cout << "ft::set second contains:";
        for (ft::set<int>::iterator it1=second1.begin(); it1!=second1.end(); ++it1)
          std::cout << ' ' << *it1;
        std::cout << '\n';  
    }

    {
        std::cout <<YELLOW << "\n" << "SET MODIFIERS clear() test" << "\n"<< DEFAULT;
        //https://m.cplusplus.com/reference/set/set/clear/
        std::set<int> myset;

        myset.insert (100);
        myset.insert (200);
        myset.insert (300);

        std::cout << "myset contains:";
        for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';

        myset.clear();
        myset.insert (1101);
        myset.insert (2202);

        std::cout << "myset contains:";
        for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';





        ft::set<int> myset1;

        myset1.insert (100);
        myset1.insert (200);
        myset1.insert (300);

        std::cout << "ft::set myset contains:";
        for (ft::set<int>::iterator it1=myset1.begin(); it1!=myset1.end(); ++it1)
          std::cout << ' ' << *it1;
        std::cout << '\n';

        myset1.clear();
        myset1.insert (1101);
        myset1.insert (2202);

        std::cout << "ft::set myset contains:";
        for (ft::set<int>::iterator it1=myset1.begin(); it1!=myset1.end(); ++it1)
          std::cout << ' ' << *it1;
        std::cout << '\n';
    }

    {
      std::cout <<YELLOW << "\n" << "SET OBSERVERS key_comp() test" << "\n"<< DEFAULT;
      // https://m.cplusplus.com/reference/set/set/key_comp/

      std::set<int> myset;
      int highest;

      std::set<int>::key_compare mycomp = myset.key_comp();

      for (int i=0; i<=5; i++) myset.insert(i);

      std::cout << "std::set myset contains:";

      highest=*myset.rbegin();
      std::set<int>::iterator it=myset.begin();
      do {
        std::cout << ' ' << *it;
      } while ( mycomp(*(++it),highest) );

      std::cout << '\n';


      ft::set<int> myset1;
      int highest1;

      ft::set<int>::key_compare mycomp1 = myset1.key_comp();

      for (int i=0; i<=5; i++) myset1.insert(i);

      std::cout << "ft::set myset contains:";

      highest1=*myset1.rbegin();
      ft::set<int>::iterator it1=myset1.begin();
      do {
        std::cout << ' ' << *it1;
      } while ( mycomp1(*(++it1),highest1) );

      std::cout << '\n';

    }


    {
      std::cout <<YELLOW << "\n" << "SET OBSERVERS value_comp() test" << "\n"<< DEFAULT;//Returns a copy of the comparison object used by the container.
      //https://m.cplusplus.com/reference/set/set/value_comp/
      //key_comp defines the order of the keys in a container. value_comp defines the order of the values in a container.
        std::set<int> myset;

        std::set<int>::value_compare mycomp = myset.value_comp();

        for (int i=0; i<=5; i++) myset.insert(i);

        std::cout << "std::set myset contains:";

        int highest=*myset.rbegin();
        std::set<int>::iterator it=myset.begin();
        do {
          std::cout << ' ' << *it;
        } while ( mycomp(*(++it),highest) );

        std::cout << '\n';


        ft::set<int> myset1;
        ft::set<int>::value_compare mycomp1 = myset1.value_comp();
        for (int i=0; i<=5; i++) myset1.insert(i);

        std::cout << "ft::set myset contains:";

        int highest1=*myset1.rbegin();
        // int highest1=4; this is for test
        
        ft::set<int>::iterator it1=myset1.begin();
        do {
          std::cout << ' ' << *it1;
        } while ( mycomp1(*(++it1),highest1) ); // while less that highest will print

        std::cout << '\n'; 
    }


    {
      std::cout <<YELLOW << "\n" << "SET OPERATIONS find() test" << "\n"<< DEFAULT;
      //https://m.cplusplus.com/reference/set/set/find/
      //Searches the container for an element equivalent to val and returns an iterator to it if found, otherwise it returns an iterator to set::end.

        std::set<int> myset;
        std::set<int>::iterator it;

        // set some initial values:
        for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

        it=myset.find(20);
        myset.erase (it);
        myset.erase (myset.find(40));

        std::cout << "std::set myset contains:";
        for (it=myset.begin(); it!=myset.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';


        ft::set<int> myset1;
        ft::set<int>::iterator it1;

        // set some initial values:
        for (int i=1; i<=5; i++) 
          myset1.insert(i*10);    // set: 10 20 30 40 50

        it1=myset1.find(20);
        myset1.erase(it1);
        myset1.erase(myset1.find(40));

        std::cout << "ft::set myset contains:";
        for (it1 = myset1.begin(); it1 != myset1.end(); ++it1)
          std::cout << ' ' << *it1;
        std::cout << '\n';
    }

    {
      std::cout <<YELLOW << "\n" << "SET OPERATIONS count() test" << "\n"<< DEFAULT;
      //https://m.cplusplus.com/reference/set/set/count/
      /*
        Searches the container for elements equivalent to val and returns the number of matches.
        Because all elements in a set container are unique,
        the function can only return 1 (if the element is found) or zero (otherwise).
        Two elements of a set are considered equivalent 
        if the container's comparison object returns false reflexively 
        (i.e., no matter the order in which the elements are passed as arguments).
      */
      
      std::set<int> myset;

      // set some initial values:
      for (int i=1; i<5; ++i) 
        myset.insert(i*3);    // set: 3 6 9 12

      for (int i=0; i<10; ++i)
      {
        std::cout << i;
        if (myset.count(i)!=0)
          std::cout << " is an element of std::map myset.\n";
        else
          std::cout << " is not an element of std::map myset.\n";
      }
        std::cout << '\n';

      ft::set<int> myset1;
      // set some initial values:
      for (int i=1; i<5; ++i) 
        myset1.insert(i*3);    // set: 3 6 9 12

      for (int i=0; i<10; ++i)
      {
        std::cout << i;
        if (myset1.count(i)!=0)
          std::cout << " is an element of ft::set myset.\n";
        else
          std::cout << " is not an element of ft::set myset.\n";
      }
      
    }

    {
      std::cout <<YELLOW << "\n" << "SET OPERATIONS lower/upper_bound() test" << "\n"<< DEFAULT;
      // https://m.cplusplus.com/reference/set/set/lower_bound/
      //https://m.cplusplus.com/reference/set/set/upper_bound/
      std::set<int> myset;
      std::set<int>::iterator itlow,itup;

      for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

      itlow=myset.lower_bound (30);                //       ^
      itup=myset.upper_bound (60);                 //                   ^

      myset.erase(itlow,itup);                     // 10 20 70 80 90

      std::cout << "std::set myset contains:";
      for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';

      
      ft::set<int> myset1;
      ft::set<int>::iterator itlow1,itup1;

      for (int i=1; i<10; i++) 
        myset1.insert(i*10); // 10 20 30 40 50 60 70 80 90

      itlow1=myset1.lower_bound (30);                //       ^
      itup1=myset1.upper_bound (60);                 //                   ^

      //does not delete the last number in the range
      myset1.erase(itlow1,itup1);                     // 10 20 70 80 90

      std::cout << "!!!ft::set myset contains:";
      for (ft::set<int>::iterator it=myset1.begin(); it!=myset1.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';
    }


    {
      std::cout <<YELLOW << "\n" << "SET OPERATIONS equal_range() test" << "\n"<< DEFAULT;
      //https://m.cplusplus.com/reference/set/set/equal_range/
      std::set<int> myset;

      for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

      std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
      ret = myset.equal_range(30);

      std::cout << "std::set the lower bound points to: " << *ret.first << '\n';
      std::cout << "std::set the upper bound points to: " << *ret.second << '\n';


      ft::set<int> myset1;
      for (int i=1; i<=5; i++) myset1.insert(i*10);   // myset: 10 20 30 40 50

      ft::pair<ft::set<int>::const_iterator,ft::set<int>::const_iterator> ret1;
      ret1 = myset1.equal_range(30);

      std::cout << "ft::set the lower bound points to: " << *ret1.first << '\n';
      std::cout << "ft::set the upper bound points to: " << *ret1.second << '\n';
    }

    {
       std::cout<<YELLOW<<"\n" << "SET OPERATIONS allocator() test" << "\n"<< DEFAULT;
        //https://m.cplusplus.com/reference/set/set/get_allocator/
        std::set<int> myset;
        int * p;
        unsigned int i;

        // allocate an array of 5 elements using myset's allocator:
        p=myset.get_allocator().allocate(5);

        // assign some values to array
        for (i=0; i<5; i++) p[i]=(i+1)*10;

        std::cout << "The allocated std::set array contains:";
        for (i=0; i<5; i++) std::cout << ' ' << p[i];
        std::cout << '\n';

        myset.get_allocator().deallocate(p,5);


        ft::set<int> myset1;
        int * p1;
        unsigned int j;

        // allocate an array of 5 elements using myset's allocator:
        p1=myset1.get_allocator().allocate(5);

        // assign some values to array
        for (j=0; j<5; j++) 
          p1[j]=(j+1)*10;

        std::cout << "The allocated ft::set array contains:";
        for (j=0; j<5; j++) std::cout << ' ' << p1[j];
        std::cout << '\n';

        myset1.get_allocator().deallocate(p1,5);
      
    }


                              /*Additional set tests*/

    {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
      std::cout <<YELLOW<< "\n\t\t\t\tS E T EXTRA TESTS\nconstructors/insert/size/maxsize/empty/begin/empty tests\n" <<DEFAULT;
      std::set<int> first;                                // empty set of ints
      first.insert(0); first.insert(1); first.insert(2); first.insert(3);
      std::set<int> second (first.begin(), first.end());  // iterating through first
      std::set<int> third (second);                       // a copy of third

      ft::set<int> first1;                                // empty vector of ints
      first1.insert(0); first1.insert(1); first1.insert(2); first1.insert(3);
      std::set<int> second1 (first1.begin(), first1.end());  // iterating through first
      std::set<int> third1 (second1);                       // a copy of third
      //Size/maxsize
      std::cout << "std::set: Size/maxsize of first: " << first.size() << " " << first.max_size() << '\n';
      std::cout << "ft::set: Size/maxsize of first1: " << first1.size() << " " << first1.max_size() << '\n';
      //empty
      std::cout << "std::set: second is empty? : " << std::boolalpha << second.empty() << std::endl;
      std::cout << "ft::set: second1 is empty? : " << std::boolalpha << second1.empty() << std::endl;
      //insert duplicate
      first1.insert(0);									first.insert(0);
      std::cout << "std::set: Size/maxsize of first: " << first.size() << "\n";
      std::cout << "ft::set: Size/maxsize of first1: " << first1.size() << '\n';
    }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

    {//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
      std::cout <<YELLOW << "swap/find/cout tests\n" << DEFAULT;
      std::set<int> first;								ft::set<int> first1;
      first.insert(0); first.insert(1); first.insert(2); first.insert(3);
      first1.insert(0); first1.insert(1); first1.insert(2); first1.insert(3);
      std::set<int> second;								ft::set<int> second1;
      second.insert(4); second.insert(5); second.insert(6); second.insert(7);
      second1.insert(4); second1.insert(5); second1.insert(6); second1.insert(7);
      std::cout << "std::set: before swap first-second: " << *(first.find(0)) << " " << *(first.find(1)) << " " << *(first.find(2)) << " " << *(first.find(3)) << std::endl;
      std::cout << "ft::set: before swap first-second: " << *(first1.find(0)) << " " << *(first1.find(1)) << " " << *(first1.find(2)) << " " << *(first1.find(3)) << std::endl;
      first.swap(second);
      first1.swap(second1);
      std::cout << "std::set: after swap first-second: " << *(first.find(4)) << " " << *(first.find(5)) << " " << *(first.find(6)) << " " << *(first.find(7)) << std::endl;
      std::cout << "ft::set: after swap first-second: " << *(first1.find(4)) << " " << *(first1.find(5)) << " " << *(first1.find(6)) << " " << *(first1.find(7)) << std::endl;
      //cout
      std::cout << "first.count(4): " << first.count(4) << std::endl;
      std::cout << "first1.count(4): " << first1.count(4) << std::endl;
      std::cout << "first.count(35): " << first.count(35) << std::endl;
      std::cout << "first1.count(35): " << first1.count(35) << std::endl;
      // lower_bound/upper_bound
      std::cout << "std::set: first: " << *(first.lower_bound(42)) << " " << *(first.upper_bound(1)) << std::endl;
      std::cout << "ft::set: first1: " << *(first1.lower_bound(42)) << " " << *(first1.upper_bound(1)) << std::endl;

      std::cout << YELLOW << "operator >< = !=/erase/count tests\n" <<DEFAULT;
      if (first == second)
        std::cout << "std:: first = second\n";
      if (first != second)
        std::cout << "std:: first != second\n";
      if (first > second)
        std::cout << "std:: first > second\n";
      if (first < second)
        std::cout << "std:: first < second\n";

      if (first1 == second1)
        std::cout << "ft:: first1 = second1\n";
      if (first1 != second1)
        std::cout << "ft:: first1 != second1\n";
      if (first1 > second1)
        std::cout << "ft:: first1 > second1\n";
      if (first1 < second1)
        std::cout << "ft:: first1 < second1\n";
    }//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

  return 0;
}