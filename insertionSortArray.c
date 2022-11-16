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
  for (int a=0; a<10; a++){
    printf("%d ", arr[a]);
  }
  printf("\n");
}

void main(){
  static int arr[10]; // array creation
  for (int i=0; i<10; i++){
    arr[i] = rand()%100; // insert a random number from 0 to 99
  }
  size_t s = sizeof(arr)/sizeof(arr[0]);
  traverseList(arr);
  int *arrs = insertionSort(arr, s);
  traverseList(arrs);
}
