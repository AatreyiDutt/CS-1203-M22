#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node* next;
};


struct Node* createList(int n){ //creates a linked list of numbers 0 to n
  int i = 0;
  struct Node* head = (struct Node*)malloc(sizeof(struct Node));

  head->val = 0;  //empty node
  head->next = NULL;  //to keep track of start of list
  struct Node* prev = head;

  while (i<n){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  //new node
    temp->val = i;  //new node value
    temp->next = NULL;  //new node points to NULL

    if (prev == head){  //if this is the 1st node of the list
      head->next = temp;  //make head point to it
    } else {
      prev->next = temp;  //previous node points to new node
    }
    prev = temp;  //new node is now the previous node
    i++;
  }
  return head;  //return starting pointer of list
}


void traverseList(struct Node* head){
  struct Node* curr = head->next;
  while (curr){
    printf("%d -> ", curr->val);
    curr = curr->next;
  }
  printf("NULL \n"); // end of list
}


struct Node* reverseChunk(struct Node* head, int k){

  struct Node* prec = NULL; //preceding node
  struct Node* curr = head->next; //1st node of list
  struct Node* succ = NULL; //succeeding node

  int i;
  while (i<k){
    succ = curr->next;  //store ptr of curr
    curr->next = prec;  //make curr point to preceding node
    prec = curr;  //shift up prec
    curr = succ;  //shift up succ using saved value
  }
  head->next = prec;
}

int main(){
  struct Node* list = createList(5);  //create a linked list of 0 to 4
  traverseList(list);
  struct Node* rev = reverseChunk(list,2);
  traverseList(rev);
  return 0;
}
