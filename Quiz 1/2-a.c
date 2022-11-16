// Reversal of Fortune

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node* next;
  struct Node* next2;
};

struct Node* arrayToLLWithNext2 (int* a, int n){
  struct Node* head = (struct Node*)malloc(sizeof(struct Node));
  head->val = 0;  // empty node, just to point to start of list
  head->next = NULL;
  head->next2 = NULL;
  struct Node* prev = head;

  int i = 0;
  while (i<n){  // for next
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  //new node
    temp->val = a[i];
    temp->next = NULL;
    temp->next2 = NULL;

    if (prev == head){
      head->next = temp;
    } else {
      prev->next = temp;
    }
    prev = temp;
    i++;
  }
  struct Node* curr = head;
  while(curr->next->next){  // for next2
    if (curr == head){
      head->next2 = head->next->next;
    } else {
      curr->next2 = curr->next->next;
    }
    curr = curr->next;
  }
  return head;
}

void traverseList2(struct Node* head){
  struct Node* curr = head->next2;
  while (curr){
    printf("%d -> ", curr->val);
    curr = curr->next2;
  }
  printf("NULL \n"); // end of list
}

void traverseList(struct Node* head){
  struct Node* curr = head->next;
  while (curr){
    printf("%d -> ", curr->val);
    curr = curr->next;
  }
  printf("NULL \n"); // end of list
}

void main(){
  static int a[10];
  for (int i=0; i<10; i++){
    a[i] = i;
  }
  struct Node* head = arrayToLLWithNext2(a, 10);
  traverseList(head);
  traverseList2(head);
}
