/*
acc to subj I need to implement reverse_iterator (making class)
random_access_iterator should not be implemented 
as subject does not require to implement random_access_iterator
random access iterator can be just replaced by pointer from std::Allocator
in ft::vector
which I am going to implement

but tests of the RAI on pointers from Allocators (one peer's realization)
showed that there were problems with method resize()

so I decided to switch back to RAI class

to pass the tester I made ft_reverse_iterator.hpp file without making
a different file for RAI class (it probably is nested for the sake of unit tester)
*/

