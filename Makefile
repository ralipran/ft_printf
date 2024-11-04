# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralipran <ralipran@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 14:04:12 by ralipran          #+#    #+#              #
#    Updated: 2024/10/31 15:25:29 by ralipran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c ft_printf_fonx_supp.c

OBJS = ${SRCS:.c=.o}

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs

NAME		=	libftprintf.a

all:$(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all bonus clean fclean re
.SILENT:
