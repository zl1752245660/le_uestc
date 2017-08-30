#include "stdafx.h"
#include "single_way_apple.h"
#define LEN 100

/************************************************************************/
/*                    单路取苹果问题										*/
/* 一个矩形区域被划分为N*M个小矩形格子，在格子(i,j)中有A[i][j]个苹果。           */
/* 现在从左上角的格子(1,1)出发，要求每次只能向右走一步或向下走一步，最后到达(N,M)，  */
/* 每经过一个格子就把其中的苹果全部拿走。请找出能拿到最多苹果数的路线               */
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