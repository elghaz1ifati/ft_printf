/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 03:03:35 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/24 04:12:13 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	unsigned int	div;
	int				count;
	int				value;

	count = 0;
	div = 1;
	while (n / div >= 10)
		div = div * 10;
	while (div > 0)
	{
		value = ft_putchar((n / div) + '0');
		if (value == -1)
			return (-1);
		count++;
		n = n % div;
		div = div / 10;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				count;
	int				value;

	count = 0;
	nb = n;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		nb = -nb;
	}
	value = ft_putunbr(nb);
	if (value == -1)
		return (-1);
	return (count + value);
}
