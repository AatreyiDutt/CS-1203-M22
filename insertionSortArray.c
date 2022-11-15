#include <stdio.h>
#include <stdlib.h>

int* createArray(){
  static int arr[10];
  int i;
  for (i=0; i<10; i++){
    arr[i] = rand()%100; // insert a random number from 0 to 99
  }
  // print Array
  return arr;
}

int insertionSort(int arr[]){
  return 0;
}


void main(){
  int a;
  int *arr = createArray();
  for (a=0; a<sizeof(arr); a++){
    printf("%d ", arr[a]);
  }
}
