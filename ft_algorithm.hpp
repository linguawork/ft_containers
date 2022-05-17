#include "ft_utility.hpp"


namespace ft {
	template<class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2) {
		for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2,
								 Compare comp) {
		for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1,
			   InputIterator2 first2) {
		for (; first1 != last1; ++first1, ++first2) {
			if (*first1 != *first2) {
				return false;
			}
		}
		return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1,
			   InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class T1, class T2>
	struct pair {
	public:
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;
	public:
		pair(): first(), second() {}
		template<class U, class V> pair (const pair<U,V>& pr)
				: first(pr.first), second(pr.second) {}
		pair (const first_type& a, const second_type& b)
				: first(a), second(b) {}
		pair& operator=(const pair& pr)  {
			if (this == &pr)
				return (*this);
			first = pr.first;
			second = pr.second;

			return (*this);
		}
	};

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	}

	template <class T1, class T2>
	bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){
		return !(lhs < rhs);
	}

	template<bool type_is_integral, typename T>
	struct is_integral_result {
		static const bool value = type_is_integral;
		typedef T type;
	};

	template <typename>
	struct is_integral_type: public is_integral_result<false, bool> {};

	template <>
	struct is_integral_type<char>: public is_integral_result<true, char> {};

	template <>
	struct is_integral_type<wchar_t>:
			public is_integral_result<true, wchar_t> {};

	template <>
	struct is_integral_type<signed char>:
			public is_integral_result<true, signed char> {};

	template <>
	struct is_integral_type<short int>:
			public is_integral_result<true, short int> {};

	template <>
	struct is_integral_type<int>:
			public is_integral_result<true, int> {};

	template <>
	struct is_integral_type<long int>:
			public is_integral_result<true, long int> {};

	template <>
	struct is_integral_type<long long int>:
			public is_integral_result<true, long long int> {};

	template <>
	struct is_integral_type<unsigned char>:
			public is_integral_result<true, unsigned char> {};

	template <>
	struct is_integral_type<unsigned short int>:
			public is_integral_result<true, unsigned short int> {};

	template <>
	struct is_integral_type<unsigned int>:
			public is_integral_result<true, unsigned int> {};

	template <>
	struct is_integral_type<unsigned long int>:
			public is_integral_result<true, unsigned long int> {};

	template <>
	struct is_integral_type<unsigned long long int>:
			public is_integral_result<true, unsigned long long int> {};

	template <class T>
	struct is_integral: public is_integral_type<T>{};

	template<bool Cond, class T = void> struct enable_if {};
	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template<class T>
	typename std::enable_if<std::is_object<T>::value, T*>::type  addressof(T& arg) {
		return reinterpret_cast<T*>(&const_cast<char&>(reinterpret_cast<const volatile char&>(arg)));
	}

	template<class T>
	typename std::enable_if<!std::is_object<T>::value, T*>::type addressof(T& arg) {
		return &arg;
	}

	template<class It>
	typename ft::iterator_traits<It>::difference_type
	distance(It first, It last) {
		typename ft::iterator_traits<It>::difference_type result = 0;
		while (first != last) {
			++first;
			++result;
		}
		return result;
	}
}