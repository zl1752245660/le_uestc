// dynamic_programming.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "matrix_mutifly.h"
#include "lcs_problem.h"
#include "Longest_palindrome_subsequence.h"
#include "string_partition.h"
#define		LEN		100


/************************************************************************/
/* 钢条切割问题                                                            */
/* 一个指定长度的钢条，怎么切割才能保证切割下来的总价值最高                       */
/************************************************************************/

/************************************************************************/
/*长度i	 1  2  3  4  5  6  7  8  9  10
/*价格pi  1  5  8  9  10 17 17 20 24 30
*/
/************************************************************************/





/************************************************************************/
/* 循环打印切割出来的钢条                                                                     */
/************************************************************************/
int print_cut_rod_solution(int price[], int n,int s[])
{
	while (n > 0)
	{
		printf("%d\n", s[n]);
		n = n - s[n];
	}
	return 0;
}

/************************************************************************/
/* 自顶向下递归实现
/* 这个方式的实现有非常大的缺陷，因为程序在一直计算着同样的子问题，导致程序运行非常慢                                                                     */
/************************************************************************/
int cut_rod(int price[],int n,int price_len) 
{
	if(n == 0)
	{
		return 0;
	}
	int q = 0;
	int len = n < price_len ? n : price_len;
	for (int i = 1;i <= len; i++)
	{
		q = MAX(q,price[i] + cut_rod(price,n - i, len));
	}
	return q;
}


int memorized_cut_rod_aux(int price[],const int n,int r[],int price_len)
{
	if(r[n] >= 0) 
	{
		return r[n];
	}
	int q;
	if (n == 0)
	{
		q = 0;
	}
	else 
	{
		q = -1;
		int len = n < price_len ? n : price_len;
		
		for (int i = 1;i <= len; i++)
		{
			q = MAX(q,price[i] + memorized_cut_rod_aux(price,n-i,r,price_len));
		}
	}
	
	r[n] = q;
	return q;
}

/************************************************************************/
/* 带备忘录的自顶向下递归实现                                                */
/************************************************************************/
int memorized_cut_rod(int price[] ,const int n,int price_len) 
{
	//将已经计算过的子问题保存在r数组中，避免子问题的重复计算
	int r[LEN + 1];
	for (int i = 0;i <= LEN; i++)
	{
		r[i] = -1;
	}
	return memorized_cut_rod_aux(price,n,r,price_len);
}


/************************************************************************/
/* 自底向上版本的动态规划，从性能上来说更好                                                                     */
/************************************************************************/
int buttom_up_cut_rod(int price[],const int n,int price_len) 
{
	int r[LEN + 1];
	int s[LEN + 1];
	r[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		int len = i < price_len ? i : price_len;
		int q = 0;
		for (int j = 1; j <= len ; j++)
		{
			if(q < (price[j] + r[i - j]))
			{
				q = price[j] + r[i - j];
				s[i] = j;
			}
		}
		r[i] = q;
	}

	print_cut_rod_solution(price,n,s);

	return r[n];
}

/************************************************************************/
/* 15.1-3，题目和之前的钢条切割差不多，只是每次切割都要付出固定的成本c，设计出新的解决方案  */
/************************************************************************/
int new_buttom_up_cut_rod(int price[],const int n,int price_len,int c)
{
	int r[LEN + 1];
	int s[LEN + 1];
	r[0] = 0;

	for (int i = 1;i <= n; i++)
	{
		int len = i < price_len ? i : price_len;
		int q = 0;
		for (int j = 1;j <= len; j++)
		{
			int temp;

			if (j == len)
			{
				temp = price[j] + r[i - j];
			}
			else 
			{
				temp = price[j] + r[i - j] - c;
			}
			if (q < temp)
			{
				q = temp;
				s[i] = j;
			}
		}
		r[i] = q;
	}
	print_cut_rod_solution(price,n,s);

	return r[n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	int price[] = {0,1,5,8,9,10,17,17,20,24,30};
	int price_len = sizeof(price)/sizeof(int) - 1;
	int result = new_buttom_up_cut_rod(price, 8,price_len,1);
	printf("result : %d\n",result);
	*/
	//solve_matrix_mutifly();
	//solve_lcs_problem();
	//solve_palindrome_subsequence();
	solve_string_partition();
	getchar();
	return 0;
}

