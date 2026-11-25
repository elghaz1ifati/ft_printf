/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:12:18 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/25 10:31:46 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ul(unsigned long n)
{
	const char	*base;
	int			count;
	int			value;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		value = ft_puthex_ul(n / 16);
		if (value == -1)
			return (-1);
		count += value;
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putptr(void *ptr)
{
	int	count;
	int	value;

	if (!ptr)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	value = ft_puthex_ul((uintptr_t)ptr);
	if (value == -1)
		return (-1);
	count = 2 + value;
	return (count);
}
