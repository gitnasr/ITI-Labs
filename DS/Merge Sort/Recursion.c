// Merge Sort with Recursion
#include <stdio.h>
void MergeSort(int *arr, int start, int end);
void Merge(int *arr, int start, int end, int mid);
int main()
{
    int test[] = {
        -49, 4, 5, 8, 245, 1, 90, 3, 64, 6, 9, -1, 0, 23, 300};
    int n = sizeof(test) / sizeof(int);
    MergeSort(test, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        int ele = test[i];
        printf("%d,", ele);
    }

    return 0;
}

void MergeSort(int *arr, int start, int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, end, mid);
    }
}

void Merge(int *arr, int start, int end, int mid)
{
    int temp[100];
    int List1 = start;
    int List2 = mid + 1;
    int i = 0;

    while (List1 <= mid && List2 <= end)
    {
        if (arr[List1] < arr[List2])
        {
            temp[i] = arr[List1];
            List1++;
        }
        else
        {

            temp[i] = arr[List2];
            List2++;
        }

        i++;
    }

    while (List1 <= mid)
    {
        temp[i] = arr[List1];
        i++;
        List1++;
    }
    while (List2 <= end)
    {
        temp[i] = arr[List2];
        i++;
        List2++;
    }
    for (i = 0; i < end - start + 1; i++)
    {
        arr[start + i] = temp[i];
    }
}