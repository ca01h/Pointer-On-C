#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_white(char ch)
{
	return ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\n' || ch == '\r';
}

char *deblank(char *string)
{
	int len = strlen(string);

	char *src, *dst;
	int ch, count = 0;
	
	dst = (char *)malloc(len * sizeof(char));
	if (dst == NULL)
	{
		printf("malloc fail!\n");
		exit(1);
	}
	src = string;

	while ((ch= *src++) != '\0')
	{
		if (is_white(ch))
		{
			if (src == string || !is_white(dst[count - 1]))
			{
				dst[count++] = ' ';
			}
		} 
		else
		{
			dst[count++] = ch;
		}
	}
	dst[count] = '\0';
	return dst;
}

int  main(void)
{
	char *string = "cao		yi  huai";
	char *dst = deblank(string);
	printf(dst);
}