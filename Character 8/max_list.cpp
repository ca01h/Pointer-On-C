#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int max_list(int first_arg, ...)
{
	int max = 0;
	va_list var_arg;

	if (first_arg >= 0)
	{
		int this_arg;
		max = first_arg;

		va_start(var_arg, first_arg);
		while ((this_arg = va_arg(var_arg, int)) >= 0)
		{
			if (this_arg > max)
			{
				max = this_arg;
			}
		}
		va_end(var_arg);
	}
	return max;
}

int main(void)
{
	int *value;
	int ch, number;
	int i = 0;

	printf("Please enter the number of you will put: ");
	scanf("%d",&number);
	getchar();

	value = (int*)malloc(number * sizeof(int));
	while ((scanf("%d", &ch)) == 1)
	{
		value[i++] = ch;
	}

	int max = max_list(value[0], value[1], value[2], value[3]);
	printf("%d", max);
	
	return EXIT_SUCCESS;
}
