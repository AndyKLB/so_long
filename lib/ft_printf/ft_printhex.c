/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:51:53 by ankammer          #+#    #+#             */
/*   Updated: 2023/11/29 15:28:07 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long nbr, char arg)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_printhex(nbr / 16, arg);
		count += ft_printhex(nbr % 16, arg);
	}
	else if (arg == 'x')
	{
		if (nbr < 10)
			count += ft_printchar(nbr + '0');
		else
			count += ft_printchar(nbr - 10 + 'a');
	}
	else if (arg == 'X')
	{
		if (nbr < 10)
			count += ft_printchar(nbr + '0');
		else
			count += ft_printchar(nbr - 10 + 'A');
	}
	return (count);
}
