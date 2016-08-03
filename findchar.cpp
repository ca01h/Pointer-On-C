#include <stdio.h>
#include <stdlib.h>
#define NULL 0

char *find_char(const char *source, const char* chars)
{
    char *cp;
    if(source != NULL && chars != NULL)
    {
        for(; *source != '\0'; source++)
        {
            for(cp = chars; *cp != '\0'; cp++)
            {
                if(*source == *cp)
                    return source;
            }
        }
    }
    return NULL;
}

int main(void)
{
    const char *source = "ABCDEF";
    const char *chars = "XRCQEF";
    char * cp;
    cp = find_char(source, chars);
    printf("%c\n", *cp);
}
