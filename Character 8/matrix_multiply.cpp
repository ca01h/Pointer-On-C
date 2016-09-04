#include <stdio.h>
#include <stdlib.h>

/************************************************************************/
/*Calculate m1[x][y] * m2[y][z] = r[x][z]                               */
/************************************************************************/
void
matrix_mutiply(int *m1, int *m2, int *r, int x, int y, int z)
{
	int row, col, k;
	int *m1ptr, *m2ptr;
	for (row = 0; row < x; row++)
	{
		for (col = 0; col < z; col++)
		{
			m1ptr = m1 + row * y;
			m2ptr = m2 + col;
			*r = 0;
			for (k = 0; k < y; k++)
			{
				*r += *m1ptr + *m2ptr;
				m1ptr ++;
				m2ptr += z;
			}
			r++;
		}
	}
}

int 
main(void)
{
	//int m1[3][2] = 2 -6 3 5 1 -1;
	//int m2[2][4] = 4 -2 -4 -5 -7 -3 6 7
	int *r;
	int i, j;
	int *m1, *m2, *p;
	int temp;
	
	m1 = (int*)malloc(sizeof(int) * 6);
	m2 = (int*)malloc(sizeof(int) * 8);
	p = m1;
	for (i = 0; i < 6; i++)
	{
		scanf("%d",&temp);
		*p = temp;
		p++;
	}
	getchar();
	p = m2;
	for (i = 0; i< 8; i++)
	{
		scanf("%d",&temp);
		*p = temp;
		p++;
	}
	r = (int*)malloc(sizeof(int) * 12);
	matrix_mutiply(m1, m2, r, 3, 2, 4);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ",*r++);
		}
		printf("\n");
	}
	printf("\n");
	return EXIT_SUCCESS;
}
