/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 17:27:59 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/20 07:51:02 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parameters vs Arguments
// Parameters = what the function declares.
//		parameters ↓
// int add(int a, int b) {
//     return a + b;
// }
// Arguments = what you pass in when you call it.
//		arguments ↓
// int result = add(3, 5);
 
// variadic function is a function can take any number of parameters
// printf() is a variadic function
// ex = int function(int count, ...){}
// variadic function lives in stdarg.h

// va_list -> complete object type(COT: size in memory is known to the compiler) 
// its used to manage variables in variadic functions

// MACRO: text replacement (find and replace)
// va_start va_arg va_copy va_end-> MACROS

//ex: count unknown number of arguments
#include <stdio.h>
#include <stdarg.h>

int	sum(int count, ...)
{
	va_list numbers;
	va_start(numbers, count);
	int num;
	int loop = 0;
	int sum = 0;
	while(loop++ < count)
	{
		num = va_arg(numbers, int);
		printf("current number: [%d]\n", num);
		sum += num;
		printf("after sum: [%d]n", sum);
	}
	va_end(numbers);
	printf("final sum: [%d]\n", sum);
}
int	main(void)
{
	sum(10, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100);
	return 0;
}
