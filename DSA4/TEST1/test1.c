#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 200
typedef struct {
    float a,b,c;
} A;
float f_a(A x)
{
    return x.a-2*x.b+3*x.c;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bublesort(int arr[],int size_arr)
{
    for(int i=size_arr-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);

            }
        }
    }
}
void bublesortChar(char *s,int length)
{
    for(int i=length-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(tolower(s[j])>tolower(s[j+1]))
            {
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
void bublesortStruct(A arr[],int size_arr)
{
    for(int i=size_arr-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(f_a(arr[j])>f_a(arr[j+1]))
            {
                A temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
   int arr[MAX];
   int n;
   printf("cau 1.1\n");
   printf("nhap so phan tu mang:");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
    scanf("%d",&arr[i]);
   }
    bublesort(arr,n);
    printf("mang sau khi sap xep la:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\ncau 1.2\n");
    char s[MAX];
    printf("nhap chuoi:");
    scanf("%s",s);
    int length=strlen(s);
    bublesortChar(s,length);
    printf("chuoi sau khi sap xep la:\n");
    printf("%s\n",s);
    printf("cau 1.3\n");
    A arrA[MAX];    
    int m;
    printf("nhap so phan tu mang cau 1.3:");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        printf("nhap phan tu thu %d:\n",i+1);
        printf("a=");
        scanf("%f",&arrA[i].a);
        printf("b=");
        scanf("%f",&arrA[i].b);
        printf("c=");
        scanf("%f",&arrA[i].c);
    }
    bublesortStruct(arrA,m);
    printf("mang sau khi sap xep la:\n");
    for(int i=0;i<m;i++)
    {
        printf("a=%.2f b=%.2f c=%.2f\n",arrA[i].a,arrA[i].b,arrA[i].c);
    }
}
