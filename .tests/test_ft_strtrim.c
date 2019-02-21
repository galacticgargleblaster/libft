#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ASSERT_STR_EQUAL(X, Y) (assert(strcmp(X, Y) == 0))

int main()
<%
	char str[] = " foo\tbar\nbaz ";
	ASSERT_STR_EQUAL(ft_strtrim(str), "foo\tbar\nbaz");
	
	char str2[] = "";
	ASSERT_STR_EQUAL(ft_strtrim(str2), "");

%>