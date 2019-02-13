#!/usr/local/bin/python3

import os
import shutil

HERE = os.path.dirname(__file__)
SRC_DIR = os.path.abspath(os.path.join(HERE, '..', 'src'))
TESTS_DIR = os.path.abspath(os.path.join(HERE, '..', '.tests'))

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

def assert_definition_exists(function_name):
	filename = os.path.join(SRC_DIR, f'ft_{function_name}.c')
	try:
		open(filename, 'x')
	except FileExistsError:
		pass
	assert os.path.basename(filename) in os.listdir(SRC_DIR), f"No {filename} found"

def assert_test_exists(function_name):
	filename = os.path.join(TESTS_DIR, f'test_ft_{function_name}.c')
	try:
		open(filename, 'x')
	except FileExistsError:
		pass
	assert os.path.basename(filename) in os.listdir(TESTS_DIR), f"No {filename} found"

def assert_test_passes(function_name):
	pass
	
if __name__ == '__main__':
	for function_name in FUNCTION_NAMES:
		assert_definition_exists(function_name)
		assert_test_exists(function_name)