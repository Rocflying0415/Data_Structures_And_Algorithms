/*
 * all_sort.h
 *
 *  Created on: 2019年4月20日
 *      Author: Zuokp
 */

#ifndef INCLUDE_ALL_SORT_H_
#define INCLUDE_ALL_SORT_H_

#include "common.h"

void MySwap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

int patition(int *a, int left, int right)
{
	int j = left;
	int i = j - 1;
	int key = a[right];

	for (; j < right; ++j)
	{
		if (a[j] <= key)
			MySwap(&a[j], &a[++i]);
	}
	MySwap(&a[right], &a[++i]);
	return i;
}

void quickSort(int *a, int left, int right)
{
	if (left >= right)
		return;
	int mid = patition(a, left, right);
	quickSort(a, left, mid - 1);
	quickSort(a, mid + 1, right);
}
#endif
