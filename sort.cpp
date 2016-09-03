#include <stdio.h>
#include <stdlib.h>

int compare_intergers(void const *a, void const *b)
{
	register int const *pa = a;
	register int const *pb = b;

	return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}

int main(void)
{
	int *array;
	int n_values;
	int i;

	printf("How many values are there? ");
	if (scanf("%d", &n_values) != 1 || n_values <= 0)
	{
		printf("Illegal number of values.\n");
		return EXIT_FAILURE;
	}

	//alloc the memory to store the values
	array = malloc(n_values * sizeof(int));
	if (array == NULL)
	{
		printf("Can't get memory for that many values.\n");
		return EXIT_FAILURE;
	}

	//read these values from console
	for (i = 0; i < n_values; i++)
	{
		printf("? ");
		if (scanf("%d",array + i) != 1)
		{
			printf("Error reading values #%d\n", i);
			free(array);
			exit(EXIT_FAILURE);
		}
	}

	//sort the array
	qsort(array, n_values, sizeof(int), compare_intergers);

	//display the array
	for (i = 0; i < n_values; i++)
	{
		printf("%d ",array[i]);
	}

	free(array);
	return EXIT_SUCCESS;
}