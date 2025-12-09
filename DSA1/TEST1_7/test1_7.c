
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>
#define MAX 200
int convertIndex(char *s)
{
    char index[3];
    index[0]=s[0];
    index[1]=s[1];
    index[2]='\0';
    return atoi(index);
    
}



int main()
{
    int n,m;
    int idx;
    printf("nhap kich thuoc mang hien tai:");
    scanf("%d",&n);
   char arr[MAX][11];
   char string[11];
   bool check[MAX]={false};
   for(int i=0;i<n;i++)
   {
    scanf("%s",string);
    idx=convertIndex(string);
    strcpy(arr[idx],string);
    check[idx]=true;
   }
   printf("nhap so chuoi can chen vao mang:");
   scanf("%d",&m);
   for(int i=0;i<m;i++)
   {
    scanf("%s",string);
    idx=convertIndex(string);
    if(!check[idx])
    {
        strcpy(arr[idx],string);
        check[idx]=true;
    }
   }
   for(int i=0;i<m+n;i++)
   {
    if(check[i])
    {
        printf("%s\n",arr[i]);
    }
   }
}
