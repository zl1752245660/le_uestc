/*

问题描述 ： P1024
	XXXX年突然有外星人造访，但大家语言不通，不过科学家们经过研究发现外星人用26个英文字母组成的单词中最长不降子序列的长度来表述数字，且英文字母的排列顺序不同，现给出其排列顺序，再给出外星人说的每个数字（其实是每个英文单词，用空格隔开），翻译出外星人所说的数字（连续输出，最后加回车）。
	 	 (因为是最长不降子序列，所以数字中没有0，也就是说外星人的数字是>=1的数字)
		 例如
	    	 我们正常的字母排列顺序是abcdefg…….xyz，代表a<b<c<…..<x<y<z
			 abcd efg hhh ihg四个字符串的最长不降子序列的长度分别为4 3 3 1
*/

/************************************************************************/
/* 测试数据 ： oydijklmrstazepqbcnuvwxfgh 
			pqbcnuvwxfgh abcdefghijklmnopqrstuvwxyz   */
/************************************************************************/

#include "stdafx.h"
#include "P1024_problem.h"
#include <string.h>
#define LEN 256

int get_max_lenght(char x[LEN], char y[LEN], int m, int n)
{
	int b[LEN][LEN];
	for (int i = 0;i <= m; i++)
	{
		for (int j = 0;j <= n; j++)
		{
			b[i][j] = 0;
		}
	}
	
	for (int i = 1;i <= m; i++)
	{
		for (int j = 1;j <= n; j++)
		{
			if(j > 1) {
				if(y[j] != y[j-1]) {
					if(x[i] == y[j]) {
						b[i][j] = b[i-1][j-1] + 1;
					} else if(b[i-1][j] < b[i][j-1]) {
						b[i][j] = b[i][j-1];
					} else {
						b[i][j] = b[i-1][j];
					}
				} else {
					b[i][j] = b[i][j-1] + 1;
				}
			} else {
				if(x[i] == y[j]) {
					b[i][j] = b[i-1][j-1] + 1;
				} else if(b[i-1][j] < b[i][j-1]) {
					b[i][j] = b[i][j-1];
				} else {
					b[i][j] = b[i-1][j];
				}
			}
		}
	}
	
	return b[m][n];
}

int solve_p1024() 
{
	char x[] = " oydijklmrstazepqbcnuvwxfgh";
	char y[] = " pqbcnuvwxfgh";

	int m = strlen(x);;
	int n = strlen(y);

	int max_len = get_max_lenght(x,y, m-1, n-1);
	printf("max_len : %d\n",max_len);

	getchar();

	return 0;
}