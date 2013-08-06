#include "minunit.h"
#include <lcthw/bstrlib.h>
#include <lcthw/ringbuffer.h>

static struct tagbstring test1 = bsStatic("test data 1");
static struct tagbstring test2 = bsStatic("test data 2");
static struct tagbstring test3 = bsStatic("test data 3");

static bstring bss1 = NULL;
static bstring bss2 = NULL;
static bstring bss3 = NULL;

#define RINGBUFFER_SIZE 200

RingBuffer *buffer = NULL;
char data[RINGBUFFER_SIZE] = {'\0'};

int setup_bstrings()
{
	bss1 = &test1;
	bss2 = &test2;
	bss3 = &test3;

	return 0;
}

char *test_create()
{	
	setup_bstrings();

	buffer = RingBuffer_create(RINGBUFFER_SIZE);
	mu_assert(buffer != NULL, "Failed to create buffer.");
	mu_assert(buffer->length == RINGBUFFER_SIZE + 1, "Got wrong buffer size.");
	mu_assert(buffer->buffer != NULL, "Failed to create a buffer for the buffer");

	return NULL;
}

char *test_write()
{	
	int rc = RingBuffer_write(buffer, (char *)bss1->data, blength(bss1));
	mu_assert(rc == blength(bss1), "Failed to write &test1 to buffer.");

	rc = RingBuffer_write(buffer, (char *)bss2->data, blength(bss2));
	mu_assert(rc == blength(bss2), "Failed to write &test2 to buffer.");

	rc = RingBuffer_write(buffer, (char *)bss3->data, blength(bss3));
	mu_assert(rc == blength(bss3), "Failed to write &test3 to buffer.");

	return NULL;
}

char *test_gets()
{
	bstring rbs1 = NULL;

	rbs1 = RingBuffer_gets(buffer, blength(bss1));
	mu_assert(rbs1 != NULL, "Error getting first bstring from ringbuffer.");
	mu_assert(bstrcmp(rbs1, bss1) == 0, "The returned bstring should be equal to bstring1.");

	return NULL;
}


char *test_read()
{
	int rc = RingBuffer_read(buffer, data, blength(bss2));
	mu_assert(rc == blength(bss2), "Failed to read right amount of bytes.");
	mu_assert(strcmp(data, (char *)bss2->data) == 0, "Retrieved bss2 string is not the same.");

	rc = RingBuffer_read(buffer, data, blength(bss3));
	mu_assert(rc == blength(bss3), "Failed to read right amount of bytes.");
	mu_assert(strcmp(data, (char *)bss3->data) == 0, "Retrieved bss3 string is not the same.");

	// trying to read again should not work
	rc = RingBuffer_read(buffer, data, blength(bss3));
	mu_assert(rc == -1, "Failed to read right amount of bytes.");

	return NULL;
}

char *test_destroy()
{
	RingBuffer_destroy(buffer);

	return NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_write);
	mu_run_test(test_gets);
	mu_run_test(test_read);
	mu_run_test(test_destroy);

	return NULL;
}

RUN_TESTS(all_tests);
