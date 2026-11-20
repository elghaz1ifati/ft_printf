/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 17:27:59 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/20 17:21:44 by fatel-gh         ###   ########.fr       */
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
// ex = int function(int count, ...){} ...(ellipsis)
// variadic function lives in stdarg.h

// va_list -> complete object type(COT: size in memory is known to the compiler) 
// its used to manage variables in variadic functions

// MACRO: text replacement (find and replace)
// va_start va_arg va_copy va_end-> MACROS

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

// ex: count unknown number of arguments
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
//ex maximum
int	maximum(int count, ...)
{
	printf("======== MAX NUMBER ========\n");
	va_list	numbers;
	va_start(numbers, count);
	int max;
	int current;

	if (count <= 0)
	{
		va_end(numbers);
		return 0;
	}
	max = va_arg(numbers, int);
	int	c = 1;
	while (c < count)
	{
		current = va_arg(numbers, int);
		if (current > max)
			max = current;
		c++;
	}
	va_end(numbers);
	return(max);	
}

void	printfconversions(void)
{
	printf("======== PRINTF CONVERSIONS ========\n");

	int rets = printf("%s", NULL); // output = (null) | warning: '%s' directive argument is null [-Wformat-overflow=] | segfault with \n (GCC turns it into puts(NULL))
	printf("[%d]\n", rets); // [6]
	rets = printf("%s", ""); // output none
	printf("[%d]\n", rets); // [0]
	printf("\n");
	int retc = printf("%c", 0); // one NUL byte
	printf("[%d]\n", retc); // [1]
	printf("\n");
	int retd = printf("%d", INT_MIN); // output -2147483648
	printf("[%d]\n", retd); // [11]
	retd = printf("%d", 0); // output 0
	printf("[%d]\n", retd); // [1]
	printf("\n");
	int	reti = printf("%i", 42); // output 42
	printf("[%i]\n", reti); // [2]
	reti = printf("%i", -42); // output -42
	printf("[%i]\n", reti); // [3]
	printf("\n");
	int retu = printf("%u", -1); // output 4294967295
	printf("[%d]\n", retu); // [10]
	retu = printf("%u", 0); // output 0
	printf("[%d]\n", retu); // [1]
	printf("\n");
	int retx = printf("%x", -1); // output ffffffff
	printf("[%d]\n", retx); // [8]
	retx = printf("%x", 0); // output 0
	printf("[%d]\n", retx); // [1]
	printf("\n");
	int retX = printf("%X", 255); // output FF
	printf("[%d]\n", retX); // [2]
	retX = printf("%X", 0); // output 0
	printf("[%d]\n", retX); // [1]
	printf("\n");
	int retp = printf("%p", NULL); // output (nil)
	printf("[%d]\n", retp); // [5]
	retp = printf("%p", &retp); // 0x7ffc64505994
	printf("[%d]\n", retp); // [14]
	printf("\n");
	int	retprc = printf("%%", "hello%"); // output : % warning: too many arguments for format [-Wformat-extra-args]
	printf("[%d]\n", retprc); // [1]
	printf("\n");
	// retprc = printf("%d %"); // commented out: missing argument = undefined behavior, lone % at the end returns -1
	// printf("[%d]\n", retprc);
	int retm = printf("%d %s %c ", 7, "ab", 'f'); // output 7 ab f
	printf("[%d]\n", retm); // [7]
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
	printf("max = [%d]\n", maximum(5, 3, 9, -2, 7, 1));
	printfconversions();
	return 0;
}