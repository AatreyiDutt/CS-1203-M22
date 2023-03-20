#include <stdio.h>
#include <stdlib.h>

struct Node {
    char val;
    struct Node* next;
    struct Node* express;
};

struct Node* createList(int n){ //creates a linked list of numbers 0 to n
    int i = 65;   // start at ascii value A
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));

    head->val = 65;
    head->next = NULL;
    i++;
    struct Node* prev = head;

    while (i<65+n){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  //new node
        temp->val = i;  //new node value is next letter
        temp->next = NULL;  //new node points to NULL
        temp->express = NULL;   // express ptr of all nodes are NULL
        prev->next = temp;  //previous node points to new node
        prev = temp;  //new node is now the previous node
        i++;
    }

    return head;  //return starting pointer of list
}

void createExp(struct Node* head){
    struct Node* exp = head;
    struct Node* prec = head;
    int skip = 3;
    while(prec){
        printf("%c-->", prec->val);
        for(int j=0; j<skip; j++){
            if(exp){
                exp = exp->next;
            }
        }
        
        prec->express = exp;
        prec = exp;   // code is breaking here
    }

}

void traverseList(struct Node* head){
    struct Node* curr = head;
    while (curr){
        printf("%c -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL"); // end of list
}

void traverseExp(struct Node* head){
    struct Node* curr = head;
    while (curr){
        printf("%c ---> ", curr->val);
        curr = curr->express;
    }
    printf("NULL"); // end of list
}

void main(){
    struct Node* list = createList(10);  //create a linked list of 0 to 4
    traverseList(list);
    printf("\n");
    createExp(list);
    traverseExp(list);
}