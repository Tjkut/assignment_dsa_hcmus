#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void initializeArray(int *arr, int size_arr, int min, int max)
{
    for (int i = 0; i < size_arr; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}
int sumNegative(int *arr,int size_arr,int *assignment)
{
    *assignment=0;
    int sum=0;
    for(int i=0;i<size_arr;i++)
    {
        if(arr[i]<0)
        {
            sum+=arr[i];
            (*assignment)++;
        }
    }
    return sum;
}
int main()
{
      time_t t;
    srand((unsigned)time(&t));
    int arr[10];
    int k=1000;
    int assignment=0;
    int fre_assignment[11]={0};
    for(int i=0;i<k;i++)
    {
        initializeArray(arr,10,-100,100);
        sumNegative(arr,10,&assignment);
        fre_assignment[assignment]++;
    }
    printf("\nObservation   assignments     \n");
    for (int h = 0; h <= 10; h++)
    {
        printf("%d: %15d  \n", h, fre_assignment[h]);
    }
}
