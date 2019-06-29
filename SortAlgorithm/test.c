#include "sort.h"
//
void showArray(const int *data, int size)
{
    if (NULL == data)
        return;
    int i;
    for (i = 0; i < size; ++i)
    {
        if (size - 1 == i)
        {
            fprintf(stdout, "%d\n", data[i]);
        }
        else
        {
            fprintf(stdout, "%d ", data[i]);
        }
    }
}
void testFunc(FUNC f, const char *str, int *data, int size)
{
    if (NULL == f || NULL == str || NULL == data)
        return;
    int i;

    srand((unsigned int) time(NULL));
    for (i = 0; i < ARRAY_SIZE; ++i)
        data[i] = rand() % 100 + 1;
    
    fprintf(stdout, "排序前数据(%s):", str);
    showArray(data, size);
    f(data, size);
    fprintf(stdout, "排序后数据(%s):", str);
    showArray(data, size);
}
