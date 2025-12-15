#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 10000

void initializeArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
}

void bubbleSort(int arr[], int n, int *comparison)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            (*comparison)++;
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

float comps_avg(int fre[], int size, int k)
{
    float avg = 0;
    for (int i = 0; i < size; i++)
        avg += fre[i] * i;
    return avg / k;
}

int main()
{
    srand((unsigned)time(NULL));

    int n = 10;
    int arr[MAX];
    int k[] = {10, 20, 50, 100, 1000, 10000};

    for (int t = 0; t < 6; t++)
    {
        int fre_comps[100] = {0};

        for (int i = 0; i < k[t]; i++)
        {
            initializeArray(arr, n);
            int comparison = 0;
            bubbleSort(arr, n, &comparison);
            fre_comps[comparison]++;
        }

        printf("So lan chay\n");
        printf("%d\n", k[t]);
        printf("Observation        Comparison\n");
        for (int h = 0; h < 100; h++)
        {
            if (fre_comps[h] > 0)
                printf("%d                 %d\n", h, fre_comps[h]);
        }

        printf("Average comparisons: %.2f\n",
               comps_avg(fre_comps, 100, k[t]));
    }
    //cau b
      int l = 1000; // số lần sinh mảng (giống yêu cầu b)
    int n_values[] = {10,20,30,40,50,60,70,80,90,100};

    for (int t = 0; t < 10; t++)
    {
        int n = n_values[t];
        int fre_comps[MAX] = {0};

        for (int i = 0; i < l; i++)
        {
            initializeArray(arr, n);
            int comparison = 0;
            bubbleSort(arr, n, &comparison);
            fre_comps[comparison]++;
        }

         printf("kich thuoc mang\n");
        printf("\nn = %d\n", n);
        printf("Observation        Comparison\n");
        for (int h = 0; h < MAX; h++)
        {
            if (fre_comps[h] > 0)
                printf("%d                 %d\n", h, fre_comps[h]);
        }

        printf("Average comparisons: %.2f\n",
               comps_avg(fre_comps, MAX, l));
    }

}

