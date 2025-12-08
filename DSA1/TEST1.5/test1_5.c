#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000
void serialKey(char s[], int m)
{
    fgets(s, m + 2, stdin);
    s[strcspn(s, "\n")] = 0;
}
void insertString(char arr[][MAX], int *n, int index, char string[])
{
    for (int i = *n; i > index; i--)
    {
        strcpy(arr[i], arr[i - 1]);
    }
    strcpy(arr[index], string);
    (*n)++; // Tăng kích thước mảng
}

int main()
{
    char arr_string[MAX][MAX];
    int n, m;
    printf("Nhap kich thuoc mang:");
    scanf("%d", &n);
    printf("Nhap do dai chuoi can nhap:");
    scanf("%d", &m);
    getchar(); // 
    for (int i = 0; i < n; i++)
    {
        serialKey(arr_string[i], m);
    }
    int index;
    printf("vi tri can chen:");
    scanf("%d", &index);
    getchar(); 
    char string[MAX];
    serialKey(string, m);
    insertString(arr_string, &n, index, string);
    printf("Mang sau khi chen:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr_string[i]);
    }
}
