/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocatorRebindOther.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:37:08 by areggie           #+#    #+#             */
/*   Updated: 2022/06/13 14:42:30 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// allocator_rebind.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int>::allocator_type IntAlloc;
int main( )
{
   IntAlloc v1Iter;
   vector<int> v1;

   IntAlloc::rebind<char>::other::pointer pszC = IntAlloc::rebind<char>::other(v1.get_allocator()).allocate(1, (void *)0);

   int * pInt = v1Iter.allocate(10);
   
   std::cout << sizeof(pInt) << endl;
   
   return 0;
}