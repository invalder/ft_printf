# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnakarac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 12:22:49 by nnakarac          #+#    #+#              #
#    Updated: 2022/03/28 23:26:43 by nnakarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_util_format1.c \
			ft_util_format2.c \
			ft_util_format3.c \
			ft_util_format4.c \
			ft_util_print_c.c \
			ft_util_print_d.c \
			ft_util_print_p.c \
			ft_util_print_u.c \
			ft_util_print_s.c \
			ft_util_print_x.c \
			ft_util_char.c \
			ft_util_str1.c \
			ft_util_str2.c \
			ft_util_putnbr1.c \
			ft_util_putnbr2.c \
			ft_util_mem.c \
			ft_util_append.c \

OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a

NAME_B	=	libftprintf_bonus.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I .

all:	$(NAME)

%o: %c
	@$(CC) $(CFLAGS) -c $< -o $@  $(CPPFLAGS)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f *~
	rm -f ft_printf_test
	rm -f a.out

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME_B)

re:	fclean all

test: re
	$(CC) $(CFLAGS) main.c libftprintf.a -o ft_printf_test
	./ft_printf_test

test_ns: re
	$(CC) main.c libftprintf.a -o ft_printf_test
	./ft_printf_test

.PHONY:	all clean fclean re
