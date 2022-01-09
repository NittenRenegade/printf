/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:01:51 by coskelet          #+#    #+#             */
/*   Updated: 2022/01/09 10:59:16 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static short	proc_double_persents(size_t *i, const char *format);
static void		print_args(va_list *pvar, t_list s_set, t_nums *nums);

int	ft_printf(const char *format, ...)
{
	va_list	pvar;
	t_list	*s_set;
	t_nums	nums;

	nums = nums_set_init();
	nums.s_cnt = cnt_specs(format);
	s_set = parse_format(format, nums.s_cnt);
	va_start(pvar, format);
	while (format[nums.i])
	{
		if (proc_double_persents(&nums.i, format))
		{
			nums.cnt++;
			continue ;
		}
		else if (nums.n >= nums.s_cnt || nums.i < s_set[nums.n].start)
			nums.cnt += putch(format[nums.i]);
		else
			print_args(&pvar, s_set[nums.n], &nums);
		nums.i++;
	}
	va_end(pvar);
	free(s_set);
	return (nums.cnt);
}

static short	proc_double_persents(size_t *i, const char *format)
{
	if (format[*i] == '%' && format[(*i) + 1] == '%')
	{
		putch('%');
		(*i) += 2;
		return (1);
	}
	return (0);
}

static void	print_args(va_list *pvar, t_list s_set, t_nums *nums)
{
	int	cnt;

	cnt = 0;
	if (s_set.type == 'c')
		cnt = char_printer((unsigned char)va_arg(*pvar, int), s_set);
	if (s_set.type == 's')
		cnt = string_printer((char *)va_arg(*pvar, char *), s_set);
	if (s_set.type == 'd' || s_set.type == 'i')
		cnt = num_printer((int)va_arg(*pvar, int), s_set);
	if (s_set.type == 'x' || s_set.type == 'X' || s_set.type == 'u')
		cnt = num_printer((unsigned int)va_arg(*pvar, unsigned int), s_set);
	if (s_set.type == 'p')
		cnt = num_printer((unsigned long)va_arg(*pvar, unsigned long), s_set);
	nums->cnt += cnt;
	nums->i = s_set.finish;
	nums->n++;
	return ;
}
