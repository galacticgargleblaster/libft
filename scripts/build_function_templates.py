#!/usr/local/bin/python3

from core import *

def build_function_definition(return_type, pointers, name, argument_str):
	
	template = \
f"""{poison}

#include "libft.h"

{return_type}\t{pointers}{name}{argument_str}
{{

}}
"""
	return template

def assert_definition_exists(return_type, pointers, name, argument_str):
	
	filename = os.path.join(SRC_DIR, f"{name}.c")

	def write_file():
		with open(filename, 'w') as fd:
				print(f"templating new file for function {name}")
				fd.write(build_function_definition(return_type, pointers, name, argument_str))

	try:
		des = open(filename, 'x')
		write_file()
		
	except FileExistsError:
		if os.stat(filename).st_size == 0:
			write_file()
			
KILLEM =[
'ft_memalloc',
'ft_memdel',
'ft_strnew',
'ft_strdel',
'ft_strclr',
'ft_striter',
'ft_striteri',
'ft_strmap',
'ft_strmapi',
'ft_strequ',
'ft_strnequ',
'ft_strsub',
'ft_strjoin',
'ft_strtrim',
'ft_strsplit',
'ft_putendl',
'ft_putnbr',
'ft_putchar_fd',
'ft_putstr_fd',
'ft_putendl_fd',
'ft_putnbr_fd',
'ft_atoi_ptr',
'ft_lstdelone',
'ft_lstdel',
'ft_lstadd',
'ft_lstiter']

if __name__ == '__main__':
	functions = parse_header(HEADER_FILE)
	for function in functions:
		assert_definition_exists(*function)

	import ipdb; ipdb.set_trace()

