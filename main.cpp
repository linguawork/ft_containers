/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:32:02 by areggie           #+#    #+#             */
/*   Updated: 2022/06/06 17:19:50 by areggie          ###   ########.fr       */
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

// for running tests
#include <iterator> // for printing out vector contents
#include <vector> // for comparative test
#include <stack> 
#include <map>



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

    {
      std::cout << "\n" << "DEBUGGING AT() from the tests" << "\n";

      int _ratio = 10000;
      std::vector<int> vector;
        
      vector.assign(9900 * _ratio, 1); //99 000 000 elements with 1 value in each
      
      
      std::cout << "The vector elements is : ";
      std::cout << vector.at(354 * _ratio) << ' '; //printout the 3 540 000th elem
      // why mine is zero, should be 1
      std::cout <<  std::endl;;



      ft::vector<int> ft_vector;
      ft_vector.assign(9900 * _ratio, 1); //99 000 000 elements with 1 value in each
      std::cout << "The ft_vector elements is : ";
      std::cout << ft_vector.at(0) << ' '; //printout the 3 540 000th elem
      std::cout << ft_vector.at(1) << ' '; 
        std::cout << ft_vector.at(354 * _ratio) << ' '; 
      // why mine is zero, should be 1
      /* 
      I printed out the values of different elements and it turns out that assign()
      assigns only to the 1st element, so it is not the problem of at()
      Method at() depends on the result of assign() in the test

      So I need to run test for assign to see the problem
      */
      std::cout <<  std::endl;;
      
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
        std::cout << "\n" << "back() test" << "\n";
      
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

    /*******************MODIFIERS**********************************/
    //https://www.cplusplus.com/reference/vector/vector/
    //Unit-tests mainly require assign() method, so one can start testing 
    {
      std::cout << "\n" << "assign() test" << "\n";
      

      std::vector<int> first;
      std::vector<int> second;
      std::vector<int> third;

      first.assign (7,100);// 7 ints with a value of 100


      std::vector<int>::iterator it;
      it=first.begin()+1; // making iterator on the second cell (+1)

      second.assign (it,first.end()-1); // from 2nd cell to the prefinal cell
      // the 5 central values of first

      int myints[] = {1776,7,4};
      third.assign (myints,myints+3);  // assigning from array.

      std::cout << "Size of std::vector first: " << int (first.size()) << '\n';
      std::cout << "Size of std::vector second: " << int (second.size()) << '\n';
      std::cout << "Size of std::vector third: " << int (third.size()) << '\n';
      
      ft::vector<int> first1;
      ft::vector<int> second1;
      ft::vector<int> third1;

      first1.assign (7,100);             // 7 ints with a value of 100


      ft::vector<int>::iterator it1;
      it1=first1.begin()+1; // making iterator on the second cell (+1)

      second1.assign (it1,first1.end()-1); // from 2nd cell to the prefinal cell
      // the 5 central values of first

      int myints1[] = {1776,7,4};
      third1.assign (myints1,myints1+3);  // assigning from array.

      std::cout << "Size of ft::vector first1: " << int (first1.size()) << '\n';
      std::cout << "Size of ft::vector second1: " << int (second1.size()) << '\n';
      std::cout << "Size of ft::vector third1: " << int (third1.size()) << '\n';
      
    }   

    {
    std::cout << "\n" << "DEBUG of ASSIGN()" << "\n";
    
    /*
    found problem in method reallocate in the cycle of construction
    */

    int _ratio = 3;
    std::vector<int> vector;
      
    vector.assign(2 * _ratio, 1); //99 000 000 elements with 1 value in each


    ft::vector<int> ft_vector;
      
    ft_vector.assign(2 * _ratio, 1); //99 000 000 elements with 1 value in each

        std::cout << "The vector elements are : ";
        for(int i=0; i < vector.size(); i++)
        std::cout << vector.at(i) << ' ';
        std::cout <<  std::endl;;

        std::cout << "The ft_vector elements are : ";
        for(int i=0; i < ft_vector.size(); i++)
        std::cout << ft_vector.at(i) << ' ';
        std::cout <<  std::endl;
      
    }   

  //https://www.cplusplus.com/reference/vector/vector/push_back/
    {
        std::cout << "\n" << "pushback() test commented so far" << "\n";
        // std::vector<int> myvector(100, 4);
        // int myint;

        // std::cout << "Please enter some integers for vector (enter 0 to end):\n";

        // do 
        // {
        //   std::cin >> myint;
        //   myvector.push_back (myint);
        // } while (myint);

        // std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
              
        // std::vector<int>::size_type sz;
        // sz = myvector.capacity(); 
        // std::cout << "capacity of vector changed: " << sz << '\n';





        // ft::vector<int> ftvector(100, 4);;
        // int ftint;

        // std::cout << "Please enter some integers for ft_vector (enter 0 to end):\n";

        // do 
        // {
        //   std::cin >> ftint;
        //   ftvector.push_back (ftint);
        // } while (ftint);

        // std::cout << "ft::vector stores " << int(ftvector.size()) << " numbers.\n";
        // ft::vector<int>::size_type sz1;
        // sz1 = ftvector.capacity(); 
        // std::cout << "capacity of ft_vector changed: " << sz1 << '\n';
    }


  //https://www.cplusplus.com/reference/vector/vector/pop_back/
    {

        std::cout << "\n" << "pop_back() test" << "\n";
        std::vector<int> myvector;
        int sum (0);
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        while (!myvector.empty()) 
        {
          sum+=myvector.back();
          myvector.pop_back();
        }
        std::cout << "The elements of myvector add up to " << sum << '\n';
        std::cout << "Size of std::myvector now: " << (myvector.size()) << '\n';

        ft::vector<int> ft_vector;
        int sum1 (0);
        ft_vector.push_back (100);
        ft_vector.push_back (200);
        ft_vector.push_back (300);

        while (!ft_vector.empty()) //debugged size = 0 there
        {
          sum1+=ft_vector.back();
          ft_vector.pop_back();
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
        
    }

    //https://www.cplusplus.com/reference/vector/vector/insert/
    {
      std::cout << "\n" << "insert() test" << "\n";
      std::vector<int> myvector (3,100); //100 100 100
      std::vector<int>::iterator it;
      // it = myvector.begin();
      //     for (it=myvector.begin(); it<myvector.end(); it++)
      //   std::cout << ' ' << *it;
      // std::cout << '\n';


    

      it = myvector.begin();
      it = myvector.insert ( it , 200 ); // it is one the first, inserted on the first place  
      //200 100 100 100

      myvector.insert (it,2,300); // it is on the first  and inserts two elements from the pos of it
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
      std::cout << "myvector contains:";
      for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
      std::cout << '\n';





      ft::vector<int> ft_vector (3,100);
      ft::vector<int>::iterator it1;

      it1 = ft_vector.begin();
      it1 = ft_vector.insert ( it1 , 200 ); // insert one element

      ft_vector.insert (it1,2,300); // insert fill with 2 

      // "it" no longer valid, get a new one:
      it1 = ft_vector.begin();


      //insert range
      std::vector<int> anothervector1 (2,400);
      ft_vector.insert (it1+2,anothervector1.begin(),anothervector1.end());

      int myarray1 [] = { 501,502,503 };
      ft_vector.insert (ft_vector.begin(), myarray1, myarray1+3);

      std::cout << "ft_vector contains:";
      for (it1=ft_vector.begin(); it1<ft_vector.end(); it1++)
        std::cout << ' ' << *it1;
      std::cout << '\n';
    }


    //https://www.cplusplus.com/reference/vector/vector/erase/
    {
      std::cout << "\n" << "erase() test" << "\n";
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
      std::cout << "\n" << "swap() test" << "\n";
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
        std::cout << "\n" << "clear() test" << "\n";
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
        std::cout << "\n" << "get_allocator() test" << "\n";
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
      std::cout << "\n" << "relational operators() test" << "\n";
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
      std::cout << "\n" << "VECTOR cases finished" << "\n";
      /**************VECTOR cases finished******************/
      
      /*****************STACK test cases start************************/
      std::cout << "\n" << "STACK test cases start" << "\n";

    }



    {
      //https://en.cppreference.com/w/cpp/container/stack/top
      std::cout << "\n" << "STACK top() test" << "\n";
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
      std::cout << "\n" << "STACK empty() test" << "\n";
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
      std::cout << "\n" << "STACK size() test" << "\n";
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
      std::cout << "\n" << "STACK push() and pop() test" << "\n";
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

    {
      std::cout << "\n" << "STACK TESTS finished" << "\n";
      /**************VECTOR cases finished******************/
      
      /*****************MAP test cases start************************/
      std::cout << "\n" << "MAP TESTS start" << "\n";

    }

    {
       std::cout << "\n" << "MAP default constructor test" << "\n";
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
      std::cout << "\n" << "Range constructor to make" << "\n";

    //   std::map<std::string, int> map3;
    //   map3["something"] = 69;
    //   map3["anything"] = 199;
    //   map3["that thing"] = 50;

    //   // here is range constructor used
    //   std::map<std::string, int> iter(map3.find("something"), map3.end());

    //   // std::cout << "map3 (key found) = "; 
    //   //       std::cout << '{';
    //   // std::map<std::string, int>::iterator itr2;  
    //   // for (itr2 = map3.find("something"); itr2 != map3.end(); ++itr2) 
    //   //   std::cout << itr2->first << ':' << itr2->second << ' ';      
    //   // std::cout << "}\n";



    //  ft::map<std::string, int> map4;
    //   map4["something"] = 69;
    //   map4["anything"] = 199;
    //   map4["that thing"] = 50;

    //   // here is range constructor used
    //   ft::map<std::string, int> iter2(map4.find("something"), map4.end());
    //   std::cout << "range constructor works" << "\n";
        
    //   // std::cout << "map3 (key found) = "; 
    //   //       std::cout << '{';
    //   // ft::map<std::string, int>::iterator it;  
    //   // for (it = map4.find("something"); it != map4.end(); ++it) 
    //   //   std::cout << it->first << ':' << it->second << ' ';      
    //   // std::cout << "}\n";


    }




    {
      //write methods
      
    }

   
  return 0;
  }