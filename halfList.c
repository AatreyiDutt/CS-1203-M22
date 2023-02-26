#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;  //value of node
  struct Node* next;  //pointer to next node
};

struct Node* createList(int n){ //creates a linked list of numbers 0 to n
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
  return head;  //return starting pointer of list
}

// uptil here, code is from linkedList.c

void half(struct Node* head){
    struct Node* curr = head;   // current
    struct Node* dub = head;    // double of curr ptr
    int count = 0;  // to keep track of num of current node
    while (dub->next){  // while next of double node is not NULL
        dub = curr;
        printf("%d -> ", curr->val);
        count +=1;
        for (int i=0; i<count; i++){    // for nth node go n nodes ahead
            dub = dub->next;
        }
        curr = curr->next;
        
    }
}

int main(){
  struct Node* list = createList(10);  //create a linked list of 0 to 9
  half(list);
  return 0;
}
