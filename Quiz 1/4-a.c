// Heaps of Fun

#include <stdio.h>
#include <stdlib.h>

void thirdLargestNumber (int* maxHeap, int n){
  // the two leaves of the root of the heap are the 2nd and 3rd
  // largest numbers in the Heap
  int leftC = maxHeap[1];
  int rightC = maxHeap[2];
  if (leftC>rightC){
    printf("%d\n", rightC);
  } else {
    printf("%d\n", leftC);
  }
}

void main(){
  int maxHeap[] = {10, 8, 9, 6, 4, 7, 2, 1};  // priority queue
  int n = sizeof(maxHeap)/sizeof(maxHeap[0]);
  thirdLargestNumber(maxHeap, n);
}
