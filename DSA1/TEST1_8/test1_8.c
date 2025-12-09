#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>
#define MAX 200
void delectChar(char *s,int index)
{
     int len = strlen(s);

    if (index < 0 || index >= len) return; // vị trí không hợp lệ

    for (int i = index; i < len; i++)
    {
        s[i] = s[i + 1];
    }
}



int main()
{
   char s[MAX];
   int index;
   printf("nhap chuoi:");
   fgets(s,MAX,stdin);
   printf("nhap vi tri can xoa:");
   scanf("%d",&index);
   delectChar(s,index);
   printf("chuoi sau khi xoa:%s",s);
   printf("%s",s);
}
