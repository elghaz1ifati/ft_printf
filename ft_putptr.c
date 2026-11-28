/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:12:18 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/28 19:40:36 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	value;

	if (!ptr)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	value = ft_puthex((uintptr_t)ptr, "0123456789abcdef");
	if (value == -1)
		return (-1);
	retur(value + 2);
}
