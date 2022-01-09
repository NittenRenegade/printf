# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 11:44:18 by coskelet          #+#    #+#              #
#    Updated: 2022/01/08 16:11:53 by coskelet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

HEADER	= ft_printf.h

SRCS	= ft_printf.c spec_utils.c  parser.c printers.c num_printers.c

LIBFT	= libft

.PHONY: all clean fclean re bonus make_proj

OBJS	= ${SRCS:.c=.o}

CC		= cc
RM		= rm -rf
AR		= ar -rcs
CFLAGS	= -Wall -Wextra -Werror

$(NAME):
			@make -C ${LIBFT}
			@make make_proj

make_proj:	${OBJS}
			@cp libft/libft.a ./${NAME}
			${AR} ${NAME} $? libft.a

%o : %c ${HEADER}
		${CC} ${CFLAGS} -c $< -o $@

bonus:	${NAME}

all:	${NAME}

MAIN	= test_main.c
test:	${MAIN}
		${CC} ${MAIN} -L. -lftprintf
		./a.out

clean:
		${RM} ${OBJS}
		@make clean -C ${LIBFT}

fclean:	clean
		${RM} ${NAME}
		@make fclean -C ${LIBFT}

re:		fclean all
