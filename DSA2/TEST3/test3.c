#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100


int main()
{
    char s[]="bcdefghijklmnopqrstuvwxyz";
    int mark[26]={0};
    for(int i=0;i<strlen(s);i++){
        mark[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(mark[i]==0){
            printf("%c at %d is missing",i+'a',i);
            break;
        }
    }
//dung mang danh dau de luu cac ky tu da xuat hien
// sau do duyet qua mang danh dau de tim ky tu dau tien khong xuat hien
    return 0;
  
}
