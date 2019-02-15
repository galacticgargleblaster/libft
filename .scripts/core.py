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

utter_bullshit = \
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

def parse_manpage(function_name):
	"""
	todo: grep for correct function.  Some manpages contain multiple functions (e.g. man strcpy)
	"""
	man = subprocess.Popen(('man', function_name), stdout=subprocess.PIPE)
	col = subprocess.Popen(('col', '-b'), stdin=man.stdout, stdout=subprocess.PIPE)
	man.stdout.close()
	manpage = col.communicate()[0]
	
	hmm = re.search(b'(#include.*)\s*(.*)\s*(.*);', manpage)
	
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