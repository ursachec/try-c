#include <stdio.h>

void strcat_new(char s[], char t[]);

main()
{
	char s[100], t[100];
	int nrn = 10;

	/* fill the char arrays with random characters*/
	for (int i = 0; i < nrn; ++i) {
		s[i] = 't';
		t[i] = 'a';
	}

	strcat_new(s, t);

	printf("s: %s \n t: %s\n", s, t);
}

/* strcat: copy t to end of s; s must be big enough */
void strcat_new(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0') /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}