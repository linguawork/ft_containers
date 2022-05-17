/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.21-school.ru >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:32:02 by areggie           #+#    #+#             */
/*   Updated: 2022/05/17 12:06:02 by areggie          ###   ########.fr       */
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

    first.assign (7,100);             // 7 ints with a value of 100


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
      
  return 0;
}