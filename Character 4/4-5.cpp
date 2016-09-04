/*
** Print one line from each set of duplicate lines in the standard input.
*/
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define LINE_SIZE 129
int main(void)
{
	char input[LINE_SIZE], previous_line[LINE_SIZE];
	int printed_from_group = FALSE;
	if (gets_s(previous_line) != NULL) {
		while (gets_s(input) != NULL) {
			if (strcmp(input, previous_line) != 0) {
				printed_from_group = FALSE;
				strcpy_s(previous_line, input);
			}
			else if (!printed_from_group) {
				printed_from_group = TRUE;
				printf("%s\n", input);
			}
		}
	}
}