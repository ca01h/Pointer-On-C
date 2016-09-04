#include <stdio.h>
#include <stdlib.h>

char *match(char *str, char *want)
{
	while (*want++ != '\0')
	{
		if (*str++ != *want++)
		{
			return NULL;
		}
	}
	return str;
}

int delsubstr(char *str, const char *substr)
{
	char *next;
	while (*str != '\0')
	{
		next = match(str,substr);
		if (next != NULL)
		{
			break;
		}
		str++;
	}
	
	if (*str == '\0')
	{
		return FALSE;
	}
	
	while(*str++ = *substr++)
		;
	return TRUE;
}

int main(void)
{
	char *str = "ABCDEFG";
	const char *substr = "CDE";
	if (delsubstr(str, substr) == TRUE)
	{
		printf("%s", str);
	} 
	else
	{
		printf("FAILED\n");
	}
	return EXIT_SUCCESS;
}