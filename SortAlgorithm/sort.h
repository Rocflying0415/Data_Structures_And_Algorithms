/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sort.h
 * Author: rocflying
 *
 * Created on 2019年6月26日, 下午12:20
 */

#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 15

typedef enum
{
    FALSE,
    TRUE,
} BOOL;

typedef void (*FUNC) (int *data, int size);

void Swap(int *a, int *b);
//冒泡排序
void BubbleSort(int *data, int size);
//冒泡排序(优化)
void BubbleSortFlag(int *data, int size);
//快速排序
int PartitionArray(int *data, int left, int right);
void Recursion(int *data, int left, int right);
void QuickSort(int *data, int size);
//直接插入排序
 void InsertionSort(int *data, int size);
//希尔排序
 void ShellSort(int *data, int size);
 //选择排序
 void SelectionSort(int *data, int size);
//堆排序
 void MaxTopHeap(int *data, int start, int end);
 void HeapSort(int *data, int size);
//归并排序
 void Merge(int *data,int size,int gap);
 void MergeSort(int *data,int size);
//基数排序
 int MaxBit(int *data, int size);//求数据的最大位数
 void RadixSort(int *data, int size);
//测试相关
void showArray(const int *data, int size);
void testFunc(FUNC f, const char *str, int *data, int size);
#endif /* SORT_H */

