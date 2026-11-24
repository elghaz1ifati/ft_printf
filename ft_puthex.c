/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 04:21:58 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/24 04:31:20 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, const char *base)
{
	unsigned int	div;
	unsigned int	len;
	int				count;
	int				value;

	len = 0;
	while (base[len])
		len++;
	div = 1;
	while (n / div >= len)
		div = div * len;
	count = 0;
	while (div < 0)
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
