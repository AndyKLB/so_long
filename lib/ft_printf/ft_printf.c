/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:16:25 by ankammer          #+#    #+#             */
/*   Updated: 2023/12/07 12:11:02 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(char arg, va_list ap)
{
	int	count;

	count = 0;
	if (arg == 'c')
		count += ft_printchar(va_arg(ap, int));
	else if (arg == 's')
		count += ft_printstr(va_arg(ap, char *));
	else if (arg == 'd' || arg == 'i')
		count += ft_printnbr(va_arg(ap, long int));
	else if (arg == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (arg == 'x' || arg == 'X')
		count += ft_printhex(va_arg(ap, unsigned int), arg);
	else if (arg == 'p')
		count += ft_printptr(va_arg(ap, long int));
	else if (arg == '%')
		count += ft_printchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += check_arg(*(format + 1), ap);
			format++;
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (count);
}
