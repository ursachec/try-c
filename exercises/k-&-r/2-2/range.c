#include <stdio.h>

#define DATA_TYPE float /* can be char, int, short, long, etc */

/* tests where the jumping point is for a data type */
main()
{
	DATA_TYPE max;

	max = 1;
	for(int i = max; max > 0; i++) {
		max = i;
	}
	printf("jumping number: %6d\n", max);
}