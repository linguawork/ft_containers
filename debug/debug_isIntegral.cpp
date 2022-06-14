#include "ft_vector.hpp"
#define UTILITIES "../../../ft_utility.hpp"
#include "./ft_containers-unit-test/sources/system/system_methods.ipp"


// #include "./ft_containers-unit-test/sources/system/lib.hpp"
// #include "./ft_containers-unit-test/sources/system/system_methods.ipp"
// #include UTILITIES
// #include "ft_utility.hpp"

int run_bool_unit_test(std::string test_name, bool (func1)()) 
{
    int ret = 0;
    time_t t1;
    time_t t2;
    bool res;

	printElement(test_name);
	res = func1();
	if (res) {
	    printElement("OK");
	    ret = 0;
	}
	else {
	    printElement("FAILED");
	    ret = 1;
	}
	t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;
	(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);
	(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);
	cout << endl;
}


bool is_integral_test_() {
	std::vector<int> v;
	bool res = 1;
	g_start2 = timer(); g_end2 = timer(); g_start1 = timer(); g_end1 = timer();
	(_is_integral<float>() == std::is_integral<float>()) ? 0 : res = 0;
	(_is_integral<int>() == std::is_integral<int>()) ? 0 : res = 0;
	(_is_integral<bool>() == std::is_integral<bool>()) ? 0 : res = 0;
	(_is_integral<char>() == std::is_integral<char>()) ? 0 : res = 0;
	(_is_integral<signed char>() == std::is_integral<signed char>()) ? 0 : res = 0;
	(_is_integral<unsigned char>() == std::is_integral<unsigned char>()) ? 0 : res = 0;
	(_is_integral<wchar_t>() == std::is_integral<wchar_t>()) ? 0 : res = 0;
	(_is_integral<char16_t>() == std::is_integral<char16_t>()) ? 0 : res = 0;
	(_is_integral<short>() == std::is_integral<short>()) ? 0 : res = 0;
	(_is_integral<unsigned short>() == std::is_integral<unsigned short>()) ? 0 : res = 0;
	(_is_integral<unsigned int>() == std::is_integral<unsigned int>()) ? 0 : res = 0;
	(_is_integral<long>() == std::is_integral<long>()) ? 0 : res = 0;
	(_is_integral<unsigned long>() == std::is_integral<unsigned long>()) ? 0 : res = 0;
	(_is_integral<long long>() == std::is_integral<long long>()) ? 0 : res = 0;
	(_is_integral<unsigned long long>() == std::is_integral<unsigned long long>()) ? 0 : res = 0;
	return res;
}

int main() {
	exit(run_bool_unit_test("is_integral", is_integral_test_));
}