#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeStruct {
	char* val;
	struct nodeStruct* left;
	struct nodeStruct* right;
} node;

typedef struct stackStruct {
	node* data;
	struct stackStruct* next;
} stack;

// from stack.c
void init(stack** head);
void push(stack** head, node* node);
node* pop(stack** head);
node* top(stack* head);
int is_empty(stack* head);
stack* clear(stack** head);

// from btree.c
node* newNode(char* key);
void treeClear(node* head);
node* parseExpression(char e[300]);
int evalExpression(node* head);
void printInfixExpression(node* head);
void printPrefixExpression(node* head);
void printPostfixExpression(node* head);