/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrdiff_t.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:48:22 by areggie           #+#    #+#             */
/*   Updated: 2022/04/11 15:48:23 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/*
источник
https://en.cppreference.com/w/c/types/ptrdiff_t#:~:text=ptrdiff_t%20is%20the%20signed%20integer,is%20not%20less%20than%2017.

ptrdiff_t is the signed integer type of the result of subtracting two pointers.


*/

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
 
int main(void)
{
    const size_t N = 100;
    int numbers[N];
 
    printf("PTRDIFF_MAX = %lld\n", PTRDIFF_MAX); // compiler needed lld in place of ld
    int *p1=&numbers[18], *p2=&numbers[23];
    
    printf("The size of ptrdiff_t = %lu\n", sizeof(ptrdiff_t));//8
    printf("The size of size_t = %lu\n", sizeof(size_t));//8
    printf("The size of int = %lu\n", sizeof(int)); //4
    ptrdiff_t diff = p2-p1;
    printf("p2-p1 = %td\n", diff);

 
    return 0;
}