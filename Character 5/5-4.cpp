#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned character_offset(unsigned bit_number)
{
	return bit_number / CHAR_BIT;
}

unsigned bits_offset(unsigned bit_number)
{
	return bit_number % CHAR_BIT;
}

void set_bit(char bit_array[], unsigned bit_number)
{
	bit_array[character_offset(bit_number)] |= 1 << bits_offset(bit_number);
}

void clear_bit(char bit_array[], unsigned bit_number)
{
	bit_array[character_offset(bit_number)] &= ~(1 << bits_offset(bit_number));
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
	if (value == 0)
	{
		clear_bit(bit_array, bit_number);
	} 
	else
	{
		set_bit(bit_array, bit_number);
	}
}

int test_bit(char bit_array[], unsigned bit_number)
{
	if (!(bit_array[character_offset(bit_number)] &= 1 << bits_offset(bit_number)))
	{
		return true;
	} 
	else
	{
		return false;
	}
}