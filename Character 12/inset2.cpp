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

int sll_insert(Node **rootp, int new_value)
{
	Node *current;
	Node *prevoius;
	Node *new_node;

	current = *rootp;
	prevoius = NULL;

	while (current != NULL && current->value < new_value)
	{
		prevoius = current;
		current = current->link;
	}

	new_node = (Node *)malloc(sizeof(Node));
	assert(new_node != NULL);
	new_value = new_node->value;

	new_node->link = current;
	if (prevoius == NULL)
	{
		*rootp = new_node;
	} 
	else
	{
		prevoius->link = new_node;
	}

	return TRUE;
}
