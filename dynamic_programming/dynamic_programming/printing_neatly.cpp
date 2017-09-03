#include "stdafx.h"
#include "printing_neatly.h"

#define MAX_INT 100000
#define MAX_LINE 30
#define LEN 100

/**********************************************************************************
考慮整齊打印問題，即在打印機商用等寬字符打印一段文本。輸入文本爲 n 個單
詞的序列，單詞長度分別爲 l1,l2,…,ln 個字符。我們希望將此段文本整齊打印在若幹行商，每行最多 M 個字
符。“整齊”的標準是這樣的：如果某行包含第 i 到第 j（i ≤ j）個單詞，且單詞間隔爲一個空格符，則行尾的
額外空格符數量爲 M − j + i − ∑k=i jlk，此值必須爲非負的，否則一行內無法容納這些單詞。我們希望能最
小化所有行（最後一行除外）的額外空格數的立方之和。設計一個動態規劃算法，在打印機商整齊打印一段 n
個單詞的文本。分析算法的時間、空間復雜性
***********************************************************************************/

int lineCost(int i, int j, int str[], int n)
{
	int extras = MAX_LINE - j + i; 
	int sum = 0;
	for (int k = i; k <= j ; k++)
	{
		/*
		if (i == 8 && j == 10)
		{
			printf("str[%d] = %d\t",k,str[k]);
			printf("sum = %d\t",sum);
		}
		*/
		
		sum = sum + str[k];
	}
	/*
	if (i == 8 && j == 10)
	{
		printf("sum = %d\t",sum);
	}
	*/
	int result = (extras - sum);
	if (result < 0)
	{
		return MAX_INT;
	}

	if (j == n-1 && result >= 0)
	{
		return 0;
	}

	return result ;
}

void print_every_line_neatly(int c[LEN],int i,int str[])
{
	int n = c[i];
	//printf("n = %d\n",n);
	if (n == 0)
	{
		for (int j = n+1;j <= i; j++)
		{
			printf("%d\t",str[j]);
		}
		printf("\n");
		return;
	}
	print_every_line_neatly(c,n,str);
	for (int j = n+1;j <= i; j++)
	{
		printf("%d\t",str[j]);
	}
	printf("\n");
}

int printing_neatly(int str[], int n)
{
	int c[LEN];
	int l[LEN];

	c[0] = 0;

	for (int j = 1; j < n; j++)
	{
		c[j] = MAX_INT;
		for (int i = 1;i <=j ; i++)
		{
			int lc = lineCost(i, j, str, n);
			//printf("i = %d,j = %d,lc = %d\n",i,j,lc);
			if (lc == MAX_INT)
			{
				continue;
			}
			int temp = c[i-1] + lc;
			if (temp < c[j])
			{
				c[j] = temp;
				l[j] = i - 1;
			}
		}
	}
	
	/*
	for (int i = 1; i < n ;i++)
	{
		printf("i = %d, %d\n", i, c[i]);
	}
	printf("--------------------------------------\n");
	for (int i = 1; i < n ;i++)
	{
		printf("i = %d, %d\n", i, l[i]);
	}
	*/
	printf("总的空格数: %d\n",c[n-1]);

	print_every_line_neatly(l,n-1,str);
	return 0;
}

void solve_printing_neatly()
{
	int str[] = { 0, 3, 5, 1, 5, 3, 2, 6, 8, 2, 5, 8, 4, 7, 4, 9, 2, 10};
	int n = sizeof(str) / sizeof(int);
	printing_neatly(str, n);
}