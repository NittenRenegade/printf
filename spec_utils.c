/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:57:21 by coskelet          #+#    #+#             */
/*   Updated: 2022/01/07 14:43:53 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	cnt_specs(const char *str)
{
	size_t	n;
	size_t	i;
	short	is_spec;

	n = 0;
	i = 0;
	is_spec = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		else if (str[i] == '%')
		{
			is_spec = 1;
			n++;
		}
		if (is_type(str[i]))
			is_spec = 0;
		i++;
	}
	return (n);
}

char	is_type(char x)
{
	if (x == 'c' || x == 's' || x == 'p' || x == 'd' || x == 'i' || x == 'u'
		|| x == 'x' || x == 'X')
		return (x);
	else
		return (0);
}

void	spec_set_init(t_list *s_set, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s_set[i].type = 0;
		s_set[i].width = 0;
		s_set[i].precision = 0;
		s_set[i].dot = 0;
		s_set[i].left_adjust = 0;
		s_set[i].zero = 0;
		s_set[i].sign = 0;
		s_set[i].space = 0;
		s_set[i].alter_form = 0;
		s_set[i].start = 0;
		s_set[i].finish = 0;
		i++;
	}
}

t_nums	nums_set_init(void)
{
	t_nums	nums;

	nums.s_cnt = 0;
	nums.i = 0;
	nums.n = 0;
	nums.cnt = 0;
	return (nums);
}
