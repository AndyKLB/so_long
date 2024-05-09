/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:23 by ankammer          #+#    #+#             */
/*   Updated: 2023/11/29 14:18:07 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_print_unsigned(nbr / 10);
		count += ft_print_unsigned(nbr % 10);
	}
	else
	{
		count += ft_printchar(nbr + 48);
	}
	return (count);
}
