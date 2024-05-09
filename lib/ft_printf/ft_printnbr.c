/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:20:06 by ankammer          #+#    #+#             */
/*   Updated: 2023/11/29 15:13:05 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nb)
{
	int		count;
	long	nbr;

	nbr = nb;
	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		count += write(1, "-", 1);
	}
	if (nbr >= 10)
	{
		count += ft_printnbr(nbr / 10);
		count += ft_printnbr(nbr % 10);
	}
	else
	{
		count += ft_printchar(nbr + 48);
	}
	return (count);
}
