#include "header.h"
#define TRUE 1
#define FALSE 0

void init(stack** head) {
	*head = NULL;
}


void push(stack** head, node* node) {
	// allocate memory
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->data = node;

	// check whether stack is empty
	if (*head == NULL)
		temp->next = NULL; // stack is empty, set next pointer to NULL
	else
		temp->next = *head; // stack isn't empty, set next pointer to head
	*head = temp; // repoint head pointer
}

node* pop(stack** head) {
	if (*head == NULL)
		return NULL;
	
	// create temp pointer to head
	stack* temphead = *head;

	// repoint head to next node
	node* temp = (*head)->data;
	*head = (*head)->next;

	// free original head node
	free(temphead);
	return temp;
}

node* top(stack* head) {
	return head->data;
}

int is_empty(stack* head) {
	if (head == NULL)
		return TRUE;
	else
		return FALSE;
}

stack* clear(stack** head) {
	// recursively call clear() until stack is empty
    if (*head == NULL)
        return *head;
    else {
        treeClear((*head)->data); // free node data stored in stack
        pop(head); // pop node from stack
        clear(head);
    }
}