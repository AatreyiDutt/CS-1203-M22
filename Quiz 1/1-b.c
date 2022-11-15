// Fizzbuzz

#include <stdio.h>
#include <stdlib.h>

void advancedFizzBuzz(int* a, int m, int* f, int nf, int* b, int nb){
  int flag;
  for (int i=0; i<m; i++){
    flag = 0;
    for (int j=0; j<nf; j++){
      if (a[i]%f[j]==0 || a[i]%f[j]==0){
        printf("fizz");
        flag++;
        break;  // if a[i] is divisible by any element in f, exit
      }
    }
    for (int k=0; k<nb; k++){
      if (a[i]%b[k]==0 || a[i]%b[k]==0){
        printf("buzz");
        flag++;
        break;  // if a[i] is divisible by any element in b, exit
      }
    }
    if (flag == 0){   // not divisble by anything in f or b
      printf("%d",a[i]);
    }
    printf(" ");  // to tell elements apart
  }
}

void main(){
  int m = 10;
  static int a[10];
  for (int i=0; i<m; i++){
    a[i] = rand()%(99 + 1 - 1) + 1; //random numbers from 1 to 99
    printf("%d ", a[i]);
  }
  printf("\n");
  static int f[] = {2, 3};
  int nf = sizeof(f)/sizeof(f[0]);
  static int b[] = {7, 11};
  int nb = sizeof(b)/sizeof(b[0]);

  advancedFizzBuzz(a, m, f, nf, b, nb);
}
