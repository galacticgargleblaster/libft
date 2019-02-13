#!/usr/local/bin/python3

import os
import shutil

HERE = os.path.dirname(__file__)
SRC_DIR = os.path.abspath(os.path.join(HERE, '..', 'src'))

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

for function_name in FUNCTION_NAMES:
	filename = os.path.join(SRC_DIR, f'ft_{function_name}.c')
	try:
		open(filename, 'x')
	except FileExistsError:
		pass
	assert os.path.basename(filename) in os.listdir(SRC_DIR), f"No {filename} found"