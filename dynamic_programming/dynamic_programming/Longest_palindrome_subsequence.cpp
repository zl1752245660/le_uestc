#include "stdafx.h"
#include <string.h>
#include "Longest_palindrome_subsequence.h"

#define LEN 100


/************************************************************************/
/* 最长回文子序列                                                          */
/* 方法一： 将输入序列倒转，然后求两个序列的最长公共子序列                        */
/************************************************************************/
static void reverse_sequence(char x[], char y[], int n)
{
	for (int i = 0;i <= n; i++)
	{
		y[i] = x[n - i];
	}
}

void print_palindrome_subsequence(char x[],char y[],int c[LEN][LEN],int i,int j)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (c[i][j] == 3)
	{
		print_palindrome_subsequence(x,y,c,i-1,j-1);
		printf("%c",x[i-1]);
	} 
	else if (c[i][j] == 2)
	{
		print_palindrome_subsequence(x,y,c,i,j-1);
	}
	else
	{
		print_palindrome_subsequence(x,y,c,i-1,j);
	}
}

int get_max_palindrome_subsequence(char x[],char y[],int n)
{
	int b[LEN][LEN];
	int c[LEN][LEN];

	for (int i = 0;i <= n; i++)
	{
		for (int j = 0;j <= n; j++)
		{
			b[i][j] = 0;
		}
	}

	for (int i = 1;i <= n; i++)
	{
		for (int j = 1;j <= n; j++)
		{
			if (x[i-1] == y[j-1])
			{
				b[i][j] = b[i-1][j-1] + 1;
				c[i][j] = 3;
			} 
			else if (b[i-1][j] >= b[i][j-1])
			{
				b[i][j] = b[i-1][j];
				c[i][j] = 1;
			}
			else 
			{
				b[i][j] = b[i][j-1];
				c[i][j] = 2;
			}
		}
	}

	print_palindrome_subsequence(x,y,c,n,n);

	return 0;
}

int memory_palindrome_subsequence(char x[], int b[LEN][LEN], int c[LEN][LEN], int n, int i, int j)
{
	if (b[i][j] > 0)
	{
		return b[i][j];
	}

	if (i == j)
	{
		return 1;
	}

	if (x[i] == x[j])
	{
		b[i][j] = memory_palindrome_subsequence(x,b,c,n,i+1,j-1) + 2;
		c[i][j] = 3;

	}
	else if (memory_palindrome_subsequence(x,b,c,n,i+1,j) >= memory_palindrome_subsequence(x,b,c,n,i,j-1))
	{
		b[i][j] = memory_palindrome_subsequence(x,b,c,n,i+1,j);
		c[i][j] = 2;
	}
	else
	{
		b[i][j] = memory_palindrome_subsequence(x,b,c,n,i,j-1);
		c[i][j] = 1;
	}
	return b[i][j];
}

void print_palindrome_subsequence2(char x[],int i,int j,int c[LEN][LEN])
{
	if (i == j)
	{
		printf("%c",x[i]);
		return ;
	}

	if (c[i][j] == 3)
	{
		printf("%c",x[i]);
		print_palindrome_subsequence2(x,i+1,j-1,c);
		printf("%c",x[j]);
	} 
	else if (c[i][j] == 2)
	{
		print_palindrome_subsequence2(x,i+1,j,c);
	}
	else 
	{
		print_palindrome_subsequence2(x,i,j-1,c);
	}
}

int get_max_palindrome_subsequence2(char x[], int n)
{
	int b[LEN][LEN];
	int c[LEN][LEN];
	for (int i = 0;i <= n; i++)
	{
		for (int j = 0;j <= n; j++)
		{
			b[i][j] = 0;
		}
	}
	int result = memory_palindrome_subsequence(x,b,c,n,0,n);
	
	for (int i = 0;i <= n; i++)
	{
		for (int j = 0;j <= n; j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}

	print_palindrome_subsequence2(x,0,n,c);
	return result;
}

void print_palindrome_subsequence3(char x[],int i,int j,int c[LEN][LEN])
{
	if (i == j)
	{
		printf("%c",x[i]);
		return ;
	}
	if (c[i][j] == 4)
	{
		printf("%c",x[i]);
		printf("%c",x[j]);
	}
	else if (c[i][j] == 3)
	{
		printf("%c",x[i]);
		print_palindrome_subsequence3(x,i+1,j-1,c);
		printf("%c",x[j]);
	} 
	else if (c[i][j] == 2)
	{
		print_palindrome_subsequence3(x,i+1,j,c);
	}
	else 
	{
		print_palindrome_subsequence3(x,i,j-1,c);
	}
}

int get_max_palindrome_subsequence3(char x[],int n)
{
	int b[LEN][LEN];
	int c[LEN][LEN];

	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < n; j++)
		{
			b[i][j] = 0;
			c[i][j] = 0;
		}
		b[i][i] = 1;
	}

	for (int l = 3; l <= n; l++)
	{
		for (int i = 0; i <= n-l; i++)
		{
			int j = l + i - 1;
			//printf("l = %d, i = %d, j = %d\n",l,i,j);
			if (x[i] == x[j])
			{
				if ((j - i) == 1)
				{
					b[i][j] = 2;
					c[i][j] = 4;
				}
				else 
				{
					b[i][j] = b[i+1][j-1] + 2;
					c[i][j] = 3;
				}
			}
			else if (b[i+1][j] >= b[i][j-1])
			{
				b[i][j] = b[i+1][j];
				c[i][j] = 2;
			}
			else 
			{
				b[i][j] = b[i][j-1];
				c[i][j] = 1;
			}
		}
	}

	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < n; j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}

	print_palindrome_subsequence3(x,0,n-1,c);

	return 0;
}

int solve_palindrome_subsequence() 
{
	char x[] = "ABCBDAB";
	char y[LEN];

	reverse_sequence(x,y,strlen(x) - 1);
	get_max_palindrome_subsequence3(x,strlen(x));

	return 0;
}