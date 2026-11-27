/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:57:01 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/27 01:52:55 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this main.c file contains only exercices to practice variadic functions
// you will find the exercices pdf in this repository

#include "ft_printf.h"
#include <stdio.h>

// LEVEL 1 : BASICS

// 1 Sum of integers
int	sum(int count, ...)
{
	int	total;
	va_list	numbers;

	total = 0;
	va_start(numbers, count);
	while (count > 0)
	{
		total += va_arg(numbers, int);
		count--;
	}
	va_end(numbers);
	return (total);	
}
// 2 Maximum
int	max_of(int count, ...)
{
	int	max;
	int	next;
	va_list	numbers;

	va_start(numbers, count);
	while(count > 0)
	{
		next = va_arg(numbers, int);
		if (max < next)
			max = next;
		count--;
	}
	va_end(numbers);
	return(max);
}
// 3 Average
double	average(int count, ...)
{
	va_list	numbers;
	double	sum;
	int	fst_count;

	if(count <= 0)
	{
		ft_printf("count number invalid !\n");
		return 0;
	}
	fst_count = (double)count;
	sum = 0.00;
	va_start(numbers, count);
	while(count > 0)
	{
		sum += va_arg(numbers, int);
		count--;
	}
	va_end(numbers);
	return (sum / fst_count);
}
// 4 Sentiel-terminated sum
int	sum_until_zero(int first, ...)
{
	va_list	numbers;
	int	total;
	int	value;

	total = 0;
	va_start(numbers, first);
	if (first == 0)
		return (0);
	total = first;
	value = va_arg(numbers, int);
	while(value != 0)
	{
		total += value;
		value = va_arg(numbers, int);
	}
	va_end(numbers);
	return (total);
}

int	main(void)
{
	int s = sum(4, 1, 2, 3, 4);
	ft_printf("SUM = %d\n", s);

	int m = max_of(3, 7, 42, 5);
	ft_printf("MAX = %d\n", m);

	double a = average(4, 10, 20, 30, 4);
	if (a == 0)
		return 0;
	printf("AVERAGE = %f\n", a);
	
	int suz = sum_until_zero(5, 3, 2, 0);
	ft_printf("SUM UNTIL ZERO = %d\n", suz);	
}