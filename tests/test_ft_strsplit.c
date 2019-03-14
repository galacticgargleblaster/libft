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
	assert(split[3] == NULL); 


	char str2[]  = "alone";
	char **split2 = ft_strsplit(str2, '~');
	ASSERT_STR_EQUAL(split2[0], "alone");
	assert(split2[1] == NULL); 
	
	char str3[] = " forever";
	char **split3  = ft_strsplit(str3, ' ');
	ASSERT_STR_EQUAL(split3[0], "forever");
%>