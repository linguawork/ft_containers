#ifndef STACK_HPP
#define STACK_HPP
// #include "../vector/Vector.hpp" // здесь подключен свой вектор
/*мне нужно подключить стандартный вектор и от него подключить стек*/
#include <vector> // ft::vector<T> я замаенил на std::vector<T>

namespace ft{

template<class T, class Container = std::vector<T> >
	class stack{

	public:
	typedef T value_type; // тип
	typedef Container container_type; // тпи кон
	typedef typename Container::size_type size_type; // 
	typedef value_type& reference;
	typedef const value_type& const_reference;

	protected:
		container_type _container;
	
	public:	
	
	explicit stack (const container_type& cont = container_type()) : _container(cont){}
	
	stack(const stack& other): _container(other._container) {}

	stack& operator=(const stack& other){
		_container = other._container;
		return (*this);
	}

	bool empty() const{
		return (_container.empty());
	}

	size_type size() const{
		return (_container.size());
	}

	value_type& top(){
		return (_container.back());
	}

	const value_type& top() const{
		return (_container.back());
	}

	void push (const value_type& val){
		_container.push_back(val);
	}

	void pop(){
		_container.pop_back();
	}



	template <class A, class Cont>
		  friend bool operator== (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
				return(lhs._container == rhs._container);
			 }
	template <class A, class Cont>
		  friend bool operator!= (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
				return(lhs._container != rhs._container);
			 }
	template <class A, class Cont>
		  friend bool operator<  (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
				return(lhs._container < rhs._container);
			 }
	template <class A, class Cont>
		  friend bool operator<= (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
				return(lhs._container <= rhs._container);
		  }
	template <class A, class Cont>
		  friend bool operator>  (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
				return(lhs._container > rhs._container);
		  }
	template <class A, class Cont>
		  friend bool operator>= (const stack<A,Cont>& lhs, const stack<A,Cont>& rhs){
				return(lhs._container >= rhs._container);
			}

};



}
#endif
