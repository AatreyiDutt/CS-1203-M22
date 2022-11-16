// Fizzbuzz

#include <stdio.h>
#include <stdlib.h>

void basicFizzBuzz(int x){
  //3,5 Fizz
  //11, 13 buzz
  //33,39,55,65 Fizzbuzz
  int flag = 0;
  if (x%3==0 || x%5==0){
    printf("fizz");
    flag++;
  }
  if (x%11==0 || x%13==0){
    printf("buzz");
    flag++;
  }
  if (flag == 0){
    printf("%d", x);
  }
  printf("\n");
}

void main(){
  printf("Enter integer: ");
  int x;
  scanf("%d", &x);
  basicFizzBuzz(x);
}
