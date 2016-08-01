#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c;
	char sum = -1;
	/*Read characters one by one, and add it to sum*/
	while ((c = getchar()) != '\n')
	{
		putchar(c);
		sum += c;
	}
	printf("%d\n", sum);
	return EXIT_SUCCESS;
}