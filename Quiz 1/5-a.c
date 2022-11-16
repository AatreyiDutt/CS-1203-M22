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

int* sortEveryThirdElement (int *a, int n){
  static int s[10];
  int spos = 0;
  int i = 0;
  while (a[i]){ // creating temp array of every 3rd element
    s[spos] = a[i];
    spos++;
    i+=3;
  }
  int * ss = insertionSort(s, spos);
  spos = i = 0;
  while (ss[spos]){
    a[i] = ss[spos];
    spos++;
    i+=3;
  }
  return a;
}

void main(){
  static int a[10];
  for (int i=0; i<10; i++){
    a[i] = rand()%99;
  }
  traverseList(a);
  int* as3 = sortEveryThirdElement(a, 10);
  traverseList(as3);
}
