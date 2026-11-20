/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 17:27:59 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/20 09:54:56 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parameters vs Arguments
// Parameters = what the function declares.
//		parameters ↓
// int add(int a, int b) 
// {
//     return a + b;
// }
// Arguments = what you pass in when you call it.
//			arguments ↓
// int result = add(3, 5);
 
// variadic function is a function can take any number of parameters
// printf() is a variadic function
// ex = int function(int count, ...){}
// variadic function lives in stdarg.h

// va_list -> complete object type(COT: size in memory is known to the compiler) 
// its used to manage variables in variadic functions

// MACRO: text replacement (find and replace)
// va_start va_arg va_copy va_end-> MACROS

// ex: count unknown number of arguments
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int	sum(int count, ...)
{
	printf("======== INT SUM ========\n");
	va_list numbers;
	va_start(numbers, count);
	int num;
	int loop;
	int sum;
	
	loop = 0;
	sum = 0;
	while(loop++ < count)
	{
		num = va_arg(numbers, int);
		printf("current number: [%d]\n", num);
		sum += num;
	}
	va_end(numbers);
	printf("final sum: [%d]\n", sum);
}

// ex print string
char	*str(int count, ...)
{
	printf("======== PRINT STRING ========\n");
	va_list		charactres;
	va_start(charactres, count);
	char	*str;
	int loop;
	
	str = malloc(count + 1);
	if (!str)
		return(NULL);
	loop = 0;
	while (loop < count)
	{
		str[loop] = (char)(va_arg(charactres, int));
		printf("current char: %c\n", str[loop]);
		loop++;
	}
	str[loop] = '\0';
	printf("current char: [\\%d]\n", str[loop]);
	return (str);
}

// main
int	main(void)
{
	sum(10, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100);
	char	*p = str(4, 'f', 'a', 't', 'i');
	if (p)
	{
		printf("final str = %s\n", p);
		free(p);
	}
	return 0;
}