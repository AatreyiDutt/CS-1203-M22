#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;  //value of node
    struct Node* next;  //pointer to next node
};

struct Node* createList(int n){ //creates a linked list of numbers 0 to n
    int i = 0;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));

    head->val = rand() % 99;
    head->next = NULL;
    i++;
    struct Node* prev = head;

    while (i<n){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  //new node
        temp->val = rand() % 99;  //new node value
        temp->next = NULL;  //new node points to NULL
        prev->next = temp;  //previous node points to new node
        prev = temp;  //new node is now the previous node
        i++;
    }
    return head;  //return starting pointer of list
}

void traverseList(struct Node* head){
    struct Node* curr = head;
    while (curr){
        printf("%d -> ", curr->val);
        curr = curr->next;
  }
  printf("NULL\n");
}

struct Node* selectionSort (struct Node* head){
    struct Node* curr = head; // head of unsorted part
    struct Node* min;
    struct Node* check; // just to traverse to look for min in unsorted sublist
    while(curr){
        min = curr; // ref point for rest of array
        check = curr->next;
        while(check){
            if (check->val < min->val){
                min = check;            
            } check = check->next;
        }   // now we have min
        int temp = curr->val;   // swap values of current node and min node
        curr->val = min->val;
        min->val = temp;
        curr = curr->next;  // update unsorted part
    } return head;
}

void main(){
    struct Node* head = createList(10); // head of entire list
    traverseList(head);
    head = selectionSort(head);
    traverseList(head);
}