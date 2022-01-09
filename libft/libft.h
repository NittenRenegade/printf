/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:44:31 by coskelet          #+#    #+#             */
/*   Updated: 2022/01/08 14:46:11 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char			*itoa(long num, char base);
int				putch(char c);
void			putstr(char *str);
void			putnstr(char *str, size_t n);
size_t			strsize(char *s);
void			init_ch_arr(char *arr, size_t n);
void			putnum(size_t num);
char			ft_isnum(char c);
unsigned int	u_atoi(char *c);
void			print_filler(char filler, size_t count);
#endif
