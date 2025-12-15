#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 100

void initializeArray(float arr[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + ((float)rand() / RAND_MAX) * (max - min);
    }
}

int minIndex(float arr[], int start, int n, int *comparison)
{
    int min_idx = start;
    for (int i = start + 1; i < n; i++)
    {
        (*comparison)++;
        if (arr[i] < arr[min_idx])
        {
            min_idx = i;
        }
    }
    return min_idx;
}

void sortArray(float arr[], int n, int *comparison)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = minIndex(arr, i, n, comparison);
        if (idx != i)
        {
            float tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }
}

float comps_avg(int fre_comps[], int size, int k)
{
    float avg = 0;
    for (int i = 0; i < size; i++)
    {
        avg += fre_comps[i] * i;
    }
    return avg / k;
}

int main()
{
    srand((unsigned)time(NULL));

    int n = 40;
    float arr[MAX];
    int k[] = {100, 1000};

    for (int j = 0; j < 2; j++)
    {
        int fre_comparisons[1000] = {0};

        for (int i = 0; i < k[j]; i++)
        {
            int comparison = 0;
            initializeArray(arr, n, -2 * n, 2 * n);
            sortArray(arr, n, &comparison);
            fre_comparisons[comparison]++;
        }

        printf("%d\n", k[j]);
        printf("\nObservation        Comparison\n");
        for (int h = 0; h < 1000; h++)
        {
            if (fre_comparisons[h] > 0)
            {
                printf("%d                 %d\n", h, fre_comparisons[h]);
            }
        }

        printf("Average comparisons: %.2f\n",
               comps_avg(fre_comparisons, 1000, k[j]));
    }
}
//TA CO SO COMPARISON THEO N LA: (n^2 - n)/2
//VAY DO PHUC TAP THUAT TOAN THEO BIG O LA: O(n^2)

