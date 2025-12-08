#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAX 255
void serialKey(char s[],int k)
{
    getchar();
    fgets(s,k+2,stdin);
    s[strcspn(s,"\n")]=0;
}
int Search(char s[MAX][MAX],int length,char target[])
{
    for(int i=0;i<length;i++)
    {
        if(strcmp(s[i],target)==0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
   char s[MAX][MAX];
    int n,k;
    printf("Nhap so luong chuoi: ");
    scanf("%d",&n);
    printf("Nhap do dai chuoi:");
    scanf("%d",&k);
    getchar();
    for(int i=0;i<n;i++)
    {
        printf("Nhap chuoi thu %d: ",i+1);
        serialKey(s[i],k);
    }
    char target[MAX];
    printf("Nhap chuoi can tim: ");
    serialKey(target,k);
    if(Search(s,n,target)!=-1)
    {
        printf("Chuoi o vi tri: %d",Search(s,n,target));
    }
    else
    {
        printf("Khong tim thay chuoi");
    }
} 
