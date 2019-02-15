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
SRC_DIR = os.path.abspath(os.path.join(HERE, '..', 'src'))
TESTS_DIR = os.path.abspath(os.path.join(HERE, '..', '.tests'))
TEST_EXECUTABLE_DIR = os.path.abspath(os.path.join(HERE, '..', 'test_output'))

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
	fff need to handle restrict keyword aswell
	"""
	man = subprocess.Popen(('man', function_name), stdout=subprocess.PIPE)
	col = subprocess.Popen(('col', '-b'), stdin=man.stdout, stdout=subprocess.PIPE)  # removes ^H backspace sequences
	man.stdout.close()
	manpage = col.communicate()[0]

	includes = re.search(b'(#include\s<.*>)', manpage)

	
	import ipdb; ipdb.set_trace()
	# capture groups are ['base type', 'string of **', '(full list, of arguments)']
	BFR = f'((?:(?:const)\s|)(?:{BASE_TYPES}))\s(\**)(?:\\n)\s*(?:{function_name})(\(.+?\))'.encode()
	base_type, pointers, argument_str = re.search(BFR, manpage).groups()

	arguments = []
	another_BFR = f'((?:(?:const)\s|)(?:{BASE_TYPES}))\s*(\**)\s([a-z]+)'.encode()
	for m in re.finditer(another_BFR, argument_str):
		arguments.append([g.decode('ascii') for g in m.groups()])

	import ipdb; ipdb.set_trace()
	
	include, return_type, signature = (g.decode('ascii') for g in hmm.groups())
	return include, return_type, signature

def get_argument_types(arguments: str) -> List[str]:
	"""
	takes a string of the form:
	bzero(void *s, size_t n);

	and returns something of the form:
	['void *', 'size_t']
	"""
	argument_types = re.findall(r'[/( ]((?:unsigned |signed |)(?:int|char|void|size_t) +\**)[a-z]*[,\)]', arguments)
	return argument_types