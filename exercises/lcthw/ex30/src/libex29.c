#include <stdio.h>
#include <ctype.h>
#include "dbg.h"

int print_a_message(const char *message)
{
	printf("A string: %s\n", message);

	return 0;
}

int uppercase(const char *message)
{
	int i = 0;

	// BUG: \0 termination problems
	for(i = 0; message[i] != '\0'; i++) {
		printf("%c", toupper(message[i]));
	}

	printf("\n");

	return 0;
}

int lowercase(const char *message)
{
	int i = 0;

	for(i = 0; message[i] != '\0'; i++) {
		printf("%c", tolower(message[i]));
	}

	printf("\n");

	return 0;
}

int fail_on_purpose()
{
	return 1;
}

