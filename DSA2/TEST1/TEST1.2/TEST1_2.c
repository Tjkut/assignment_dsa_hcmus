#include <stdlib.h>
#include <stdio.h>
#define MAX 100

int orderedLinearSearch(float arr[], int size, float value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
        else if (arr[i] > value)
        {
            return -1;
        }
    }
    return -1
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
    int index = orderedLinearSearch(arr, n, value);
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
