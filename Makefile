# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fatel-gh <fatel-gh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/21 15:00:16 by fatel-gh          #+#    #+#              #
#    Updated: 2026/11/24 04:05:14 by fatel-gh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

COMPILER = cc
CFLAGS = -Wextra -Wall -Werror 
REMOVE = rm -f
ARCHIVE = ar 
ARFLAGS = rcs
SOURCES = ft_printf.c ft_putchar.c ft_putstr.c \
	ft_putnbr.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)
$(NAME) : $(OBJECTS)
	@$(ARCHIVE) $(ARFLAGS) $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	@$(COMPILER) $(CFLAGS) -c $< -o $@
clean:
	@$(REMOVE) $(OBJECTS)

fclean: clean
	@$(REMOVE) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
