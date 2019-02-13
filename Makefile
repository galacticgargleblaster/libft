# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 10:18:11 by nkirkby           #+#    #+#              #
#    Updated: 2018/10/02 04:42:19 by nkirkby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "libft.a"
SOURCE_DIR = src
SOURCES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c ft_itoa.c ft_strdup.c ft_atoi.c ft_split_whitespaces.c
OBJECT_FILES = $(addsuffix .o,$(basename $(SOURCES)))
INCLUDES = "libft.h"

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra -I$(INCLUDES) $(addprefix $(SOURCE_DIR)/,$(SOURCES)) && ar -r $(NAME) $(OBJECT_FILES)

clean:
	/bin/rm -f $(OBJECT_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: clean all
