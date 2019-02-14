#!/usr/local/bin/python3

"""
The purpose of this script is to automate the easy-to-check rules for libft
"""

import os
import shutil
import subprocess
import pathlib

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

test_name = lambda function_name: os.path.join(TESTS_DIR, f'test_ft_{function_name}.c')

def assert_definition_exists(function_name):
	filename = os.path.join(SRC_DIR, f'ft_{function_name}.c')
	try:
		open(filename, 'x')
	except FileExistsError:
		pass
	assert os.path.basename(filename) in os.listdir(SRC_DIR), f"No {filename} found"

def assert_test_exists(function_name):
	filename = test_name(function_name)
	try:
		open(filename, 'x')
	except FileExistsError:
		pass
	assert os.path.basename(filename) in os.listdir(TESTS_DIR), f"No {filename} found"

def assert_test_passes(function_name):
	pathlib.Path(TEST_EXECUTABLE_DIR).mkdir(parents=True, exist_ok=True)

	test_source_file_path = test_name(function_name)
	test_source_file_basename = os.path.basename(test_source_file_path)
	test_executable_path = os.path.join(
		TEST_EXECUTABLE_DIR, 
		test_source_file_basename.split('.')[0]
	)
	compilation_args = [
		"clang", test_source_file_path, 
		"-lft", "-L", LIB_DIR, 
		"-o", test_executable_path
	]

	print(f"{test_source_file_basename:<20}", end='')
	try:
		subprocess.check_call(compilation_args, cwd=HERE)
		print(f" compiles ", end='')
	except:
		print(f"\nfailed to compile \t`{test_source_file_basename}`\twith command:\n{(' ').join(compilation_args)}")
		raise

	try:
		subprocess.check_call(test_executable_path, cwd=TEST_EXECUTABLE_DIR)
		print(f" runs")
	except:
		raise
	
if __name__ == '__main__':
	for function_name in FUNCTION_NAMES:
		assert_definition_exists(function_name)
		assert_test_exists(function_name)
		assert_test_passes(function_name)