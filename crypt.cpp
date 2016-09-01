#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int prepare_key(char *key)
{
	int i;
	int chracter;
	int length;
	char *ptr_key;
	char *dmp;
	bool is_letter_exist[26];

	for (i = 0; i < 26; i++)
	{
		is_letter_exist[i] = FALSE;
	}

	//Make sure the key is legal
	if (*key == '0')
	{
		return FALSE;
	}
	for (ptr_key = key; (chracter = *ptr_key) != '\0'; ptr_key++)
	{
		if (!islower(chracter))
		{
			if (!isupper(chracter))
			{
				return FALSE;
			}
			*ptr_key = toupper(chracter);
		}
	}

	//Delete the repeated letter in key[]
	for (ptr_key = key; (chracter = *ptr_key) != '\0'; ptr_key++)
	{
		if (is_letter_exist[chracter - 65] == FALSE)
		{
			is_letter_exist[chracter - 65] = TRUE;
		}
		else
		{
			dmp = ptr_key; 
			strcpy(dmp, dmp + 1);
			ptr_key--;
		}
	}

	length = strlen(key);

	//add the other letter to key[]
	for (i = 0; i < 26; i++)
	{
		if (is_letter_exist[i] == FALSE)
		{
			key[length] = (char)(i + 65);
			length++;
		}
	}
	key[length] = '\0';

	return TRUE;
}

void encrypt(char *data, char const *key)
{
	int length;
	int i;
	char *ptr_data;

	length = strlen(data);
	for (i = 0, ptr_data = data; i < length; i++)
	{
		if (isalpha(*ptr_data))
		{
			data[i] = key[*ptr_data - 65];
		}
		ptr_data++;
	}
}

void decrypt(char *data, char const *key)
{
	int length;
	int i;
	int index;
	char *ptr_data;
	char *ch;
	
	length = strlen(data);
	for (i = 0, ptr_data = data; i < length; i++)
	{
		if (isalpha(*ptr_data))
		{
			ch = strchr(key, *ptr_data);
			index = strlen(key) - strlen(ch);
			*ptr_data = (char)(index + 65);
		}
		ptr_data++;
	}
}

int main(void)
{
	char key[27] = {'T','R','A','I','L','B','L','A','Z','E','R','S','\0'};
	if (prepare_key(key))
	{
		printf(key);
		printf("\n");
	}
	else
		printf("The key is illegal!\n");

	char data[] = {'A','T','T','A','C','K',' ','A','T',' ','D','A','W','N','\0'};
	encrypt(data, key);

	printf("ENCRYPT: ");
	printf(data);
	printf("\n");

	decrypt(data, key);
	printf("DECRYPT: ");
	printf(data);
	printf("\n");
	
	return EXIT_SUCCESS;
}