/*
 * main.c
 *
 *  Created on: 2019年4月26日
 *      Author: Zuokp
 */
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(s) (sizeof(s) / sizeof(s[0]))

void MySwap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void BubbleSort(int *a, int len)
{
	if ((NULL == a) || (len <=1))
		return;
	int i, j;

	for (i = 0; i < len - 1; ++i)
	{
		for (j = 0; j < len - i -1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				MySwap(&a[j], &a[j + 1]);
			}
		}
	}
}

void showData(int *a, int len)
{
	if ((NULL == a) || (len <= 0))
		return;
	int i = 0;
	for (; i < len; ++i)
		printf("%d ", a[i]);
	putchar('\n');
}

int main(int argc, char *argv[])
{
	int szData[] = {3, 2, 1, -1, 0, 5, 4, -4};

	int len = ARRAY_SIZE(szData);

	BubbleSort(szData, len);
	showData(szData, len);
	return 0;
}


