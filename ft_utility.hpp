#ifndef FT_UTILITY_HPP
#define FT_UTILITY_HPP


/*
about iterator_traits typedef in Russian STL of 98 standard by Stepanov:

шаблонный класс iterator_traits в качестве шаблона принимает итератор и наделяет его полями 
которые уже прописаны в основном итераторе 
Хотя эти поля повторяются важность класса iterator_traits в том что они обеспечивают 
частичную специализацию (partial specialization) КОТОРАЯ ОБРАБАТЫВАЕТ ВСЕ ТИПЫ УКАЗАТЕЛЕЙ
(некоторые компиляторы не поддерживают частичную специализацию)

Эта обработка определяет что все указатели это итератора произвольного доступа
(RAI) с типом расстояния ptrdiff_t

Ptrdiff - это целый тип который представляет разницу между любыми двумя объектами-указателями
указывающими на элементы одного массива ( typedef in C library <stddef.h>)
(книга С++ STL , стр 72)

*/


/*
iterator traits

*/

#include <iostream>

namespace ft {
	class random_access_iterator_tag {};

	class bidirectional_iterator_tag {};

	class forward_iterator_tag {};

	template<class iterator>
	struct iterator_traits {
		typedef iterator iterator_type;
		typedef typename iterator::difference_type difference_type;
		typedef typename iterator::value_type value_type;
		typedef typename iterator::pointer pointer;
		typedef typename iterator::reference reference;
		typedef typename iterator::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T *> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

	template<class T>
	struct iterator_traits<const T *> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};


	//template class Iterator
	template<class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T *, class Reference = T &>
	class iterator {
	public:
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	template<class T>
	class bidirectional_iterator: ft::iterator<ft::bidirectional_iterator_tag, T> {
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference reference;
	private:
		pointer _elem;
	};


}



/*
	https://www.cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator

	implementation of iterator for vector -  random_access_iterator
*/

namespace ft {
	template<typename T>
	class vector_iterator: public ft::iterator<ft::random_access_iterator_tag, T> 
	{
	public:
		typedef T value_t;
		typedef T* pointer;
		typedef T& reference;

		typedef T                                                     						 	iterator_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type            value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
	public:
		vector_iterator(): ptr(nullptr) {}

		vector_iterator(pointer other): ptr(other) {}

		vector_iterator(vector_iterator const &other): ptr(other.ptr) {}

		virtual ~vector_iterator() {}

		vector_iterator &operator=(const vector_iterator& other) {
			if (this == &other)
				return (*this);
			ptr = other.ptr;
			return (*this);
		}

		pointer base() const {
			return (ptr);
		}

		reference operator*(void) const {
			return (*ptr);
		}

		pointer operator->(void) {
			return &(operator*());
		}

		vector_iterator operator+(difference_type n) const {
			return (ptr + n);
		}

		vector_iterator operator-(difference_type n) const {
			return (ptr - n);
		}

		vector_iterator& operator++() {
			ptr++;
			return (*this);
		}

		vector_iterator operator++(int) {
			vector_iterator temp(*this);
			operator++();
			return (temp);
		}

		vector_iterator& operator--() {
			ptr--;
			return (*this);
		}

		vector_iterator operator--(int) {
			vector_iterator temp(*this);
			operator--();
			return (temp);
		}

		vector_iterator& operator+=(difference_type n) {
			ptr += n;
			return (*this);
		}

		vector_iterator& operator-=(difference_type n) {
			ptr -= n;
			return (*this);
		}

		reference operator[](difference_type n) {
			return (*(ptr + n));
		}
	private:
		pointer ptr;
	};

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator-(const ft::vector_iterator<T> lhs,
			  const ft::vector_iterator<T> rhs) {
		return (lhs.base() - rhs.base());
	}

	template<typename T>
	ft::vector_iterator<T> operator+(typename ft::vector_iterator<T>::difference_type n,
			typename ft::vector_iterator<T>& rai) {
		return (&(*rai) + n);
	}

	template<typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator-(const ft::vector_iterator<T_LEFT> lhs,
			  const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() - rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator==(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() == rhs.base());
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator==(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() == rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator!=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() != rhs.base());
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator!=(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator<(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() < rhs.base());
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator<=(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() <= rhs.base);
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator<=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() <= rhs.base);
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator<(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() < rhs.base);
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator>(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() > rhs.base());
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator>(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() > rhs.base());
	}

	template <typename T>
	typename ft::vector_iterator<T>::difference_type
	operator>=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <typename T_LEFT, typename T_RIGHT>
	typename ft::vector_iterator<T_LEFT>::difference_type
	operator>=(const ft::vector_iterator<T_LEFT> lhs, const ft::vector_iterator<T_RIGHT> rhs) {
		return (lhs.base() >= rhs.base());
	}


	/*
	is_integral
	*/

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

	/*
	block enable if

	*/

	template<class T>
	typename std::enable_if<std::is_object<T>::value, T*>::type  addressof(T& arg) {
		return reinterpret_cast<T*>(&const_cast<char&>(reinterpret_cast<const volatile char&>(arg)));
	}

	template<class T>
	typename std::enable_if<!std::is_object<T>::value, T*>::type addressof(T& arg) {
		return &arg;
	}



}



#endif








