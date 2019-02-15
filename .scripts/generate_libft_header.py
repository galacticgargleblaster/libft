#!/usr/local/bin/python3

from core import *

N_TABS = 2

def get_formatted_signature(function_name):
	include, return_type, signature = parse_manpage(function_name)
	tabs = '\t' * N_TABS
	return f"{return_type}{tabs}ft_{signature};"

if __name__ == '__main__':
	function_signatures = '\n'.join([get_formatted_signature(fn) for fn in sorted(FUNCTION_NAMES)])
	template = \
f"""{poison}

/*
* This file is autogenerated.
* Edit the template in .scripts/generate_libft_header.py
*/

#include <string.h>

#ifndef LIBFT_H
# define LIBFT_H

#define IS_LOWERCASE(X) ((X >= 'a') && (X <= 'z'))
#define IS_UPPERCASE(X) ((X >= 'A') && (X <= 'Z'))
#define IS_ALPHA(X) (IS_LOWERCASE(X) || IS_UPPERCASE(X))
#define IS_DIGIT(X) ((X >= '0') && (X <= '9'))

int		ft_atoi_ptr(char *str, long *out);
void	ft_putchar(char c);
void	ft_puts(char *str);
{function_signatures}

#endif
"""
	with open(os.path.join(LIB_DIR, 'libft.h'), 'w') as fd:
		fd.write(template)