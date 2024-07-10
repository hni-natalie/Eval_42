# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraja-az <rraja-az@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 12:05:04 by rraja-az          #+#    #+#              #
#    Updated: 2024/07/09 11:42:39 by rraja-az         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = \
	ft_printchar.c \
	ft_printstr.c \
	ft_printptr.c \
	ft_printhex.c \
	ft_printint.c \
	ft_printuint.c \
	ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
