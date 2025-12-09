#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>
#define MAX 200
typedef struct Toado
{
    float x;
    float y;
} Toado;
 void input(Toado *p)
 {
    printf("nhap x:");
    scanf("%f",&p->x);
    printf("nhap y:");
    scanf("%f",&p->y);
 }
int delete(Toado arr[],int *n,Toado p)
{
    int index=-1;
    for(int i=0;i<*n;i++)
    {
        if(arr[i].x==p.x && arr[i].y==p.y)
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        printf("khong tim thay toa do can xoa");
        return -1;
    }
    for(int i=index;i<*n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    (*n)--;
    return index;
}

int main()
{
  
    Toado arr[MAX];
    int n;
    printf("nhap so luong toa do:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("toa do thu %d:\n",i+1);
        input(&arr[i]);
    }
    Toado p;
    printf("nhap toa do can xoa:\n");
    input(&p);
    int index=delete(arr,&n,p);
    printf("danh sach toa do sau khi xoa:\n");
    for(int i=0;i<n;i++)
    {
        printf("(%.2f,%.2f)\n",arr[i].x,arr[i].y);
    }
  if(index!=-1)
  {
    printf("toa do da xoa o vi tri thu %d\n",index);
  }
    return 0;
}
