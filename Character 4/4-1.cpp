/*计算一个数的平方根*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float new_guess;
	float last_guess;
	float number;

	printf("Enter a number: ");
	scanf_s("%f", &number);
	if (number < 0)
	{
		printf("Cannot handle the negative number\n");
		return EXIT_SUCCESS;
	}

	new_guess = 1;
	do 
	{
		last_guess = new_guess;
		new_guess = (last_guess + number / last_guess) / 2;
		printf("%.15e\n", new_guess);
	} while (new_guess != last_guess);

	printf("Square root of %g is %g\n", number, new_guess);
	return EXIT_SUCCESS;
}