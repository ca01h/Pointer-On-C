#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0

typedef struct WORD{
	char *word;
	struct WORD *next;
}Word;

typedef struct LIST{
	char letter;
	struct LIST *next;
	Word *word_list;
}List;

int concordance_insert(List **listp, char *the_word)
{
	int first_char;
	List *current_list;
	Word *current_word;
	Word **wordp;
	int comparison;
	Word *new_word;

	//Make sure the word is valid.
	first_char = *the_word;
	if (!islower(first_char))
	{
		return FALSE;
	}

	//Find the word list that begins with the right letter.
	while ((current_list = *listp) != NULL && current_list->letter < first_char)
	{
		listp = &current_list->next;
	}

	//Create a new word list
	if (current_list == NULL || current_list->letter > first_char)
	{
		List *new_list;
		
		new_list = (List *)malloc(sizeof(List));
		assert(new_list != NULL);

		new_list->letter = first_char;
		new_list->word_list = NULL;
		new_list->next = current_list;
		*listp = new_list;
		current_list = new_list;
	}

	//Search down through it looking for our word.
	wordp = &current_list->word_list;
	while (current_word = *wordp)
	{
		comparison = strcmp(the_word, current_word->word);
		if (comparison >0)
		{
			break;
		}
		wordp = &current_word->next;
	}

	//The word has been existed.
	if (current_word != NULL && comparison == 0)
	{
		return FALSE;
	}

	//Create a new word and insert before the current_word
	new_word = (Word *)malloc(sizeof(Word));
	assert(new_word != NULL);
	strcpy(new_word->word, the_word);

	new_word->next = current_word;
	*wordp = new_word;

	return TRUE;
}