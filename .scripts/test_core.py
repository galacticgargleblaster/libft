#!/usr/local/bin/python3


from core import *

def test_parsing_manpage():
	i, b, p, a = parse_manpage('atoi')
	assert i == '#include <stdlib.h>'
	assert b == 'int'
	assert p == ''
	assert a == [('const char', '*', 'str')]


if __name__ == '__main__':
	test_parsing_manpage()