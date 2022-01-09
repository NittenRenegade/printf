/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:33:54 by coskelet          #+#    #+#             */
/*   Updated: 2022/01/08 14:15:34 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_num_sign(long *num, char **sign, t_list set);
static void		get_num_str(long num, char **num_str, t_list set);
static int		print_left_num(char *num_str, char *sign, char filler,
					t_list set);
static int		print_right_num(char *num_str, char *sign, char filler,
					t_list set);

int	num_printer(long num, t_list set)
{
	char	*sign;
	char	filler;
	char	*num_str;
	int		cnt;

	sign = "";
	get_num_sign(&num, &sign, set);
	filler = ' ';
	if (set.zero && set.left_adjust == 0
		&& !(set.dot && (set.type == 'd' || set.type == 'i' || set.type == 'u'
				|| set.type == 'x' || set.type == 'X'))
		&& !(num == 0 && set.dot && set.precision == 0))
		filler = '0';
	get_num_str(num, &num_str, set);
	if (num_str == NULL)
		return (0);
	if (set.left_adjust)
		cnt = print_left_num(num_str, sign, filler, set);
	else
		cnt = print_right_num(num_str, sign, filler, set);
	free(num_str);
	return (cnt);
}

static void	get_num_sign(long *num, char **sign, t_list set)
{
	if (set.type == 'i' || set.type == 'd')
	{
		if (set.space)
			*sign = " ";
		if (set.sign)
			*sign = "+";
		if (*num < 0)
		{
			*num = 0 - *num;
			*sign = "-";
		}
	}
	if ((set.alter_form && set.type == 'x' && *num != 0) || set.type == 'p')
		*sign = "0x";
	if (set.alter_form && set.type == 'X' && *num != 0)
		*sign = "0X";
}

static void	get_num_str(long num, char **num_str, t_list set)
{
	*num_str = itoa(num, set.type);
	if (num == 0 && set.dot && set.precision == 0)
		**num_str = '\0';
}

static int	print_left_num(char *num_str, char *sign, char filler, t_list set)
{
	unsigned int	num_len;
	unsigned int	sign_len;

	num_len = strsize(num_str);
	sign_len = strsize(sign);
	putstr(sign);
	if (set.precision > num_len)
		set.precision = set.precision - num_len;
	else
		set.precision = 0;
	print_filler('0', set.precision);
	putstr(num_str);
	if (set.width > set.precision + num_len + sign_len)
	{
		print_filler(filler, set.width - (set.precision + num_len + sign_len));
		return (set.width);
	}
	return (set.precision + num_len + sign_len);
}

static int	print_right_num(char *num_str, char *sign, char filler, t_list set)
{
	unsigned int	num_len;
	unsigned int	sign_len;

	num_len = strsize(num_str);
	sign_len = strsize(sign);
	if (set.precision > num_len)
		set.precision = set.precision - num_len;
	else
		set.precision = 0;
	if (filler == '0')
		putstr(sign);
	if (set.width > set.precision + num_len + sign_len)
		print_filler(filler, set.width - (set.precision + num_len + sign_len));
	if (filler == ' ')
		putstr(sign);
	print_filler('0', set.precision);
	putstr(num_str);
	if (set.width > set.precision + num_len + sign_len)
		return (set.width);
	else
		return (set.precision + num_len + sign_len);
}
