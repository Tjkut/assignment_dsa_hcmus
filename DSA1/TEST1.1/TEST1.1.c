#include<stdio.h>
#include<math.h>
int findNearest(int *arr,int value,int size_arr)
{
    int index=0;
    int min_direction=abs(arr[0]-value);
    int direc_current;
    for(int i=1;i<size_arr;i++)
    {
        direc_current=abs(arr[i]-value);
        if(direc_current<min_direction)
        {
            min_direction=direc_current;
            index=i;
        }
    }
    return index;
}
int main()
{
    int arr[]={10,22,14,3,76,54,32};
    int size_arr=sizeof(arr)/sizeof(arr[0]);
    int value=20;
    int index=findNearest(arr,value,size_arr);
    printf("find %d at %d\n",arr[index],index);
    return 0;
}
//ouput
//find 22 at 1
