/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 04:21:58 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/25 14:30:33 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, const char *base)
{
	unsigned long	div;
	unsigned long	len;
	int				count;
	int				value;

	len = 0;
	while (base[len])
		len++;
	div = 1;
	while (n / div >= len)
		div = div * len;
	count = 0;
	while (div > 0)
	{
		value = ft_putchar(base[n / div]);
		if (value == -1)
			return (-1);
		count++;
		n = n % div;
		div = div / len;
	}
	return (count);
}
