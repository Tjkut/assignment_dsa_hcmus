
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

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b, int *step)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    (*step)++;
}

/* ===== SẮP XẾP TĂNG DẦN (CÓ STEP) ===== */

void bubbleSort(int arr[], int n, int *step)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            (*step)++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1], step);
            }
        }
    }
}

void selectionSort(int arr[], int n, int *step)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            (*step)++;
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            swap(&arr[i], &arr[min], step);
    }
}

void insertionSort(int arr[], int n, int *step)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            (*step)++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                (*step)++;
                j--;
            }
            else
                break;
        }
        arr[j + 1] = key;
        (*step)++;
    }
}

/* ===== SẮP XẾP GIẢM DẦN (KHÔNG STEP) ===== */

void bubbleSortDesc(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

void selectionSortDesc(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[max])
                max = j;

        if (max != i)
        {
            int t = arr[i];
            arr[i] = arr[max];
            arr[max] = t;
        }
    }
}

void insertionSortDesc(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int a[10] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int n = 10;

    int a2[10], a3[10];
    for (int i = 0; i < n; i++)
    {
        a2[i] = a[i];
        a3[i] = a[i];
    }

    int step1 = 0, step2 = 0, step3 = 0;

    bubbleSort(a, n, &step1);
    selectionSort(a2, n, &step2);
    insertionSort(a3, n, &step3);

    printf("Cau 1.1 - Sap xep tang dan:\n");
    printf("So step cua BubbleSort: %d\n", step1);
    printf("So step cua SelectionSort: %d\n", step2);
    printf("So step cua InsertionSort: %d\n", step3);

    printf("Cau 2 - Sap xep giam dan:\n");
    initializeArray(a, n, 0, 100);
    printArray(a,n);
    initializeArray(a2, n, 0, 100);
    printArray(a2,n);
    initializeArray(a3, n, 0, 100);
    printArray(a3,n);

    printf("Sau khi sap xep giam dan:\n");
    bubbleSortDesc(a, n);
    printArray(a,n);
    selectionSortDesc(a2, n);
    printArray(a2,n);
    insertionSortDesc(a3, n);
    printArray(a3,n);
    //  BubbleSort: đổi điều kiện so sánh để phần tử lớn được đẩy lên trước, tạo thứ tự giảm dần.
// SelectionSort: thay vì chọn giá trị nhỏ nhất, ta tìm giá trị lớn nhất và đưa về đầu mảng.
// InsertionSort: khi chèn phần tử mới, dịch các phần tử nhỏ hơn sang phải để giữ thứ tự giảm.
printf("Cau 3\n");
int arr[MAX],brr[MAX],crr[MAX];
int k[]={10,20,50,100};
for(int i=0;i<4;i++)
{
    printf("%d\n",k[i]);
    initializeArray(arr,k[i],-100,100);
    initializeArray(brr,k[i],-100,100);
    initializeArray(crr,k[i],-100,100);
    step1=0;
    bubbleSort(arr ,k[i],&step1);
    step2=0;
    selectionSort(brr,k[i],&step2);
    step3=0;
    insertionSort(crr,k[i],&step3);
    printf("So step cua BubbleSort: %d\n", step1);
    printf("So step cua SelectionSort: %d\n", step2);
    printf("So step cua InsertionSort: %d\n", step3);
}
//Giong nhau
//n tăng từ 10 → 100, số step đều tăng theo bậc hai
//3 thuat toan deu co do phuc tap thoi gian la O(n^2)
//khac nhau
//so step cua BubbleSort luon lon hon so step cua SelectionSort va InsertionSort
//so step cua InsertionSort khá tương đồng so với SelectionSort
    return 0;
}

