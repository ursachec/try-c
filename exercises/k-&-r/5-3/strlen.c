#include <stdio.h>

int strlen_new(char *s);

int main()
{
	char *s = "ABCDEFGHIJ";
	int lengthOfS = 0;

	lengthOfS = strlen_new(s);
	printf("The length of the string '%s' is %d\n", s, lengthOfS);

	return 0;
}

/* strlen: return length of string s */
int strlen_new(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}