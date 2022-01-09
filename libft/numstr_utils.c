/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numstr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:30:29 by coskelet          #+#    #+#             */
/*   Updated: 2022/01/08 14:47:11 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int num, unsigned int power);

void	putnum(size_t num)
{
	char	*s_num;

	s_num = itoa(num, 'd');
	putstr(s_num);
	free(s_num);
}

char	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

unsigned int	u_atoi(char *c)
{
	unsigned int	num;
	short			pos;
	short			i;
	char			*tmp;

	tmp = c;
	while (*tmp == '0')
		tmp++;
	i = 0;
	while (*tmp)
	{
		tmp++;
		i++;
	}
	tmp--;
	pos = 0;
	num = 0;
	while (i > 0)
	{
		num += (*tmp - '0') * ft_pow(10, pos);
		pos++;
		tmp--;
		i--;
	}
	return (num);
}

void	print_filler(char filler, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		putch(filler);
		i++;
	}
}

static int	ft_pow(int num, unsigned int power)
{
	int				res;
	unsigned long	i;

	if (!power)
		return (1);
	res = 1;
	i = 0;
	while (i < power)
	{
		res *= num;
		i++;
	}
	return (res);
}
