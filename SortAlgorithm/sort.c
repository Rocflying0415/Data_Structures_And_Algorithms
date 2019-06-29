#include "sort.h"

void Swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void BubbleSort(int *data, int size)
{
    if (NULL == data || 1 >= size)
        return;
    int i, j;
    for (i = 0; i < size - 1; ++i)
    {
        for (j = 0; j < size - i - 1; ++j)
        {
            if (data[j] > data[j + 1])
                Swap(&data[j], &data[j + 1]);
        }
#if 1
        fprintf(stdout, "第 %02d 步排序结果：", i + 1);
        showArray(data, size);
#endif
    }
}
void BubbleSortFlag(int *data, int size)
{
    if (NULL == data || 1 >= size)
        return;
    BOOL flag;
    int i, j;
    for (i = 0; i < size - 1; ++i)
    {
        flag = FALSE;
        for (j = 0; j < size - i - 1; ++j)
        {
            if (data[j] > data[j + 1])
            {
                 Swap(&data[j], &data[j + 1]);
                 flag = TRUE;
            }
        }
        if (!flag)
            break;//未发生交换了
#if 1
        fprintf(stdout, "第 %02d 步排序结果：", i + 1);
        showArray(data, size);
#endif
    }
}
int PartitionArray(int *data, int left, int right)
{
    if (NULL == data || left >= right)
        return -1;
    int j = left;
    int i = j - 1;
    int key = data[right];
    static int n = 0;
    while (j < right)
    {
        if (data[j] <= key)
            Swap(&data[j], &data[++i]);
        ++j;
    }
    Swap(&data[right], &data[++i]);
#if 1
    fprintf(stdout, "第 %02d 步排序结果：", ++n);
    showArray(data, ARRAY_SIZE);
#endif
    return i;
}

void Recursion(int *data, int left, int right)
{
    if (left >= right)
        return;
    int mid = PartitionArray(data, left, right);
    if (-1 != mid)
    {
        Recursion(data, left, mid - 1);
        Recursion(data, mid + 1, right);
    }
}
void QuickSort(int *data, int size)
{
    if (NULL == data || 1 >= size)
        return;
    Recursion(data, 0, size - 1);
}
 void InsertionSort(int *data, int size)
 {
     if (NULL == data || 1 >= size)
         return;
     int i, j;
     int temp;
     for (i = 1; i < size; ++i)
     {
         if (data[i - 1] > data[i])
         {
             temp = data[i];
             for (j = i - 1; j >= 0 && data[j] > temp; --j)
             {
                 Swap(&data[j], &data[j + 1]);
             }
             data[j + 1] = temp;
         }
#if 1
        fprintf(stdout, "第 %02d 步排序结果：", i);
        showArray(data, size);    
#endif
     }
     
}
void ShellSort(int *data, int size)
{
    if (NULL == data || 1 >= size)
        return;
    int i, j, gap;
    int temp;
    int n = 0;

    for (gap = size / 2; gap >= 1; gap /= 2) // 使用增量序列gap = {n/2 ,n/4, n/8 .....1}
    {
        for (i = gap; i < size; i++) // 注意 i的增量为 1
        {
            temp = data[i];
            j = i - gap;
            while (j >= 0 && data[j] > temp)
            {
                data[j + gap] = data[j];
                j -= gap;
            }
            data[j + gap] = temp;
        }
#if 1
        fprintf(stdout, "第 %02d 步排序结果：", ++n);
        showArray(data, size);
#endif   
    }
}
 void SelectionSort(int *data, int size)
 {
     if (NULL == data || 1 >= size)
         return;
     int i, j;
     for (i = 0; i < size - 1; ++i)
     {
         for (j = i + 1; j < size; ++j)
         {
             if (data[i] > data[j])
                 Swap(&data[i], &data[j]);
         }
#if 1
        fprintf(stdout, "第 %02d 步排序结果：", i + 1);
        showArray(data, size);
#endif 
     }
}
void MaxTopHeap(int *data, int start, int end)
{
    if (NULL == data || start >= end)
        return;
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)
    { //若子节点指标在范围内才做比较
        if (son + 1 <= end && data[son] < data[son + 1]) //先比较两个子节点大小，选择最大的
            son++;
        if (data[dad] > data[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
        {
             return;
        }
        else
        { //否则交换父子内容再继续子节点和孙节点比较
            Swap(&data[dad], &data[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
 void HeapSort(int *data, int size)
{
    if (NULL == data || 1 >= size)
        return;
    int i;
    //初始化，i从最後一个父节点开始调整
    for (i = size / 2 - 1; i >= 0; i--)
        MaxTopHeap(data, i, size - 1);
    //先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
    for (i = size - 1; i > 0; i--)
    {
        Swap(&data[0], &data[i]);
#if 1
        fprintf(stdout, "元素交換：");
        showArray(data, size);
#endif
        MaxTopHeap(data, 0, i - 1);
#if 1
        fprintf(stdout, "  調整堆：");
        showArray(data, size);
#endif
    }
 }
void Merge(int *data,int size,int gap)
{
    int *brr = (int *) malloc(sizeof (int) * size);
    if (NULL == brr) return;
    int i = 0; //brr的下标
    int start1 = 0;
    int end1 = start1 + gap - 1;
    int start2 = end1 + 1;
    int end2 = start2 + gap - 1 < size - 1 ? start2 + gap - 1 : size - 1;

    while (start2 < size)
    {
        while (start1 <= end1 && start2 <= end2)
        {
            if (data[start1] <= data[start2])
            {
                brr[i++] = data[start1++];
            }
            else
            {
                brr[i++] = data[start2++];
            }
        }
        while (start1 <= end1)
        {
            brr[i++] = data[start1++];
        }

        while (start2 <= end2)
        {
            brr[i++] = data[start2++];
        }

        start1 = end2 + 1;
        end1 = start1 + gap - 1;
        start2 = end1 + 1;
        end2 = start2 + gap - 1 < size - 1 ? start2 + gap - 1 : size - 1;
    }
    while (start1 < size)
    {
        brr[i++] = data[start1++];
    }

    for (int i = 0; i < size; i++)
    {
        data[i] = brr[i];
    } 
    free(brr);
    brr = NULL;
}
void MergeSort(int *data,int size)
{
    if (NULL == data || 1 >= size)
        return;
    
    int i;
    int j = 0;
    for (i = 1; i < size; i *= 2)
    {
        Merge(data, size, i);
#if 1
        fprintf(stdout, "第 %02d 步排序结果：", ++j);
        showArray(data, size);
#endif 
    }
}
int MaxBit(int *data, int size)
{
    int d = 1; //保存最大的位数
    int p = 10;
    for (int i = 0; i < size; ++i)
    {
        while (data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void RadixSort(int *data, int size)
{
    if (NULL == data || 1 >= size)
        return;
    int d = MaxBit(data, size);
    //数组中的元素的最大位数
    int *tmp = (int *) malloc(size * sizeof (int));
    int *count = (int *) malloc(10 * sizeof (int));
    //计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++)
    {
        //进行d次排序
        for (j = 0; j < 10; j++)
            count[j] = 0;
        //每次分配前清空计数器
        for (j = 0; j < size; j++)
        {
            k = (data[j] / radix) % 10;
            //计算每次循环某一位的数字
            count[k]++;
            //统计每个桶中的记录数
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j];
        //第j个桶以及之前所有桶中元素的总数
        for (j = size - 1; j >= 0; j--)
        {
            //将所有桶中记录依次收集到tmp中
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;

        }
        for (j = 0; j < size; j++)//将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    free(tmp);
    free(count);
    tmp = NULL;
    count = NULL;
}