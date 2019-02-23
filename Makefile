# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 10:18:11 by nkirkby           #+#    #+#              #
#    Updated: 2019/02/22 12:23:02 by nkirkby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE_DIR = .
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
SOURCE_BASENAMES = $(notdir $(SOURCES))

INCLUDES = libft.h
CC = clang
CPP = clang -E
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

# ------------------------------------------------------------------------------#
# This method of directory creation is adapted from:
# https://gist.github.com/maxtruxa/4b3929e118914ccef057f8a05c614b0f

# intermediate directory for generated object files
OBJECT_DIR := .o

# object files, auto generated from source files
OBJECTS := $(patsubst %,$(OBJECT_DIR)/%.o,$(basename $(SOURCE_BASENAMES)))
# ------------------------------------------------------------------------------#


.SUFFIXES: # remove the default suffix rules, because the GNU Make manual states:
# Suffix rules are the old-fashioned way of defining implicit rules for make.
# Suffix rules are obsolete because pattern rules are more general and clearer.
# They are supported in GNU make for compatibility with old makefiles.
all: $(NAME)

$(NAME): $(OBJECTS)
	ar -r $@ $^

# https://stackoverflow.com/questions/38110010/pattern-rule-with-files-in-different-directories
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c $(INCLUDES)
	$(shell mkdir -p $(dir $(OBJECTS)) >/dev/null)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	/bin/rm -rf $(OBJECT_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: clean all

test:
	./scripts/build_and_run_tests.py
	
debug: CFLAGS += -g
debug: fclean all
