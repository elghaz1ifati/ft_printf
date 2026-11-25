/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:57:01 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/25 15:28:16 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this main.c file contains only exercices to practice variadic functions
// you will find the exercices pdf in this repository

#include "ft_printf.h"
#include <stdio.h>

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


int	main(void)
{
	int re = ft_printf("%d\n", sum(4, 1, 2, 3, 4));
	ft_printf("%d\n", re);
}