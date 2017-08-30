#include "stdafx.h"
#include "single_way_apple.h"
#define LEN 100

/************************************************************************/
/*                    ��·ȡƻ������										*/
/* һ���������򱻻���ΪN*M��С���θ��ӣ��ڸ���(i,j)����A[i][j]��ƻ����           */
/* ���ڴ����Ͻǵĸ���(1,1)������Ҫ��ÿ��ֻ��������һ����������һ������󵽴�(N,M)��  */
/* ÿ����һ�����ӾͰ����е�ƻ��ȫ�����ߡ����ҳ����õ����ƻ������·��               */
/* 5 , 3 , 2 , 6 , 4                                                    */
/* 2 , 3 , 1 , 5 , 2                                                    */
/* 1 , 4 , 2 , 5 , 7                                                    */
/* 7 , 2 , 4 , 6 , 2                                                    */
/* 5 , 3 , 1 , 6 , 2                                                    */
/************************************************************************/
void print_singal_way_apple(int c[LEN][LEN], int apples[5][5],int i, int j)
{
	if (i == 0 && j == 0)
	{
		printf("i = %d, j = %d,  %d\n",i, j, apples[i][j]);
		return;
	}
	if (c[i][j] == 2)
	{
		print_singal_way_apple(c, apples, i, j-1);
		printf("i = %d, j = %d,  %d\n",i, j, apples[i][j]);
	}
	else if (c[i][j] == 1)
	{
		print_singal_way_apple(c, apples, i-1, j);
		printf("i = %d, j = %d,  %d\n",i, j, apples[i][j]);
	}
}

void singal_way_apple(int apples[5][5], int raw, int colume)
{
	int m[LEN][LEN];
	int c[LEN][LEN];

	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < colume; j++)
		{
			if (i == 0 && j == 0)
			{
				m[i][j] = apples[i][j];
			}
			else if (i == 0)
			{
				m[i][j] = m[i][j-1] + apples[i][j];
				c[i][j] = 2;
			}
			else if (j == 0)
			{
				m[i][j] = m[i-1][j] + apples[i][j];
				c[i][j] = 1;
			}
			else 
			{
				if (m[i][j-1] >= m[i-1][j])
				{
					m[i][j] = m[i][j-1] + apples[i][j];
					c[i][j] = 2;
				} 
				else 
				{
					m[i][j] = m[i-1][j] + apples[i][j];
					c[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < colume; j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	printf("----------------------------------------\n");
	print_singal_way_apple(c, apples, raw - 1, colume - 1);
}

int solve_single_way_apple()
{

	int apples[5][5] = {{5, 3, 2, 6, 4}, {2, 3, 1, 5, 2} , {1, 4, 2, 5, 7},{7, 2, 4, 6, 2}, {5, 3, 1, 6, 2}};
	singal_way_apple(apples,5,5);

	return 0;
}