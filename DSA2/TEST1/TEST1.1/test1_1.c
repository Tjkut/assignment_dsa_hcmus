#include <stdlib.h>
#include <stdio.h>
#define MAX 100
int findIndex(float arr[],int size,float value)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]>=value)
        {
            return i;
        }
    }
}
void insertOrderedArray(float arr[],int *size,float value)
{
   int index=findIndex(arr,*size,value);
    (*size)++;
   for(int i=*size;i>index;i--)
   {
       arr[i]=arr[i-1];
   }
    arr[index]=value;
   
}
int main()
{
    float arr[MAX];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }
    float value;
    scanf("%f",&value);
    insertOrderedArray(arr,&n,value);
    for(int i=0;i<n;i++){
        printf("%.2f ",arr[i]);
    }
    return 0; 
}
