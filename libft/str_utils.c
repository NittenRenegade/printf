/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:24:46 by coskelet          #+#    #+#             */
/*   Updated: 2022/01/08 14:47:21 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putch(char c)
{
	write(1, &c, 1);
	return (1);
}

void	putstr(char *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		putch(*str);
		str++;
	}
	return ;
}

void	putnstr(char *str, size_t n)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (*str && i < n)
	{
		putch(*str);
		str++;
		i++;
	}
	return ;
}

size_t	strsize(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void	init_ch_arr(char *arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		arr[i] = '\0';
		i++;
	}
}	
