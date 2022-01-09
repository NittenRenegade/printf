/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:53:53 by coskelet          #+#    #+#             */
/*   Updated: 2022/01/09 10:45:49 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_list {
	char			type;
	unsigned int	width;
	unsigned int	precision;
	short			dot;
	short			left_adjust;
	short			zero;
	short			sign;
	short			space;
	short			alter_form;
	size_t			start;
	size_t			finish;
}	t_list;
typedef struct s_nums{
	size_t		s_cnt;
	size_t		i;
	size_t		n;
	int			cnt;
}	t_nums;

int				ft_printf(const char *format, ...);
size_t			cnt_specs(const char *str);
char			is_type(char x);
void			spec_set_init(t_list *s_set, size_t n);
t_nums			nums_set_init(void);
t_list			*parse_format(const char *str, size_t s_cnt);
int				char_printer(unsigned char c, t_list set);
int				string_printer(char *str, t_list set);
int				num_printer(long num, t_list set);
#endif
