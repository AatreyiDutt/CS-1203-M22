#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;  //value of node
	struct Node* next;  //pointer to next node
};

struct Node* createList(int n){ //creates a linked list of n numbers
	int i = 0;
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));

	head->val = rand()%99;
	head->next = NULL;
	i++;
	struct Node* prev = head;

	while (i<n){
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  //new node
		temp->val = rand()%99;  //new node value
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
	printf("NULL"); // end of list
}

struct Node* partition(struct Node* head, struct Node* tail){
	struct Node* pivot = head;	// assuming pivot to be 1st element
	struct Node* lo = head;	// for traversal & comparison
	int temp = 0;	// for swapping
	while(lo && lo!=tail){
		if(lo->val < tail->val){	// if smth is greater than tail
			pivot = head;
			temp = head->val;	// swap it with head
			head->val = lo->val;
			lo->val = temp;
			head = head->next;	// check next
		}
		lo = lo->next;	// repeat for next node
	}
	temp = head->val;	// swap pivot and tail
	head->val = tail->val;
	tail->val = temp;
	return pivot;
}

void quickSort(struct Node* head, struct Node* tail){
	struct Node* p = partition(head, tail);	// get partitioning node
	if (head!=tail){	// head=tail means empty list
		if (p && head!=p){
			quickSort(head, p);	// first half
		} if (p && p->next){
			quickSort(p->next,tail);	// second half
		}
	}
}

void main(){
	struct Node* head = createList(10);
	traverseList(head);
	struct Node* tail = head;
	while (tail && tail->next){
		tail = tail->next;
	}
	quickSort(head, tail);	// for list with 10 nodes
	printf("\n");
	traverseList(head);
}
