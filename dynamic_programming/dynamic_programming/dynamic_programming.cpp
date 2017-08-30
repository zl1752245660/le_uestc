// dynamic_programming.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "matrix_mutifly.h"
#include "lcs_problem.h"
#include "Longest_palindrome_subsequence.h"
#include "string_partition.h"
#define		LEN		100


/************************************************************************/
/* �����и�����                                                            */
/* һ��ָ�����ȵĸ�������ô�и���ܱ�֤�и��������ܼ�ֵ���                       */
/************************************************************************/

/************************************************************************/
/*����i	 1  2  3  4  5  6  7  8  9  10
/*�۸�pi  1  5  8  9  10 17 17 20 24 30
*/
/************************************************************************/





/************************************************************************/
/* ѭ����ӡ�и�����ĸ���                                                                     */
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
/* �Զ����µݹ�ʵ��
/* �����ʽ��ʵ���зǳ����ȱ�ݣ���Ϊ������һֱ������ͬ���������⣬���³������зǳ���                                                                     */
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
/* ������¼���Զ����µݹ�ʵ��                                                */
/************************************************************************/
int memorized_cut_rod(int price[] ,const int n,int price_len) 
{
	//���Ѿ�������������Ᵽ����r�����У�������������ظ�����
	int r[LEN + 1];
	for (int i = 0;i <= LEN; i++)
	{
		r[i] = -1;
	}
	return memorized_cut_rod_aux(price,n,r,price_len);
}


/************************************************************************/
/* �Ե����ϰ汾�Ķ�̬�滮������������˵����                                                                     */
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
/* 15.1-3����Ŀ��֮ǰ�ĸ����и��ֻ࣬��ÿ���иҪ�����̶��ĳɱ�c����Ƴ��µĽ������  */
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

