#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int isAccending(char *s, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (s[i+1] < s[i])
        {
           
            return -1;
        }
    }
   return 1;
}
int linearSearch(char *s, int length, char value)
{
    for (int i = 0; i < length; i++)
    {
        if (s[i] == value)
        {
            return i;
        }
    }
    return -1;
}
int BinarySearch(char *s, int length, char value)
{
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (s[mid] == value)
        {
            return mid;
        }
        else if (s[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    char s[MAX];
    printf("Nhap chuoi: ");
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = 0; // Remove trailing newline character
    int length = strlen(s);
    if (isAccending(s, length) == 1)
    {
        printf("Chuoi tang dan\n");
        printf("Nhap ky tu can tim: ");
        char value;
        scanf(" %c", &value);
        int index = linearSearch(s, length, value);
        int index2 = BinarySearch(s, length, value);
        if (index != -1)
        {
            printf("Ky tu %c o vi tri %d\n", value, index);
            printf("Find by linear search\n");
        }
        else
        {
            printf("Khong tim thay ky tu %c\n", value);
        }
        if(index2 != -1)
        {
            printf("Ky tu %c o vi tri %d \n", value, index2);
            printf("Find by binary search\n");
        }
        else
        {
            printf("Khong tim thay ky tu %c\n", value);
        }

    }
    else
    {
        printf("Chuoi khong tang dan\n");
    }
    return 0;
  
}
