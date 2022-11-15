// Fizzbuzz

#include <stdio.h>
#include <stdlib.h>

void basicFizzBuzz(int x){
  //3,5 Fizz
  //11, 13 buzz
  //33,39,55,65 Fizzbuzz
  if (x%33==0 || x%39==0 || x%55==0 || x%65==0){
    printf("fizzbuzz\n");
  } else if (x%11==0 || x%13==0){
    printf("buzz\n");
  } else if (x%3==0 || x%5==0){
    printf("fizz\n");
  } else {
    printf("%d\n", x);
  }
}

void main(){
  printf("Enter integer: ");
  int x;
  scanf("%d", &x);
  basicFizzBuzz(x);
}
