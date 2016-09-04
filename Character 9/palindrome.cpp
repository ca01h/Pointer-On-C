#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

int
palindrome(char *string)
{
	char *string_end;
	string_end = string + strlen(string) - 1;
	
	while(TRUE){
		while(!isalpha(*string)){
			string++;
		}
		while(!isalpha(*string_end)){
			string_end--;
		}
		if(string_end <= string){
			return TRUE;
		}
		if(tolower(*string) != tolower(*string_end)){
			return FALSE;
		}
		string++;
		string_end--;
	}
		
} 



int
main(void)
{
	char *string;
	char ch;
	printf("Enter a string\n");
	
	string = (char*)malloc(sizeof(char) * 20);
	char *ptr = string;
	while(ch != '\n'){
		scanf("%c", &ch);
		*ptr++ = ch; 
	}
	*--ptr = '\0';
	
	if(palindrome(string)){
		printf("The string is palindrome!");
	}
	else{
		printf("The string is not palindrome!");
	}
	return 0;
}
