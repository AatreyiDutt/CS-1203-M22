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

  int m = 0;
  while (m<n){  // for next
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  //new node
    temp->val = a[m];
    temp->next = NULL;
    temp->nextk = NULL;

    if (prev == head){
      head->next = temp;
    } else {
      prev->next = temp;
    }
    prev = temp;
    m++;
  }

  int j = 0;  // for List
  struct Node* curr = head;
  struct Node* tempo = curr;
  while(j<n){
    curr->k = rand()%(5+1-2)+2;
    int nk = curr->k;
    int c = 0;

    if (curr==head){
      while(c<nk){
        tempo = tempo->next;
        printf("at %d c is %d of %d\n", j, c, nk);
        c++;
      }
      head->nextk = tempo;
      curr = head->next;
      tempo = curr;
    } else {
      while (c<nk && tempo){
        tempo = tempo->next;
        printf("at %d c is %d of %d\n", j, c, nk);
        c++;
      }
      curr = curr->next;
      tempo = curr;
    }
    j++;
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
