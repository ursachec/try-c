#include <stdio.h>

int strend_new(char *s, char *t);

int main()
{
	char *s = "    toAppend   ";
	char *t = "toAppend";

	if(strend_new(s, t))
		printf("s contains t at the end\n");
	else
		printf("s does NOT contain t at the end\n");

	return 0;
}

int strend_new(char *s, char *t)
{
	for ( ; *s != '\0'; s++)
		if (*s == *t)
			break;

	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 1;
	
	return 0;
}