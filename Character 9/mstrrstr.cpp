#include <stdio.h>
#include <string.h>

char*
my_strrstr(char const *s1, char const *s2)
{
	char *last;
	char *current;
	
	last = NULL;
	
	if(*s2 != '\0'){
		current = strstr(s1, s2);
		
		while(current != NULL){
			last = current;
			current = strstr(last + 1, s2);
		}
	}
	
	return last;
}

int
main(void)
{
	char *result;
	result = my_strrstr("Hello world, Hello WHTU", "Hello");
	printf(result);
	return 0;
}
 
