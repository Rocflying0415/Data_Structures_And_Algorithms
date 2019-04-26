/*
 * main.c
 *
 *  Created on: 2019年4月20日
 *      Author: Zuokp
 */
#include "all_sort.h"

int main(int argc, char *argv[])
{
	int szData[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1};

	int i, j;
	int size = sizeof(szData) / sizeof(szData[0]);
	quickSort(szData, 0, size - 1);
	for (i = 0, j = 1; i < size; ++i, ++j)
	{
		printf("%d ", szData[i]);
		if (j % 10 == 0)
			putchar('\n');
	}
	putchar('\n');
	return 0;
}



