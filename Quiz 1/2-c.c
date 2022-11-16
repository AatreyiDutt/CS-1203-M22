#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node* next;
  int k;
  struct Node* nextk;
};

struct Node* arrayToLLWithNextk (int* a, int n){
  struct Node* head = (struct Node*)malloc(sizeof(struct Node));
  head->val = 0;  // empty node, just to point to start of list
  head->next = NULL;
  head->nextk = NULL;
  struct Node* prev = head;

  int i = 0;
  while (i<n){  // for next
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  //new node
    temp->val = a[i];
    temp->next = NULL;
    temp->nextk = NULL;

    if (prev == head){
      head->next = temp;
    } else {
      prev->next = temp;
    }
    prev = temp;
    i++;
  }

  i = 0;
  struct Node* curr = head; // current node, increments using next
  struct Node* temp = head; // current node's kth node, resets after every node's nextk is found
  while(i<n){  // for nextk
    curr->k = rand()%(5 + 1 - 2) + 2; // random number between 2 and 5
    printf("k is %d: ", curr->k);
    if (curr == head){
      int j=0;  // counter to loop findNext until k
      while(j<curr->k){
        temp = temp->next;  // finding head+k
        j++;
      }
      head->next = temp;
      // printf("%d, ", temp->val);
      curr = head->next;
      temp = curr;
    }
    else {
      int flag = 0; //checking for null
      int j = 0;
      while(j<curr->k && flag==0){
        temp = temp->next;  // finding head+k
        if (temp==NULL){ // if curr is NULL
          curr->nextk = NULL;
          flag++;
        }
        j++;
      }
      //printf("%d, ", temp->val);
      if (flag!=0){
        curr->nextk = temp;
      }
      curr = curr->next;
      temp = curr;
    }
    printf("(i is %d) ", i);
    i++;
    printf("\n");
  }
  return head;
}

void traverseListk(struct Node* head){
  struct Node* curr = head->nextk;
  printf("%d\n", curr->val);
  while (curr){
    printf("%d -> ", curr->val);
    curr = curr->nextk;
  }
  printf("NULL \n"); // end of list
}

void main(){
  static int a[10];
  for (int i=0; i<10; i++){
    a[i] = i;
    printf("%d ", a[i]);
  }
  printf("\n");
  struct Node* head = arrayToLLWithNextk(a, 10);
  traverseListk(head);
}
