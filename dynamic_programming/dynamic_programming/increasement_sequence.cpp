#include "increasement_sequence.h"
#include "stdafx.h"

#define LEN 100

void print_increment_item(int s[LEN],int i,int array[])
{
	if (s[i] == -1)
	{
		printf("%d ",array[i]);
		return;
	}

	print_increment_item(s, s[i], array);
	printf("%d ",array[i]);
}

int solve_increasing_sequence(int array[], int n)
{
	int m[LEN];
	int s[LEN];
	int max_num = 0;
	int last_item = 0;

	for (int i = 0; i < n; i++)
	{
		m[i] = 1;
		s[i] = -1;
	}

	for (int i = 1;i < n; i++)
	{
		for (int j = 0;j < i; j++)
		{
			if (array[j] < array[i])
			{
				int q = m[j] + 1;
				if (q > m[i])
				{
					m[i] = q;
					s[i] = j;
					if (m[i] > max_num)
					{
						max_num = m[i];
						last_item = i;
					}
				}
			}
		}
	}
	
	printf("max_num = %d \n",max_num);

	print_increment_item(s,last_item,array);

	return 0;
}
 
void increasing_sequence()
{
	int array[] = {6,4,5,1,4,5,8,6,7,5};
	solve_increasing_sequence(array,10);
}