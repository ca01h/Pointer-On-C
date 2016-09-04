#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int
identity_matrix(int matrix[10][10])
{
	int row, column;
	for (row = 0; row < 10; row++)
	{
		for (column = 0; column < 10; column++)
		{
			if (matrix[row][matrix] != (row == column))
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}
