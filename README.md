# ft_containers
The project is to implement basic container classes in CPP: vector, stack, map for the sake of understanding
how STL containers work.
If you can not make them perfect, make the minimum viable.



#Objectives

In this project, I have to implement a few container types of the C++ standard template library.
I have to take the structure of each standard container as reference. 
If a part of the Orthodox Canonical form (Coplean) is missing in it, I should not implement it.
As a reminder, you I am to comply with the C++98 standard, 
so any later feature of the containers MUST NOT be implemented,
but every C++98 feature (even deprecated ones) is expected.

I need to implement the following containers and turn in the necessary <container>.hpp files:
• vector
    You don’t have to do the vector<bool> specialization.
• map
• stack
    It will use the vector class as default underlying container. But it must still be compatible with other containers, 
    the STL ones included.
I also have to implement:
• iterators_traits
• reverse_iterator
• enable_if
  Yes, it is C++11 but you will be able to implement it in a C++98 manner. 
  This is asked so you can discover SFINAE.
• is_integral
• equal and/or lexicographical_compare
• std::pair
• std::make_pair

• The namespace must be ft.
• Each inner data structure used in the containers must be logical and justified (this
  means using a simple array for map is not ok).
• I cannot implement more public functions than the ones offered in the standard containers. 
  Everything else must be private or protected. 
  Each public function or variable must be justified.
• All the member functions, non-member functions and overloads of the standard containers are expected.
• I must follow the original naming. Take care of details.
• If the container has an iterator system, you must implement it. (My own iterators)
• You must use std::allocator. (which is good)
• For non-member overloads, the keyword friend is allowed. Each use of friend must be justified and will be checked during evaluation.
• Of course, for the implementation of map::value_compare, the keyword friend is allowed.
  
  
• I must also provide tests, at least a main.cpp, for your defense. I have to go further than the main given as example!
• I must produce two binaries that run the same tests: one with your containers only, and the other one with the STL containers.
• Compare outputs and performance / timing (your containers can be up to 20 times slower).
• Test your containers with: ft::<container>.
  
  
  
  
  
  
