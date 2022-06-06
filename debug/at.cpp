

#include "ft_vector.hpp"



#define	_vector 			ft::vector
#include "./ft_containers-unit-test/sources/system/system_methods.ipp"
#include "./ft_containers-unit-test/sources/system/lib.hpp"


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
    
    std::cout << res1.size() << std::endl;
    std::cout << res2.size() << std::endl;;

        std::cout << "The vector elements are : ";
        for(int i=0; i < res1.size(); i++)
        std::cout << res1.at(i) << ' ';
       std::cout <<  std::endl;;

        std::cout << "The vector elements are : ";
        for(int i=0; i < res2.size(); i++)
        std::cout << res2.at(i) << ' ';
        std::cout <<  std::endl;;


    

 
    



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

// int _ratio = 10000;

template <typename T>
std::vector<int> at_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start1 = timer();
    v.push_back(vector.at(354 * _ratio));
    g_end1 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

template <typename T>
std::vector<int> at_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    g_start2 = timer();
    v.push_back(vector.at(354 * _ratio));
    g_end2 = timer();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    return v;
}

int main() {
     

    exit(run_vector_unit_test<int>("at()", at_test, at_test));

    int _ratio = 10000;

    // ft::vector<int> vector;

    // std::vector<int> at_test( vector) 
    // {
    //     std::vector<int> v;
    //     vector.assign(9900 * _ratio, 1);

    //     v.push_back(vector.at(354 * _ratio));
    //     v.push_back(vector.size());
    //     v.push_back(vector.capacity());
    //     return v;
    // }

}