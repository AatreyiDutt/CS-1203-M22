#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;  //value of node
  struct Node* next;  //pointer to next node
};

void createList(int n){ //creates a linked list of numbers 0 to n
  int i = 0;
  struct Node* head = (struct Node*)malloc(sizeof(struct Node));

  head->val = i;
  head->next = NULL;
  i++;
  struct Node* prev = head;

  while (i<n){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  //new node
    temp->val = i;  //new node value
    temp->next = NULL;  //new node points to NULL
    prev->next = temp;  //previous node points to new node
    prev = temp;  //new node is now the previous node
    i++;
  }

  // traversal
  struct Node* curr = head;
  while (curr){
    printf("%d -> ", curr->val);
    curr = curr->next;
  }
  printf("NULL"); // end of list
}

int main(){
  createList(5);  //create a linked list of 0 to 4
  return 0;
}
