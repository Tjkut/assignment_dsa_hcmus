//ascending letter interger
#include <stdio.h>
#include <stdbool.h>
bool ascending(int n,int *comparsion){
    (*comparsion)=0;
    if(n<9){
        return true;
    }
  do{
    int last_digit = n % 10;
    n/=10;
    int current_digit = n % 10;
    (*comparsion)++;
    if(last_digit<current_digit){
        return false;
    }
  }
  while(n>9);
  return true; 
}
int main() {
   int sum_compare=0;
    int comparsion=0;
    for(int i=1000;i<=9999;i++)
    {
        ascending(i,&comparsion);
        sum_compare+=comparsion;
    }
    float mean_comparsion=(sum_compare*1.0)/(9999-1000+1);
    printf("Mean comparsion:%.2f",mean_comparsion);
  
    return 0;
}
