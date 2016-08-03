#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
#define TRUE 1
#define FALSE 0

int main(void)
{
	char sieve[SIZE];
	char *sp;
	int number;

	for (sp = sieve; sp < &sieve[SIZE];)
	{
		*sp++ = TRUE;
	}

	for (number = 3; ;number += 2)
	{
		sp = sieve + (number - 3) / 2;

		if (sp >= &sieve[SIZE])
		{
			break;
		}
		
		while (sp += number, sp < &sieve[SIZE])
		{
			*sp = FALSE;
		}
	}

	printf("2\n");
	for (number = 3, sp = sieve; sp < &sieve[SIZE]; number += 2, sp++)
	{
		if (*sp)
		{
			printf("%d\n", number);
		}
	}

	return EXIT_SUCCESS;
}
