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
void deleteArr(int arr[], int *size_arr, int pos)
{
    if (pos < 0 || pos >= *size_arr)
    {
        printf("Vi tri xoa khong hop le.\n");
        return;
    }
    for (int i = pos; i < *size_arr - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size_arr)--;
}
void sortArr(int arr[], int size_arr)
{
    for (int i = 0; i < size_arr - 1; i++)
    {
        for (int j = i + 1; j < size_arr; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void CaseA(int arr[],int *size_arr,int k)
{
    for(int i=0;i<(*size_arr);i++)
    {
        if(arr[i]>=k)
        {
            deleteArr(arr,size_arr,i);
            i--;
        }
    }
}
void CaseB(int arr[],int *size_arr,int k)
{
    sortArr(arr,*size_arr);
  int i=*size_arr-1;
  while(arr[i]>k&&i>=0)
  {
      deleteArr(arr,size_arr,i);
      i--;
  }
}
int main()
{
   time_t t;
    srand((unsigned)time(&t));
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d",&n);
    int n_original=n;
    int arr[MAX];
    initializeArray(arr,n,1998,2023);
    printf("Mang ban dau:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    int k=2016;
    CaseA(arr,&n,k);
    printf("\nMang sau khi xoa phan tu lon hon %d (Case A):\n",k);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    n=n_original;
    initializeArray(arr,n,1998,2023);
    printf("\n\nMang ban dau:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    CaseB(arr,&n,k);
    printf("\n\nMang sau khi xoa phan tu lon hon %d (Case B):\n",k);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
// Dựa trên tiêu chuẩn đếm số phép so sánh và số phép dịch chuyển phần tử, thuật toán Case B được đánh giá là tốt hơn. Sau khi sắp xếp, các phần tử lớn hơn 

//k nằm ở cuối mảng nên việc xóa chỉ cần thực hiện ở cuối, làm giảm số phép so sánh và dịch chuyển. Trong khi đó, Case A phải duyệt toàn bộ mảng và dồn phần tử nhiều lần nên kém hiệu quả hơn.
}

