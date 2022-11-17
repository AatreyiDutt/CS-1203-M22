#include<stdio.h>
#include<stdlib.h>

struct Leaf{
	int val;
	struct Leaf* left;
	struct Leaf* right;
};

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


struct Leaf* createNew(int num){
  struct Leaf* new = (struct Leaf*)malloc(sizeof(struct Leaf));
  new->val = num;
  new->left = NULL;
  new->right = NULL;
  return new;
}

struct Leaf* recursiveBST(int arr[], int start, int end){
	if (start > end)
	return NULL;

	int mid = (start + end)/2; //middle element
	struct Leaf *root = createNew(arr[mid]);

	root->right = recursiveBST(arr, start, mid-1);
  root->left = recursiveBST(arr, mid+1, end);

	return root;
}

struct Leaf* arrayToReverseBST (int* a, int n){
	struct Leaf *root = recursiveBST(a, 0, n-1);
  return root;
}

void preOrder(struct Leaf* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->val);
	preOrder(node->left);
	preOrder(node->right);
}

void main(){
  static int arr[10]; // array creation
  for (int i=0; i<10; i++){
    arr[i] = rand()%100; // insert a random number from 0 to 99
  }
  int *arrs = insertionSort(arr, 10);
  struct Leaf* root = arrayToReverseBST(arrs, 10);
	preOrder(root);
}
