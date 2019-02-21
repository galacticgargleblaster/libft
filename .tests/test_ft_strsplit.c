#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ASSERT_STR_EQUAL(X, Y) (assert(strcmp(X, Y) == 0))

int main()
<%
	char str[] = "**foo****bar*baz*";
	char **split = ft_strsplit(str, '*');
	ASSERT_STR_EQUAL(split[0], "foo");
	ASSERT_STR_EQUAL(split[1], "bar");
	ASSERT_STR_EQUAL(split[2], "baz");
%>