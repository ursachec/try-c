
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_PAGES 400000

int main()
{
	char c;
	char *ptr;

	int pageSize = 0;

	pageSize = getpagesize();
	ptr = (char *) malloc(pageSize * NUM_PAGES);

	printf("Press <RETURN> to start cutting memory. ", NUM_PAGES);
	scanf("%c",&c);

	printf("Cutting memory with %d pages...\n", NUM_PAGES);
	while(1) {
		printf("looping ");
		for (int i=0 ; i < NUM_PAGES ; i++) ptr[i*pageSize] = '0';
	}
}
