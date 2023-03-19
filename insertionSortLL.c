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

struct Node* insertionSort(struct Node* head){
    struct Node* curr = head;
    struct Node* headSorted = NULL;
    while (curr) {
        struct Node* succ = curr->next;

        if (headSorted == NULL || headSorted->val >= curr->val) {   // just for 1st node inserted
            curr->next = headSorted;
            headSorted = curr;
        } else {
            struct Node* prev = headSorted; // the node after which curr will be inserted in sorted list
            while (prev->next && prev->next->val < curr->val) { // smth after prev exists and its value is less than curr's
                prev = prev->next;  // keep going
            }
            curr->next = prev->next;
            prev->next = curr;
        }

        curr = succ;
    }
    return headSorted;
}

void main(){
    struct Node* head = createList(10);
    traverseList(head);
    struct Node* sorted = insertionSort(head);    // returns head of sorted list
    traverseList(sorted);
}