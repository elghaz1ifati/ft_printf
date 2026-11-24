/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:26:40 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/24 02:51:00 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_print_conversion(char specifier, va_list arguments)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(arguments, int)));
	if (specifier == 's')
		return (ft_putstr(va_arg(arguments, char *)));
	if (specifier == '%')
		return (ft_putchar('%'));
	return (-1);
}

int ft_printf(const char *format, ...)
{
	va_list arguments;
	int f;
	int count;
	int value;

	va_start(arguments, format);
	f = 0;
	count = 0;
	while (format[f])
	{
		if (format[f] == '%' && format[f + 1])
		{
			f++;
			value = ft_print_conversion(format[f], arguments);
		}
		else
			value = ft_putchar(format[f]);
		if (value == -1)
		{
			va_end(arguments);
			return (-1);
		}
		count += value;
		f++;
	}
	va_end(arguments);
	return (count);
}