/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:16:36 by ankammer          #+#    #+#             */
/*   Updated: 2023/11/29 15:10:18 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(char arg);
int	ft_printstr(char *str);
int	ft_printnbr(int nbr);
int	ft_print_unsigned(unsigned int nbr);
int	ft_printhex(unsigned long nbr, char arg);
int	ft_printptr(unsigned long ptr);

#endif