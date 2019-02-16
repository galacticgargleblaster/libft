#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "unity.h"

/*
**	The real atoi returns zero for any string that doesn't start with a +, -, or [0,9]
*/

#define COMPARE(X) (assert(atoi(X) == ft_atoi(X)))

void test()
{
	COMPARE("--23");
	COMPARE("256a99999");
	COMPARE("-40000000000000");
	COMPARE("-2147483648");
	COMPARE("2147483647");
	COMPARE("0");
	COMPARE("+1");
	COMPARE("--0");
	COMPARE("toto3");
	COMPARE("42amis");
	COMPARE("-20toto12");
	COMPARE("   23");
	TEST_ASSERT(0);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test);
	return UNITY_END();
}