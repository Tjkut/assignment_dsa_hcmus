#include <stdlib.h>
#include <stdio.h>
#define MAX 100
int binarySearch(float arr[], int size, float value)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    float arr[MAX];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    float value;
    scanf("%f", &value);
    int index = binarySearch(arr, n, value);
    if (index != -1)
    {
        printf(" %d\n", index);
    }
    else
    {
        printf("Not found\n");
        return 0;
    }
}
