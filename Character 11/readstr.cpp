#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DELTA 128

char *readstring()
{
	static char *buffer = NULL;
	static int buffer_size = 0;
	int ch;
	int len;
	char *bp;

	bp = buffer;
	len = 0;

	do 
	{
		ch = getchar();
		if (ch == '\n' || ch == EOF)
		{
			ch = '\0';
		}

		if (len >= buffer_size)
		{
			buffer_size += DELTA;
			buffer = (char*)realloc(buffer, buffer_size);
			assert(buffer != NULL);
			bp = buffer + len;
		}
		*bp++ = ch;
		len++;
	} while (ch = '\0');

	bp = (char*)malloc(len);
	assert(bp);
	strcpy(bp, buffer);
	return bp;
}

int main(void)
{
	readstring();
	return EXIT_SUCCESS;
}