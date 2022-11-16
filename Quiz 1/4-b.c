// Heaps of Fun

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void returnSmallestNum (int* maxHeap, int n){
  // let the height of the maxHeap be h, calculated as log2(n+1)
  // then the number of leaves in the ith row is 2^i AT MAX
  // the smallest number will be in this last row of leaves
  //  since this is a max heap
  int h = log(n+1)/log(2);
  int i = pow(2, h-1);

  int lastRow[i]; //last row of elements
  for (int a=0; a<i; a++){
    lastRow[a] = maxHeap[n-a-1];
  }
  int* sorted = insertionSort(lastRow, i);
  printf("%d\n", sorted[0]);
}

void main(){
  int maxHeap[] = {10, 8, 9, 6, 4, 7, 3, 2, 1};  // priority queue
  int n = sizeof(maxHeap)/sizeof(maxHeap[0]);
  returnSmallestNum(maxHeap, n);
}
