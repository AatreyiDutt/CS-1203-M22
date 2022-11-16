// BST is the BEST

#include <stdio.h>
#include <stdlib.h>

struct Leaf {
  int val;
  struct Leaf* left;  //larger
  struct Leaf* right; //smaller
};

struct Leaf* sortBST(int a*, int start, int end){
  int midpos = (end-start)/2; // create mid Leaf
  struct Leaf* root = (struct Leaf*)malloc(sizeof(struct Leaf));
  root->val = a[midpos];  // assign value from array
  for (int i = 0; i<n; i++){  // for every next element check if greater/lesser and branch

  }
  if (start<end){
    
  } else {}
    return root;
  }
}

struct Leaf* arrayToReverseBST(int* a, int n){
  int end = n-1;
  int start = 0;
  root = sortBST(a, start, end);
}

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

void main(){
  static int a[10];
  for (int i=0; i<10; i++){
    a[i] = rand()%(99+1-1);
    printf("%d ", a[i]);
  }
  int* as = insertionSort(a);
  struct Leaf* root = arrayToReverseBST(as, 10);
}
