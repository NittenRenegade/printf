/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:05:52 by coskelet          #+#    #+#             */
/*   Updated: 2022/01/08 12:31:00 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_printer(unsigned char c, t_list set)
{
	char	filler;

	if (set.left_adjust)
		putch(c);
	if (set.width < 1)
		set.width = 1;
	filler = ' ';
	if (set.zero && set.left_adjust == 0)
		filler = '0';
	if (set.width > 1)
		print_filler(filler, set.width - 1);
	if (set.left_adjust == 0)
		putch(c);
	return (set.width);
}

int	string_printer(char *str, t_list set)
{
	char	filler;
	size_t	size;

	if (str == NULL)
		str = "(null)";
	size = strsize(str);
	if (set.dot && size > set.precision)
		size = set.precision;
	if (set.width < size)
		set.width = size;
	if (set.left_adjust)
		putnstr(str, size);
	if (set.dot && set.precision == 0)
		return (0);
	filler = ' ';
	if (set.zero && set.left_adjust == 0)
		filler = '0';
	print_filler(filler, set.width - size);
	if (set.left_adjust == 0)
		putnstr(str, size);
	return (size + (set.width - size));
}
