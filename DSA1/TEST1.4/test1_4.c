#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

void insert(char s[], char key, int index)
{
    int size_string = strlen(s);
    for (int i = size_string; i >= index; i--)
    {
        s[i + 1] = s[i];
    }
    s[index] = key;
}

int main()
{
    char s[MAX];
    fgets(s, MAX, stdin);
    s[strcspn(s, "\n")] = 0;
    char key;
    scanf(" %c", &key);
    int index;
    printf("Nhap vi tri can chen: ");
    scanf("%d", &index);
    insert(s, key, index);
    printf("Chuoi sau khi chen: %s\n", s);
    return 0;
}
