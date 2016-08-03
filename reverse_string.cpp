#include <stdio.h>
#include <stdlib.h>

void reverse_string(char *string)
{
	char *last_ptr;
	
	for (last_ptr = string; *last_ptr != '\0'; last_ptr++)
	{
		;
	}
	
	last_ptr--;
	while (string < last_ptr)
	{
		char temp;
		temp = *string;
		*string++ = *last_ptr;
		*last_ptr-- = temp;
	}
}

int main(void)
{
	char *string ,*first_ptr;
	int ch;
	first_ptr = string = (char*)malloc(10 * sizeof(char));
	while ((ch = getchar()) != '\n')
	{
		*string++ = ch;
	}
	
	reverse_string(first_ptr);
	printf(string);
	return EXIT_SUCCESS;
}