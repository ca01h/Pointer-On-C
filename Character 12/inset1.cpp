#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NODE 
{
	struct NODE *link;
	int value;
}Node;

int sll_insert(Node *current, int new_value)
{
	Node *previous;
	Node *new_node;

	while (current->value < new_value)
	{
		previous = current;
		current = current->link;
	}

	new_node = (Node*)malloc(sizeof(Node));
	assert(new_node != NULL);
	new_node->value = new_value;

	new_node->link = current;
	previous->link = new_node;

	return EXIT_SUCCESS;
}
