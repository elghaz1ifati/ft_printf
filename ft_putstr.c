/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatel-gh <fatel-gh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 19:53:07 by fatel-gh          #+#    #+#             */
/*   Updated: 2026/11/22 19:29:33 by fatel-gh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int		s;
	ssize_t	wr;

	s = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[s])
	{
		wr = write(1, &str[s], 1);
		if (wr == -1)
			return (-1);
		s++;
	}
	return (s);
}
