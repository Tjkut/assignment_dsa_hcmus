#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000
void Insert(float arr[], float value, int index, int *n)
{
    for (int i = *n; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value; // Chèn giá trị
    (*n)++;             // Tăng kích thước
}

void insertArray(float arr[], float num[], int index[], int *size_arr, int size_num)
{
    for (int i = 0; i < size_num; i++)
    {
        Insert(arr, num[i], index[i], size_arr);
    }
}

int main()
{
    int n;
    printf("nhap kich thuoc mang:");
    scanf("%d", &n);
    float arr[MAX];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    int m;
    printf("nhap so phan tu can chen:");
    scanf("%d", &m);
    float num[m];
    int index[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%f%d", &num[i], &index[i]);
    }
  insertArray(arr, num, index, &n, m);
    printf("mang sau khi chen:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
}
