#include "matrix_mutifly.h"
#include "stdafx.h"

/************************************************************************/
/* 矩阵连乘问题															*/
/*矩阵 |   A1  |   A2  |  A3  |  A4  |   A5  |   A6						*/
/*规模 | 30*35 | 35*15 | 15*5 | 5*10 | 10*20 | 20*25						*/
/************************************************************************/

#define LEN		100
#define MAX_INT 100000

/************************************************************************/
/* 递归打印                                                               */
/************************************************************************/
void print_optimal_parens(int s[LEN][LEN], int i,int j)
{
	if (i == j)
	{  
		printf("A[%d]",i);
	}
	else 
	{
		printf("(");
		print_optimal_parens(s,i,s[i][j]);
		print_optimal_parens(s,s[i][j]+1,j);
		printf(")");
	}
}

/************************************************************************/
/* 自底向上算出最小值                                                       */
/************************************************************************/
void matrix_chain_order(int matrix[],int number)
{
	int m[LEN][LEN];
	int s[LEN][LEN];

	for (int i = 1; i <= number; i++)
	{
		m[i][i] = 0;
	}

	for (int l = 2; l <= number; l++)
	{
		for (int i = 1; i <= number-l+1; i++)
		{
			int j = i + l - 1;
			m[i][j] = MAX_INT;

			for (int k = i ;k < j; k++)
			{
				int q = m[i][k] + m[k+1][j] + matrix[i-1] * matrix[k] * matrix[j];
				if(q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	print_optimal_parens(s,1,6);
	printf("\n");
	printf("Min : %d\n", m[1][6]);
}

int lookup_chain(int matrix[],int m[LEN][LEN], int s[LEN][LEN],int i,int j)
{
	if (m[i][j] < MAX_INT)
	{
		return m[i][j];
	}
	for (int k = i;k < j; k++)
	{
		int q = lookup_chain(matrix,m,s,i,k) + lookup_chain(matrix,m,s,k+1,j) + matrix[i-1]*matrix[k]*matrix[j];
		if (q < m[i][j])
		{
			m[i][j] = q;
			s[i][j] = k;
		}
	}
	return m[i][j];
}

/************************************************************************/
/* 备忘录法，采用又顶向底的方法，为了避免子问题重叠的问题，所以用一个数组表保存已经计算出的值，避免重复计算   */
/************************************************************************/
void memory_matrix_chain(int matrix[] ,int number)
{
	int m[LEN][LEN];
	int s[LEN][LEN];

	for (int i = 0; i <= number; i++)
	{
		for (int j = 0;j <= number; j++)
		{
			if (i == j)
			{
				m[i][j] = 0;
			}
			else 
			{
				m[i][j] = MAX_INT;
			}
		}
	}
	int Min = lookup_chain(matrix,m,s,1,number);
	printf("Memory Min : %d\n",Min);
	print_optimal_parens(s,1,number);
}

int solve_matrix_mutifly() 
{
	int matrix[7] = {30,35,15,5,10,20,25};

	memory_matrix_chain(matrix,6);
	return 0;
}