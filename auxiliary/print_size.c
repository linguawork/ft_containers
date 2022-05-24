/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:58:19 by areggie           #+#    #+#             */
/*   Updated: 2022/05/10 15:06:15 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include <stdio.h>

int main()
{
	/*
		https://www.quora.com/Why-do-some-C-programs-use-size_t-instead-of-int-What-are-the-advantages
		size_t implies the size of an object, and usually matches 
		the processor address size which is often 64 bits.
		int is a signed integer, and is usually only 32 bits on 64 bit systems which is 
		less than you need to store the size of some objects.
	*/
	
	printf("the size of ptrdiff_t in c is %lu bytes\n ", sizeof(ptrdiff_t)); // 8 bytes not %d, but long unsigned
	printf("the size of size_t in c is %lu bytes\n ", sizeof(size_t)); // 8bytes
	printf("the size of int in c is %lu bytes\n ", sizeof(int)); // 4 bytes
	
	return 0;
	
}