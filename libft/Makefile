# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 11:44:18 by coskelet          #+#    #+#              #
#    Updated: 2022/01/08 14:42:14 by coskelet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

HEADER	= libft.h

SRCS	= str_utils.c	itoa.c	numstr_utils.c	

OBJS	= ${SRCS:.c=.o}

CC		= cc
RM		= rm -rf
AR		= ar -rcs
CFLAGS	= -Wall -Wextra -Werror

$(NAME):	${OBJS}
			${AR} ${NAME} $?

%o : %c ${HEADER}
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re 
