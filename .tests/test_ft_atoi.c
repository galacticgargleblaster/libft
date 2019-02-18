#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
**	The real atoi returns zero for any string that doesn't start with a +, -, or [0,9]
*/

#define COMPARE(X) (assert(atoi(X) == ft_atoi(X)))

int main()
<%
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
	COMPARE("\t\v\f\r\n \f-06050");
	COMPARE("\t\v\f\r\n \f- \f\t\n\r    06050");
	
	// Brush the teeth with inputs around __LONG_MAX__
	char buf[100];
	for (unsigned long long i = __LONG_MAX__ - 5; i < __LONG_MAX__ + 5ULL; i++)
	{
		sprintf(buf, "%llu", i);
		//printf("%d\t%d\t%s\n", ft_atoi(buf), atoi(buf), buf);
		COMPARE(buf);
	}
	for (unsigned long long i = __LONG_MAX__ - 5; i < __LONG_MAX__ + 5ULL; i++)
	{
		sprintf(buf, "-%llu", i);
		//printf("%d\t%d\t%s\n", ft_atoi(buf), atoi(buf), buf);
		COMPARE(buf);
	}
%>