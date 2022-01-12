#include "header.h"
#include <ctype.h>

node* newNode(char* key) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->val = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void treeClear(node* head) {
	if (head == NULL)
		return NULL;

	// free child nodes
	treeClear(head->left);
	treeClear(head->right);

	free(head);
}

node* parseExpression(char e[300]) {
	int pushcount = 0;
	char* ptr = strtok(e, " ");
	node* tempnode = NULL;
	node* templeftnode = NULL;
	node* temprightnode = NULL;
	stack* s;
	init(&s);

	while(ptr != NULL) {
		tempnode = NULL;
		templeftnode = NULL;
		temprightnode = NULL;

		if(ptr[0] == '*' || ptr[0] == '/' || ptr[0] == '+' || ptr[0] == '-') {
			// if here, token is operator
			tempnode = newNode(ptr);

			// pop right/left children off stack
			temprightnode = pop(&s);
			templeftnode = pop(&s);

			// push node onto stack
			push(&s, tempnode);
			pushcount++;

			// set children of recently inserted stack node
			top(s)->right = temprightnode;
			top(s)->left = templeftnode;
		}
		else if (isdigit(ptr[0])) {
			// if here, token is operand
			tempnode = newNode(ptr);
			push(&s, tempnode);
			pushcount++;
		}
		else {
			// if here, token is either operator or operand. clear memory, exit from function
			printf("Invalid expression. Enter a valid postfix expression \n");
			clear(&s);
			return NULL;
		}
		ptr = strtok(NULL, " ");
	}

	if(is_empty(s) || s->next != NULL || pushcount <= 2) {
		// error check: [nothing on stack] [more than one node on stack] [at least 3 tokens haven't been entered]
		printf("Invalid expression. Enter a valid postfix expression \n");
		clear(&s);
		return NULL;
	}
	else {
		return pop(&s);
	}
}

int evalExpression(node* head) {
	if(isdigit(head->val[0]))
		return atoi(head->val);
	else {
		// if here, token is operator, access values of both children and perform operation
		switch (head->val[0]) {
		case '*':
			return evalExpression(head->left) * evalExpression(head->right);
			break;
		case '/':
			return evalExpression(head->left) / evalExpression(head->right);
			break;
		case '+':
			return evalExpression(head->left) + evalExpression(head->right);
			break;
		case '-':
			return evalExpression(head->left) - evalExpression(head->right);
			break;
		}
	}
}

void printInfixExpression(node* head) {
	// left tree -> root -> right tree
	if(head == NULL)
		return;

	if(head->val[0] == '+' || head->val[0] == '*' || head->val[0] == '-' || head->val[0] == '/') {
		// contains operator, print parentheses before and after expression
		printf("(");
		printInfixExpression(head->left);
		printf(" %s ", head->val);
		printInfixExpression(head->right);
		printf(")");
	}
	else {
		// print normally
		printInfixExpression(head->left);
		printf(" %s ", head->val);
		printInfixExpression(head->right);
	}
}

void printPrefixExpression(node* head) {
	// root -> left tree -> right tree
	if (head == NULL)
		return;

	printf(" %s ", head->val);
	printPrefixExpression(head->left);
	printPrefixExpression(head->right);
}

void printPostfixExpression(node* head) {
	// left tree -> right tree -> root
	if (head == NULL)
		return;
	
	printPostfixExpression(head->left);
	printPostfixExpression(head->right);
	printf(" %s ", head->val);
}