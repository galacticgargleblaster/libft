#!/usr/local/bin/python3


import os
import shutil
import subprocess
import pathlib
import sys
import re
from typing import List 

HERE = os.path.dirname(__file__)
LIB_DIR = os.path.abspath(os.path.join(HERE, '..'))
SRC_DIR = LIB_DIR
TESTS_DIR = os.path.abspath(os.path.join(HERE, '..', '.tests'))
TEST_EXECUTABLE_DIR = os.path.abspath(os.path.join(HERE, '..', '.test_output'))
HEADER_FILE = os.path.join(LIB_DIR, "libft.h")

FUNCTION_NAMES = \
['memset',
'bzero',
'memcpy',
'memccpy',
'memmove',
'memchr',
'memcmp',
'strlen',
'strdup',
'strcpy',
'strncpy',
'strcat',
'strncat',
'strlcat',
'strchr',
'strrchr',
'strstr',
'strnstr',
'strcmp',
'strncmp',
'atoi',
'isalpha',
'isdigit',
'isalnum',
'isascii',
'isprint',
'toupper',
'tolower']


# http://nicjam.es/why-the-42-header-is-poisonous/
poison = \
"""/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/13 14:56:17 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
"""

get_test_name = lambda function_name: os.path.join(TESTS_DIR, f'test_ft_{function_name}.c')
get_source_name = lambda function_name: os.path.join(SRC_DIR, f'ft_{function_name}.c')

BASE_TYPES = 'char|int|void|size_t'

def parse_manpage(function_name):
	"""
	regexes enough information out of a manpage to generate some mostly normal c code
	"""
	man = subprocess.Popen(('man', function_name), stdout=subprocess.PIPE)
	col = subprocess.Popen(('col', '-b'), stdin=man.stdout, stdout=subprocess.PIPE)  # removes ^H backspace sequences
	man.stdout.close()
	manpage = col.communicate()[0].decode('ascii')

	BFR = f'(#include\s<.*>)[\w\W]*((?:(?:const)\s|)(?:{BASE_TYPES}))\s*(\**)(?:\\n)\s*(?:{function_name})(\(.+?\))'
	include, base_type, pointers, argument_str = re.search(BFR, manpage).groups()

	arguments = []
	# another BFR is needed to lex the arguments
	another_BFR = f'((?:(?:const)\s|)(?:{BASE_TYPES}))\s*(\**)(?:restrict)*\s*([a-z\d]+)'
	for m in re.finditer(another_BFR, argument_str):
		arguments.append(m.groups())

	return include, base_type, pointers, arguments

def	parse_header(filepath: str):
	"""
	returns a list of function definitions, parsed from the prototypes in the header
	"""
	LINE_REGEX = f'({BASE_TYPES})\s*(\**)([a-z_]*)(\(.+?\))'

	functions = []
	with open(filepath, 'r') as header:
		for line in header:
			match = re.search(LINE_REGEX, line)
			if match:
				functions.append(match.groups())
	return functions