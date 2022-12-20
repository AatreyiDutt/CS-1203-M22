#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* arr, int n){
    int a, b, mini, temp; // a = ref element, b = elements for comparing to a, mini = index of min element, temp = swap
    for (a=0; a<n-1; a++){  // a from 0 to 2nd last element
        mini = a;
        for (b = a+1; b<n; b++){
            if (arr[b] < arr[mini]){    // if num at b is smaller than num at mini
                mini = b;   // b holds the min
            }
            if (mini!=a){   // if ref element a is not the minimum
                temp = arr[mini];    // swap
                arr[mini] = arr[a];
                arr[a] = temp;
            }
        }
    }
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
  selectionSort(arr, s);
  traverseList(arr);
}
