#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define MAX 100

void initializeArray(float arr[], int n, int min, int max){
    for(int i = 0; i < n; i++){
          arr[i] = min + ((float)rand() / RAND_MAX) * (max - min);
    }
}
int minIndex(float arr[], int n,int *comparison){
    int min_idx = 0;
    (*comparison) = 0;
    for(int i = 1; i < n; i++){
        (*comparison)++;
        if(arr[i] < arr[min_idx]){
            min_idx = i;
        }
    }
    return min_idx;
}
float comps_avg(int fre_comps[], int size_fre_comps, int k)
{
    float avg = 0;
    for (int i = 0; i < size_fre_comps; i++)
    {
        avg += fre_comps[i] * i;
    }
    avg = avg * 1.0 / k;
    return avg;
}
int main()
{
    int n = 10;
    float arr[MAX];
    int k[]={100,1000};
    int comparison = 0;
    int fre_comparisons[MAX] = {0};
    srand((unsigned)time(NULL));
    int fre_comparison[11] = {0};
    for(int j=0;j<2;j++)
    {
        memset(fre_comparisons,0,sizeof(fre_comparisons));
        for(int i=0;i<k[j];i++)
        {
            initializeArray(arr,n,-2*n,2*n);
            fre_comparisons[minIndex(arr,n,&comparison)]++;
        }
        printf("%d\n",k[j]);
        printf("\nObservation        Comparison\n");
        for(int h=0;h<=10;h++)
        {
            printf("%d                 %d\n",h,fre_comparisons[h]);
        }
        printf("Average comparisons: %.2f\n",comps_avg(fre_comparisons,MAX,k[j]));
    }
   
}
