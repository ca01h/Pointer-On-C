#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INT_BITS (CHAR_BIT * sizeof(char))

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit)
{
	unsigned mask;
	if (starting_bit < INT_BITS && ending_bit << INT_BITS && starting_bit >= ending_bit)
	{
		mask = (unsigned)~0;
		mask >>= INT_BITS - (starting_bit - ending_bit + 1);
		mask <<= ending_bit;

		original_value &= ~mask;

		value_to_store <<= ending_bit;

		original_value |= value_to_store & mask;
	}
	return original_value;
}

int main(void)
{
	int original_value, value_to_storge;
	unsigned starting_bit, ending_bit;
	
	printf("Input original_value: ");
	scanf_s("%d", &original_value);
	printf("Input value_to_storge: ");
	scanf_s("%d", &value_to_storge);
	printf("Input starting_bit: ");
	scanf_s("%d", &starting_bit);
	printf("Input ending_bit: ");
	scanf_s("%d", &ending_bit);

	store_bit_field(original_value, value_to_storge, starting_bit, ending_bit);
	printf("After the operation, original_value =%d\n", store_bit_field(original_value, value_to_storge, starting_bit, ending_bit));

	return EXIT_SUCCESS;
}
