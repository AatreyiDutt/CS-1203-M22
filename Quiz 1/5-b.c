// Sort of OK

#include <stdio.h>
#include <stdlib.h>

int* insertionSort(int * arr, int size){
  int i, item, j;
  for (i = 1; i < size; i++) {
      item = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > item) {
          arr[j+1] = arr[j];
          j--;
      }
      arr[j+1] = item;
  }
  return arr;
}

void traverseList(int* arr){
  int i = 0;
  while (arr[i]){
    printf("%d ", arr[i]);
    i++;
  }
  printf("\n");
}

void kSmallestAmongUntouched(int *a, int k, int n){
  int i = 0;
  while (a[i]){
    a[i] = -1;  // flag every 3rd element
    i+=3;
  }
  traverseList(a);
  static int b[10];
  int bpos = 0;
  for (int pos=0; pos<n; pos++){
    if (a[pos]>-1){
      b[bpos] = a[pos];
      bpos++;
    }
  }
  int* bs = insertionSort(b, bpos);
  for (int c=0; c<k; c++){
    if (bs[c]){
      printf("%d ", bs[c]);
    }
  }
}

void main(){
  static int a[10];
  for (int i=0; i<10; i++){
    a[i] = rand()%99;
  }
  traverseList(a);
  int k = rand()%(10+1-1)+1; // generate random number from 1 to 10
  printf("%d\n", k);
  kSmallestAmongUntouched(a, k, 10);
}
