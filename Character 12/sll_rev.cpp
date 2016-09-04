#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

typedef struct NODE 
{
	struct NODE *link;
	int value;
}Node;

struct Node *sll_rev(Node *current)
{
	Node *previous;
	Node *next;

	for (previous = NULL; next != NULL; current = next)
	{
		next = current->link;
		current->link = previous;
		previous = current;
	}

	return previous;
}


