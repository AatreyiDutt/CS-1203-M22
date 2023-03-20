#include <stdio.h>
#include <stdlib.h>

void swap(int* arr, int x, int y){  // swap xth and yth elements in array arr
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int* arr, int lo, int hi){
    int pivot = arr[hi];    // pivot default to last element in subarray
    int a = lo-1;   // a for elements bigger than pivot
    
    for (int b=lo; b<hi; b++){  // in subarray
        if(arr[b]<=pivot){  // if pivot is greater than element
            a++;
            swap(arr, a, b);    // swap with the bigger element
        }
    }
    swap(arr, a+1, hi); // swap pivot with bigger element
    return (a+1);   // new partition
}

void quickSort(int* arr, int lo, int hi){
    if (lo<hi){
        int p = partition(arr,lo,hi);   // partition index
        quickSort(arr,lo,p-1);  // left
        quickSort(arr,p+1,hi);  // right
    }
}

void traverseList(int* arr){
    for (int i=0; i<10; i++){
    printf("%d ", arr[i]);
    } printf("\n");
}

void main(){
    static int arr[10]; // array creation
    for (int i=0; i<10; i++){
        arr[i] = rand()%100; // insert a random number from 0 to 99
    }
    size_t s = sizeof(arr)/sizeof(arr[0]);
    traverseList(arr);
    quickSort(arr, 0, s-1);
    traverseList(arr);
}
