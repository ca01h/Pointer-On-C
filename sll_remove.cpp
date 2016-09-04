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

int sll_remove(struct NODE **linkp, struct NODE *delete_node)
{
	struct NODE *current;
	
	assert(delete_node != NULL);

	while ((current = *linkp) != NULL && current != delete_node)
	{
		linkp = &current->link;
	}

	if (current == delete_node)
	{
		*linkp = current->link; 
		free(current);
		return TRUE;
	} 
	else
	{
		return FALSE;
	}
}


