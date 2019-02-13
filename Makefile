# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 10:18:11 by nkirkby           #+#    #+#              #
#    Updated: 2019/02/13 13:15:34 by nkirkby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE_DIR = src
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = libft.h
CC = clang
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

.SUFFIXES: # remove the default suffix rules, because the GNU Make manual states:
# Suffix rules are the old-fashioned way of defining implicit rules for make.
# Suffix rules are obsolete because pattern rules are more general and clearer.
# They are supported in GNU make for compatibility with old makefiles.

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -r $@ $^

$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: clean all

