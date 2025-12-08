#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAX 255
int findChar(char s[],int length,char ch)
{
    for(int i=0;i<length;i++)
    {
       if(tolower(s[i])==tolower(ch))
       {
        return i;
       }
    }
    return -1;
}
int main()
{
    char s[MAX];
    printf("nhap chuoi:");
    fgets(s,MAX,stdin);
    int len=strlen(s);
    s[strcspn(s,"\n")]=0;
    char ch;
    printf("nhap ky tu can tim:");
    scanf("%c",&ch);
  printf("found %c at %d",ch,findChar(s,strlen(s),ch));
    return 0;
} 
