#ifndef _NODE_H_
#define _NODE_H_

typedef struct node
{
	int value;
	struct node *next;
}Node;

typedef struct list
{
	Node *head;
	Node *tail;
}List;

#endif
