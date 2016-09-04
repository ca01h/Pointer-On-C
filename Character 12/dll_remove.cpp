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

int dll_remove(struct NODE *rootp, struct NODE *delete_node)
{
	Node *current;

	assert(delete_node != NULL);

	for (current = rootp->fwd; current != NULL; current = current->fwd)
	{
		if (current == delete_node)
		{
			break;
		}
	}

	if (current == delete_node)
	{
		if (current->bwd == NULL)
		{
			rootp->fwd = current->fwd;
		} 
		else
		{
			current->bwd->fwd = current->fwd;
		}

		if (current->fwd == NULL)
		{
			rootp->bwd = current->bwd;
		} 
		else
		{
			current->fwd->bwd = current->bwd;
		}

		free(current);

		return TRUE;
	} 
	else
	{
		return FALSE;
	}
}

