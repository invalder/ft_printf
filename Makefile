# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 12:22:49 by nnakarac          #+#    #+#              #
#    Updated: 2022/03/15 00:19:07 by nnakarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_util_char.c \
			ft_util_str.c \
			ft_util_putnbr.c \
			ft_format_chk.c \
			ft_util_mem.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I .

all:	$(NAME)

%o: %c
	@$(CC) $(CFLAGS) -c $< -o $@  $(CPPFLAGS)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

test:
	$(CC) $(CFLAGS) main.c libftprintf.a -o ft_printf_test
	./ft_printf_test

test_ns:
	$(CC) main.c libftprintf.a -o ft_printf_test
	./ft_printf_test

.PHONY:	all clean fclean re
