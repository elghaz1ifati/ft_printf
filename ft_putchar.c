/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 17:35:15 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/22 19:29:48 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	return (write(1, &ch, 1));
}
