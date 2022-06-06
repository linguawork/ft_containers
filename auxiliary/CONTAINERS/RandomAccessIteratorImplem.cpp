/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIteratorImplem.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:29:50 by areggie           #+#    #+#             */
/*   Updated: 2022/05/05 12:33:33 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Самодельная реализация произвоильного итератора на основе
указателя
Код нужно доработать 
Написан в качестве псевдокода используя std

источник кода:
https://stackoverflow.com/questions/12092448/code-for-a-basic-random-access-iterator-based-on-pointers
*/


template<typename Type>
class Container<Type>::Iterator : public std::iterator<std::random_access_iterator_tag, Type>
{
private:
    Type* _ptr;

	
public:
    using difference_type = typename std::iterator<std::random_access_iterator_tag, Type>::difference_type;
    
    Iterator() : _ptr(nullptr)
	{
		 
	}
	
    Iterator(Type* rhs) : _ptr(rhs)
	{
		
	}
	
    Iterator(const Iterator &rhs) : _ptr(rhs._ptr) 
	{
		
	}
    /* inline Iterator& operator=(Type* rhs) {_ptr = rhs; return *this;} */
    /* inline Iterator& operator=(const Iterator &rhs) {_ptr = rhs._ptr; return *this;} */
    inline Iterator& operator+=(difference_type rhs) {_ptr += rhs; return *this;}
    inline Iterator& operator-=(difference_type rhs) {_ptr -= rhs; return *this;}
    inline Type& operator*() const {return *_ptr;}
    inline Type* operator->() const {return _ptr;}
    inline Type& operator[](difference_type rhs) const {return _ptr[rhs];}
    
    inline Iterator& operator++() {++_ptr; return *this;}
    inline Iterator& operator--() {--_ptr; return *this;}
    inline Iterator operator++(int) const {Iterator tmp(*this); ++_ptr; return tmp;}
    inline Iterator operator--(int) const {Iterator tmp(*this); --_ptr; return tmp;}
    /* inline Iterator operator+(const Iterator& rhs) {return Iterator(_ptr+rhs.ptr);} */
    inline difference_type operator-(const Iterator& rhs) const {return _ptr-rhs.ptr;}
    inline Iterator operator+(difference_type rhs) const {return Iterator(_ptr+rhs);}
    inline Iterator operator-(difference_type rhs) const {return Iterator(_ptr-rhs);}
    friend inline Iterator operator+(difference_type lhs, const Iterator& rhs) {return Iterator(lhs+rhs._ptr);}
    friend inline Iterator operator-(difference_type lhs, const Iterator& rhs) {return Iterator(lhs-rhs._ptr);}
    
    inline bool operator==(const Iterator& rhs) const {return _ptr == rhs._ptr;}
    inline bool operator!=(const Iterator& rhs) const {return _ptr != rhs._ptr;}
    inline bool operator>(const Iterator& rhs) const {return _ptr > rhs._ptr;}
    inline bool operator<(const Iterator& rhs) const {return _ptr < rhs._ptr;}
    inline bool operator>=(const Iterator& rhs) const {return _ptr >= rhs._ptr;}
    inline bool operator<=(const Iterator& rhs) const {return _ptr <= rhs._ptr;}

};