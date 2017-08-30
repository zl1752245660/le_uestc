#include "stdafx.h"
#include "string_partition.h"
#define LEN 100
#define MAX_INT 10000

/************************************************************************/
/* 字符串拆分问题                                                                 */
/************************************************************************/

int MIN(int a, int b)
{
	return a >= b ? b : a;
}

void print_partition_sort(int c[LEN][LEN], int i, int j,int n)
{
	if (i == j || i <= 0 || j > n || c[i][j] == 0)
	{
		return;
	}
	printf("%d ",c[i][j]);
	print_partition_sort(c, i, c[i][j], n);
	print_partition_sort(c, c[i][j] + 1,j, n);
}

int get_min_partition_value(int partitions[], int n, int p_length)
{
	int m[LEN][LEN];
	int c[LEN][LEN];
	for (int i = 0;i <= n; i++)
	{
		for (int j = 0;j <= n; j++)
		{
			m[i][j] = 0;
			c[i][j] = 0;
		}
		m[i][i] = 1;
	}

	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i <= n - l + 1; i++)
		{
			int j = l + i - 1;
			int q;
			for (int k = 0; k < p_length; k++)
			{
				if (i < partitions[k] && partitions[k] < j)
				{
					q = j - i + 1 + m[i][partitions[k]] + m[partitions[k]+1][j];
					//printf("l = %d, i = %d, j = %d, q = %d\n", l, i, j, q);
					if (q < m[i][j] || m[i][j] == 0)
					{
						m[i][j] = q;
						c[i][j] = partitions[k];
					}
				}
			}

		}
	}

	printf("总的拆分次数 : %d\n",m[1][n]);

	printf("--------------------------------------------------------------------\n");

	print_partition_sort(c,1,n , n);

	return 0;
}


int solve_string_partition()
{
	int partitions[] = {2, 8, 10};
	get_min_partition_value(partitions,20,3);
	return 0;
}