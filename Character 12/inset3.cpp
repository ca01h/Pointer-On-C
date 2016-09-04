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

int sll_insert(Node **linkp, int new_value)
{
	Node *current;
	Node * new_node;

	while ((current = *linkp) != NULL && current->value > new_value)
	{
		linkp = &current->link;
	}

	new_node = (Node *)malloc(sizeof(Node));
	assert(new_node != NULL);
	new_node->value = new_value;

	new_node->link = current;
	*linkp = new_node;

	return TRUE;
}
