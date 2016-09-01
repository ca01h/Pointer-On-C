#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char const whitespace[] = " \n\t\r\f\v";

int main(void)
{
	char buffer[101];
	int count = 0;

	while (gets(buffer))
	{
		char *word;
		for (word = strtok(buffer, whitespace); word != NULL; word = strtok(NULL, whitespace))
		{
			if (strcmp(word, "the") == 0)
			{
				count++;
			}
		}
	}
	printf("%d\n", count);
	return EXIT_SUCCESS;
}