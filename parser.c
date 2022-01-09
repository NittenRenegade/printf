/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:28:31 by coskelet          #+#    #+#             */
/*   Updated: 2022/01/07 14:30:57 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_spec(const char *str, size_t *i, t_list *s_set, size_t *n);
static void	parse_digits(const char *str, size_t *i, t_list *s_set, size_t *n);
static void	fill_width_prec(char *width, char *prec, t_list *s_set, size_t n);

t_list	*parse_format(const char *str, size_t s_cnt)
{
	size_t	i;
	size_t	n;
	t_list	*s_set;

	s_set = malloc(sizeof(t_list) * s_cnt);
	if (!s_set)
		return (NULL);
	spec_set_init(s_set, s_cnt);
	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i += 1;
		else if (str[i] == '%')
		{
			s_set[n].start = i;
			i++;
			check_spec(str, &i, s_set, &n);
		}
		i++;
	}
	return (s_set);
}

static void	check_spec(const char *str, size_t *i, t_list *s_set, size_t *n)
{
	while (str[*i])
	{
		if (str[*i] == '-')
			s_set[*n].left_adjust = 1;
		else if (str[*i] == '0')
			s_set[(*n)].zero = 1;
		else if (str[*i] == ' ')
			s_set[*n].space = 1;
		else if (str[*i] == '+')
			s_set[*n].sign = 1;
		else if (str[*i] == '#')
			s_set[*n].alter_form = 1;
		else if (str[*i] == '.' || ft_isnum(str[*i]))
			parse_digits(str, i, s_set, n);
		if (is_type(str[*i]))
		{
			s_set[*n].type = str[*i];
			s_set[*n].finish = *i;
			(*n)++;
			return ;
		}
		(*i)++;
	}
}

static void	parse_digits(const char *str, size_t *i, t_list *s_set, size_t *n)
{
	char	width[99];
	char	prec[99];
	char	*tmp;

	init_ch_arr(width, 99);
	init_ch_arr(prec, 99);
	tmp = width;
	while (ft_isnum(str[*i]) || str[*i] == '.')
	{
		if (str[*i] == '.')
		{
			s_set[*n].dot = 1;
			tmp = prec;
		}
		else
		{
			*tmp = str[*i];
			tmp++;
		}
		(*i)++;
	}
	fill_width_prec(width, prec, s_set, *n);
	return ;
}

static void	fill_width_prec(char *width, char *prec, t_list *s_set, size_t n)
{
	s_set[n].width = u_atoi(width);
	s_set[n].precision = u_atoi(prec);
	return ;
}
