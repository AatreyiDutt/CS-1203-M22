#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode (int data){
    struct Node* leaf = (struct Node*)malloc(sizeof(struct Node));
    leaf->val = data;
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
}

void insertLeaf (struct Node* leaf, int data){
    if (leaf==NULL){    // if nothing at leaf
        leaf = createNode(data);
    } else {
        if (data<leaf->val){
            insertLeaf(leaf->left, data);   // left children are less than parent
        } else {
            insertLeaf(leaf->right, data);  // right children are greater than/equal to parent
        }
    }
}

void inOrder (struct Node* leaf){
    if (leaf){
        inOrder(leaf->left);
        printf("%d ", leaf->val);
        inOrder(leaf->right);
    }
}

void main(){
    static int arr[10];
    struct Node* root = NULL; 
    arr[0] = rand() % 100;
    root = createNode(arr[0]);
    struct Node* leaf;
    for (int i=1;i<10;i++){
        arr[i] = rand() % 100;  // array of random integers
        printf("%d ", arr[i]);
        insertLeaf(root, arr[i]);
    }
    printf("\n");
    inOrder(root);
}