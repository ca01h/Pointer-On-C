#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

typedef struct NODE 
{
	struct NODE *fwd;
	struct NODE *bwd;
	int value;
}Node;

int dll_insert(Node rootp, int value)
{
	Node *this_node;
	Node *next_node;
	Node *new_node;

	for (this_node = rootp; (new_node = this_node->fwd) != NULL; this_node = new_node)
	{
		if (next_node->value == value)
		{
			return 0;
		}
		if (next_node->value > value)
		{
			break;
		}
	}

	new_node = (Node *)malloc(sizeof(Node));
	assert(new_node != NULL);
	new_node->value = value;

	new_node->fwd = next_node;
	this_node->fwd = new_node;

	if (this_node != rootp)
	{
		new_node->bwd = this_node;
	} 
	else
	{
		new_node->bwd = NULL;
	}

	if (next_node != NULL)
	{
		next_node->bwd = new_node;
	} 
	else
	{
		rootp->bwd = new_node;
	}

	return 1;
}


