#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void initializeArray(int arr[], int n, int min, int max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}
void swap(int *a, int *b, int *step)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    (*step)++;
}

void bubbleSort(int arr[], int n, int *step)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1], step);
            }
        }
    }
}
void Method1(int arr[], int *n, int *step1)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            (*step1)++;
            if (arr[j] == arr[i])
            {
                for (int k = j; k < *n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                    (*step1)++;
                }
                (*n)--;
                j--; //
            }
        }
    }
}
void Method2(int arr[], int *n, int *step2)
{
    bubbleSort(arr, *n, step2);

    for (int i = 0; i < *n - 1; i++)
    {
        (*step2)++; // comparison
        if (arr[i] == arr[i + 1])
        {
            for (int k = i; k < *n - 1; k++)
            {
                arr[k] = arr[k + 1];
                (*step2)++; // assignment
            }
            (*n)--;
            i--; 
        }
    }
}
int main()
{
    srand(time(NULL));

    int step1_sum = 0;
    int step2_sum = 0;

    for (int t = 0; t < 10; t++)
    {
        int a1[10], a2[10];
        int n1 = 10, n2 = 10;
        int step1 = 0, step2 = 0;

        // sinh mảng [-100, 100]
        initializeArray(a1, 10, -100, 100);

        // copy mảng
        for (int i = 0; i < 10; i++)
            a2[i] = a1[i];

        Method1(a1, &n1, &step1);
        Method2(a2, &n2, &step2);

        step1_sum += step1;
        step2_sum += step2;
    }

    printf("Step trung binh Method 1: %.2f\n", (float)step1_sum / 10);
    printf("Step trung binh Method 2: %.2f\n", (float)step2_sum / 10);
    printf("Dua vao so step, Method 2 hieu qua hon Method 1\n");
    printf("Vi Method 2 sap xep truoc khi xoa trung, giam so lan dich chuyen va so lan so sanh\n");


    return 0;
}


