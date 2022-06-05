

#include<iostream>
#include<set>
 #include<iterator>

/*

	source:
		https://www.mygreatlearning.com/blog/set-in-cpp/#:~:text=Set%20is%20a%20C%2B%2B%20STL,implemented%20using%20Binary%20search%20trees.
		
		Код с сайта, на котором даются примеры как работает SET


		Set is a  C++ STL container used to store the unique elements, and all the elements are stored in a sorted manner.
		
		Once the value is stored in the set, it cannot be modified within the set; 
		instead, we can remove this value and can add the modified value of the element.
		
		Sets are implemented using Binary search trees or RED BLACK TREE




		Difference between set, multiset, and unordered_set:

			A Set stores the elements in sorted order.
			Set stores unique elements.
			Elements can only be inserted and deleted but cannot be modified within the set.
			Sets are implemented using a binary search tree.
			Sets are traversed using iterators.
		

*/


using namespace std;

int main()
{
	{
		cout << "set.insert() elements into the set: " << endl;
		
		set < int > s;
	
		// inserting elements in random order .
		s.insert( 60 ) ;
		s.insert( 10 ) ;
		s.insert( 20 ) ;
		s.insert( 20 ) ; // set will delete the repeated elements
		s.insert( 40 ) ;
		s.insert( 50 ) ;
		
		// printing set s
		//initialising the iterator, iterating to the beginning of the set.
	
		set<int >::iterator it ;
		cout << "The element of set s are : " << endl;
		for (it = s.begin() ; it != s.end() ; it++ ) 
		{
			cout << *it<<" ";
		}
		cout << endl;
		
		cout << "The size of set : \n " << s.size() << endl;
	}


	{
		cout << "\n set.erase(), find(), lower_bound(), upper_bound() elements into the set: \n" << endl;
		set< int >s ;
		s.insert( 34 ) ;
		s.insert( 14 ) ;
		s.insert( 13 ) ;
		s.insert( 56 ) ;
		s.insert( 5 ) ; 
		s.insert( 23 ) ;
		s.insert( 10 ) ;
		s.insert( 4 ) ;
		set<int> :: iterator it;
		cout << " the elements of set are : \n";
		for(it = s.begin() ; it != s.end() ; it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		
		// Removing all elements up to 10
		cout<< " elements of set s after deleting elements upto 10  \n " ;
		s.erase(s.begin() , s.find(10) ) ;
		for ( it = s.begin() ; it!=s.end() ; it++)
			cout<< *it << " ";
			
		// Performing Lower bound and upper bound in set
		cout << " \n lower bound of 13 \n " ;
		cout << *s.lower_bound(13)<< endl;
		cout << " lower bound of 34\n " ;
		cout << *s.lower_bound( 34 ) << endl;
		cout << " upper bound of 13 \n " ;
		cout << *s.upper_bound( 13 ) << endl;
		cout << " upper bound of 34  \n" ;
		cout << *s.upper_bound( 34 ) << endl ;
	}



	{
		cout << "\n set.erase(), find() in the set: \n" << endl;
	
		set< int > s ;
		// adding random elements to set using the insert().
		s.insert( 13 ) ;
		s.insert( 11 ) ;
		s.insert( 44 ) ;
		s.insert( 1 ) ;
		s.insert(10 ) ;
		s.insert( 25 ) ; 
		s.insert( 11 ) ;   // 11 will only be added only once .  
		
		// declaring iterators to traverse through the set .
		set <int>::iterator ptr1 , ptr2 , ptr3;
		cout << " set elements are initially  : \n" ;
		for ( ptr1 = s.begin() ; ptr1 != s.end() ; ptr1++)
		{
			cout << *ptr1 << " " ;
		}
		cout << endl ;
		
		// making another set  s2 , storing elements in decreasing order.
		// copying the elements of s into s2 .
		set < int , greater <int> > s2 ( s.begin()  , s.end() ); 
		set < int , greater <int > > ::iterator itr ; 
		
		
		ptr2 = s.find( 11 ) ;
		ptr3 = s.find( 25) ;

		// elements from 11 to 25 are erased from the set using the erase() . 
		s.erase ( ptr2 , ptr3);
		cout << "  set s elements after erase  : \n " ;
		for ( ptr1 = s.begin() ; ptr1 != s.end() ; ptr1++)
		{
			cout << *ptr1 << " ";
		}
		cout << endl ;
		cout << " elements of set s2 are : \n" ;
		for ( itr = s2.begin() ; itr != s2.end()  ; itr++)
		{
			cout << *itr << " ";
		}    

	}



	
	
	return 0;
}

