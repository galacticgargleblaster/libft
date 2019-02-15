#!/usr/local/bin/python3

from core import *

def build_definintion(function_name):
	include, return_type, signature = parse_manpage(function_name)
	arguments = re.search(r'\((.*)\)', signature)

	template = \
f"""{poison}

#include "../libft.h"

{return_type}\tft_{function_name}{arguments}
{{

}}
"""
	return template

def build_test_definition(function_name):
	include, return_type, signature = parse_manpage(function_name)
	argument_types = get_argument_types(signature)
	template = f"""
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
{include}

void test({return_type} (function_under_test)({','.join(argument_types)}))
{{
	// do tests here
}}

int main()
{{
	test(&{function_name});
	test(&ft_{function_name});
}}
	"""
	return template

def assert_definition_exists(function_name):
	filename = get_source_name(function_name)
	try:
		open(filename, 'x')
	except FileExistsError:
		if os.stat(filename).st_size == 0:
			with open(filename, 'w') as fd:
				fd.write(build_definintion(function_name))

	assert os.path.basename(filename) in os.listdir(SRC_DIR), f"No {filename} found"

def assert_test_exists(function_name):
	filename = get_test_name(function_name)
	try:
		open(filename, 'x')
	except FileExistsError:
		if os.stat(filename).st_size == 0:
			with open(filename, 'w') as fd:
				fd.write(build_test_definition(function_name))

	assert os.path.basename(filename) in os.listdir(TESTS_DIR), f"No {filename} found"

def assert_test_passes(function_name):
	pathlib.Path(TEST_EXECUTABLE_DIR).mkdir(parents=True, exist_ok=True)

	test_source_file_path = get_test_name(function_name)
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
	for function_name in sorted(FUNCTION_NAMES):
		assert_definition_exists(function_name)
	
	for function_name in sorted(FUNCTION_NAMES):
		assert_test_exists(function_name)

	for function_name in sorted(FUNCTION_NAMES):
		assert_test_passes(function_name)