#include "lcs_problem.h"
#include "stdafx.h"

#define  LEN 100

/************************************************************************/
/* 最长公共子序列问题                                                      */
/* X = <A,B,C,B,D,A,B>													*/
/* Y = <B,D,C,A,B,A>													*/
/************************************************************************/

void print_lcs(int c[LEN][LEN],char x[],int i,int j)
{
	//printf("i = %d , j = %d , %d\n",i,j,c[i][j]);
	if (i == 0 || j == 0)
	{
		return;
	}
	if (c[i][j] == 3)
	{
		print_lcs(c,x,i-1,j-1);
		printf("%c",x[i]);
	} 
	else if (c[i][j] == 2)
	{
		print_lcs(c,x,i,j-1);
	}
	else
	{
		print_lcs(c,x,i-1,j);
	}
}

void lcs_length(char x[], char y[],int m, int n)
{
	int b[LEN][LEN];
	int c[LEN][LEN];

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			b[i][j] = 0;
			c[i][j] = 0;
		}
	}

	for (int i = 1;i <= m; i++)
	{
		for (int j = 1;j <= n; j++)
		{
			if (x[i] == y[j])
			{
				b[i][j] = b[i-1][j-1] + 1;
				c[i][j] = 3;
			}
			else 
			{
				if (b[i][j-1] >= b[i-1][j])
				{
					b[i][j] = b[i][j-1];
					c[i][j] = 2;
				} 
				else 
				{
					b[i][j] = b[i-1][j];
					c[i][j] = 1;
				}
			}
		}
	}
	
	print_lcs(c,x,m,n);
	printf("\n"); 
	printf("LCS lenght : %d\n",b[m][n]);
}

void solve_lcs_problem()
{
	char x[8] = {' ', 'A', 'B', 'C', 'B', 'D', 'A', 'B'};
	char y[7] = {' ', 'B', 'D', 'C', 'A', 'B', 'A'};

	lcs_length(x,y,7,6); 
}