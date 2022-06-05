/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorByMesherin.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:48:12 by areggie           #+#    #+#             */
/*   Updated: 2022/04/11 18:58:53 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
the source of the code: https://www.youtube.com/watch?v=_wE7JYfcKN0&list=PL4_hYwCyhAvYTzwME4vQoDO8ZINM5trra&index=4


краткое описание вектора (код из лекции)
*/

#include <iostream>
#include <vector>

template<typename T>
class Vector
{
private:
	T* arr;
	size_t sz;
	size_t cap;
	
public:

	// void resize(size_t n, const T& value = T())
	// {
	// 	for (size_t i = sz; i < n; ++i)
	// 	{
	// 		arr[i] = value;
	// 	}
	// 	if (n < sz)
	// 		sz = n;
	// }
		
	void reserve (size_t n)
	{
		if (n <= cap)
			return;
		newarr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)])// это получше чем стр
		// reinterpret_cast см. 211019-7ReinterpretCast.cpp  преобразование в другой тип
		
		  
		// newarr = reinterpret_cast<T*>(new char[n * sizeof(T)])// это получше чем строка ниже
		// T* newarr = new T[n];// конструктора по умолчанию может не быть и не хорошо создавать объекты с количеством объектов
		for (size_t i = 0; i < sz; ++i)
			// newarr[i] = arr[i]; // здесь будет undefined behavior так как не будут созданы объекты 
			// new arr, поэтому используется placement_new(28:09)
			new(newarr + i) T (arr[i]); // placement new https://www.geeksforgeeks.org/placement-new-operator-cpp/
			// using placement new, object construction can be done at known address
			// по адресу newarr +i  кладем объект типа Т  параметра (arr[i])
		
		// здесь  лучше явно вызвать деструктор	
		for (size_t i = 0; i < sz; ++i)
		{
			(arr + i)->~T(); // arr + i или i+arr = arr[i] и дальше идет разыменование объекта Т
		}
		//delete[] arr; // тоже плохая строчка потому что вызываются деструкторы по месту где не были созданиы объекты
		delete[] reinterpret_cast<int8_t*>(arr); // переводим все в биты и зачищаем (int8_t приводит к числам 
		//и поэтому диструкторы вызывать не нужно нужно просто почистить)
		
		
		arr = newarr;
		cap = n;
	}

	void resize(size_t n, const T& value = T())
	{
		if (n > cap)
			reserve(n);
		for (size_t i = sz; i < n; ++i)
		{
			arr[i] = value;
		}
		if (n < sz)
			sz = n;
	}
	
	void push_back (const T& value)
	{
		// if (cap > sz)
		// {
		// 	arr[sz] = value;
		// 	++sz;
		// }
		if (cap == sz)
			reserve (2 * sz);
		arr[sz] = value;
		++sz;
	}

	void pop_back()
	{
		--sz;
	}


	
};

int main()
{
	std::vector<int> v;
	
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		std::cout <<"Vector size is " <<v.size() << ' ' << "Vector capacity is "<< v.capacity() << '\n';
	}
}