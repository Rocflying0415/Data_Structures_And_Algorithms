/* 
 * File:   main.c
 * Author: rocflying
 *
 * Created on 2019年6月26日, 下午12:19
 */
#include "sort.h"
/*
 * 
 */
int main(int argc, char** argv)
{
    int szData[ARRAY_SIZE] = {};
    FUNC f;

    f = BubbleSort;
    testFunc(f, "冒泡排序", szData, ARRAY_SIZE);
    f = BubbleSortFlag;
    testFunc(f, "冒泡排序优化", szData, ARRAY_SIZE);
    f = QuickSort;
    testFunc(f, "快速排序", szData, ARRAY_SIZE);
    f = InsertionSort;
    testFunc(f, "插入排序", szData, ARRAY_SIZE);
    f = ShellSort;
    testFunc(f, "希尔排序", szData, ARRAY_SIZE);
    f = SelectionSort;
    testFunc(f, "选择排序", szData, ARRAY_SIZE);
    f = HeapSort;
    testFunc(f, "堆排序", szData, ARRAY_SIZE);
    f = MergeSort;
    testFunc(f, "归并排序", szData, ARRAY_SIZE);
    f = RadixSort;
    testFunc(f, "基数排序", szData, ARRAY_SIZE);
    return (EXIT_SUCCESS);
}

