/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:39:36 by coskelet          #+#    #+#             */
/*   Updated: 2022/01/08 14:46:58 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_res(char **res, char *str, long num, char base);
static void	get_base_symb(long num, char *str, short base, char *symbols);
static void	get_base_symb_ul(unsigned long num, char *str, unsigned short base,
				char *symbols);

char	*itoa(long num, char base)
{
	size_t	size;
	short	neg;
	char	str[99];
	char	*res;

	neg = 1;
	if (num < 0)
		neg = -1;
	if (base == 'x')
		get_base_symb(num, str, 16, "0123456789abcdef");
	else if (base == 'X')
		get_base_symb(num, str, 16, "0123456789ABCDEF");
	else if (base == 'p')
		get_base_symb_ul(num, str, 16, "0123456789abcdef");
	else
		get_base_symb(num * neg, str, 10, "0123456789");
	size = strsize(str);
	if (num < 0 && base != 'p')
		size++;
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	fill_res(&res, str, num, base);
	return (res);
}	

static void	fill_res(char **res, char *str, long num, char base)
{
	size_t	i;
	size_t	j;

	j = strsize(str);
	i = 0;
	if (num < 0 && base != 'p')
	{
		*res[i] = '-';
		i++;
	}
	while (j > 0)
	{
		(*res)[i] = str[j - 1];
		i++;
		j--;
	}
	(*res)[i] = '\0';
	return ;
}

static void	get_base_symb(long num, char *str, short base, char *symbols)
{
	size_t	i;

	i = 0;
	while (num >= base)
	{
		str[i] = symbols[num % base];
		num = num / base;
		i++;
	}
	str[i] = symbols[num];
	str[i + 1] = '\0';
	return ;
}

static void	get_base_symb_ul(unsigned long num, char *str, unsigned short base,
			char *symbols)
{
	size_t	i;

	i = 0;
	while (num >= base)
	{
		str[i] = symbols[num % base];
		num = num / base;
		i++;
	}
	str[i] = symbols[num];
	str[i + 1] = '\0';
	return ;
}
