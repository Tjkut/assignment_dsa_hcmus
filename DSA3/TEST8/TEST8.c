//ascending letter interger
#include <stdio.h>
#include <stdbool.h>
//them bien shift va assignment vao trong ham
void f(int a[], int n, int *shift, int *assignment) {
    *shift = 0;
    *assignment = 0;

    for (int d = n / 2; d > 0; d /= 2) {
        for (int i = d; i < n; i++) {
            int t = a[i];   
            int j;

            for (j = i; j >= d && a[j - d] > t; j -= d) {
                a[j] = a[j - d]; 
                (*shift)++;
            }

            a[j] = t;             
            (*assignment)++;
        }
    }
}
int main()
{
    
  int a[] = {34, 29, 10, 3, 2, 44, 88, 1, 21, 12, 3, 18, 21, 23, 37, 17, 8, 9, 4, 0};
  int n = 20;
  int assignment=0,shift=0;
  f(a,n,&shift,&assignment);
  printf("shift:%d assignment:%d",shift,assignment);
  return 0;



}

