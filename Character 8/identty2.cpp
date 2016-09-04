#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int
identity_matrix(int *matrix, int size)
{
	int row, column;
	for (row = 0; row < 10; row++)
	{
		for (column = 0; column < 10; column++)
		{
			if (*matrix++ != (row == column))//this way to judge one site is 1 or 0 can inspire me.
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}
