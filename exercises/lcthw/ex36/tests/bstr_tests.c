#include "minunit.h"
#include <lcthw/bstrlib.h>
#include <stdlib.h>

char *test_bchar()
{
	bstring b = bfromcstr("Hello, world!");

	mu_assert(bchar(b, 0) == 'H', "Failed to return right char with bchar.");
	mu_assert(bchar(b, 5) == ',', "Failed to return right char with bchar.");
	mu_assert(bchar(b, 15) == '\0', "Failed to return right fallback char with bchar.");

	bdestroy(b);

	return NULL;
}

char *test_bdata()
{
	bstring b = bfromcstr("Hello, world!");

	mu_assert(strcmp(bdata(b), "Hello, world!") == 0, 
		"Failed to get the data from the bstring.");

	bdestroy(b);

	return NULL;
}

char *test_blength()
{
	bstring b = bfromcstr("Hello, world!");

	mu_assert(blength(b) == 13, "blength returned wrong value for given string.");

	bdestroy(b);

	return NULL;
}

char *test_bformat()
{
	bstring b = bformat("Hello, %s%c", "world", '!');

	mu_assert(strcmp((char *)b->data , "Hello, world!") == 0, 
		"Failed to create bstring from bformat.");

	bdestroy(b);

	return NULL;
}

char *test_bsplit()
{
	bstring b = bfromcstr("Hello, world!");

	struct bstrList *list = bsplit(b, ',');

	bstring bstr1 = list->entry[0];
	bstring bstr2 = list->entry[1];

	mu_assert(list != NULL, "Failed to create bstrList from bsplit call.");
	mu_assert(list->qty > 0, "bstrList should contain more than 0 elements.");

	mu_assert(strcmp((char *)bstr1->data, "Hello") == 0, 
		"Failed to get a valid first substring.");
	mu_assert(strcmp((char *)bstr2->data, " world!") == 0, 
		"Failed to get a valid second substring.");

	bstrListDestroy(list);

	return NULL;
}

char *test_bfindreplace()
{
	bstring b = bfromcstr("Hello, world!");
	bstring find = bfromcstr("Hello");
	bstring replace = bfromcstr("Goodbye");

	mu_assert(bfindreplace(b, find, replace, 0) != BSTR_ERR, 
		"Failed to perform bfindreplace.");
	mu_assert(strcmp((char *)b->data, "Goodbye, world!") == 0,
	 "Failed to perform str replace correctly.");

	bdestroy(b);
	bdestroy(find);
	bdestroy(replace);

	return NULL;
}

char *test_binstr()
{
	bstring b = bfromcstr("Hello, world!");
	bstring b2 = bfromcstr("Hello");

	mu_assert(binstr(b, 0, b2) != BSTR_ERR, "Failed to find substring in string.");
	mu_assert(binstr(b, 5, b2) == BSTR_ERR, "Failed to not find substring in string at pos.");

	bdestroy(b);
	bdestroy(b2);

	return NULL;
}

char *test_biseq()
{
	bstring b = bfromcstr("Hello, world!");
	bstring b2 = bfromcstr("Hello, world!");

	mu_assert(bstricmp(b, b2) == 0, "Failed to compare two equal strings.");

	bdestroy(b);
	bdestroy(b2);

	return NULL;
}

char *test_bstricmp()
{
	bstring b = bfromcstr("Hello, world!");
	bstring b2 = bfromcstr("Hello, world!");
	bstring b3 = bfromcstr("Goodbye, lorem ipsum!");

	mu_assert(bstricmp(b, b2) == 0, "Failed to compare two equal strings.");
	mu_assert(bstricmp(b, b3) > 0, "Failed to compare two different strings.");

	bdestroy(b);
	bdestroy(b2);
	bdestroy(b3);

	return NULL;
}

char *test_bconcat()
{
	bstring b = bfromcstr("Hello, world!");
	bstring bc = bfromcstr("Goodbye, lorem ipsum!");

	mu_assert(bconcat(b, bc) == BSTR_OK, "Failed to concat one bstring to another.");
	mu_assert(strcmp((char *) b->data, "Hello, world!Goodbye, lorem ipsum!") == 0, 
	"Failed to concat." );

	bdestroy(b);

	return NULL;
}

char *test_bdestroy()
{
	bstring b = bfromcstr("Hello, world!");

	mu_assert(bdestroy(b) != BSTR_ERR, "Failed to destroy bstring.");
	mu_assert((char *)b->data == NULL, "Bstring data not NULL.");

	bdestroy(b);

	return NULL;
}

char *test_bassignblk()
{
	bstring b = bfromcstr("Foo bar baz!");	

	bassignblk(b, "Hello, world! Goodbye, lorem ipsum!", 13);

	mu_assert(strcmp((char *)b->data, "Hello, world!") == 0, 
		"Failed to assign cstr with len to bstring.");

	bdestroy(b);

	return NULL;
}

char *test_bassigncstr()
{
	bstring b = bfromcstr("Foo bar baz!");

	bassigncstr(b, "Hello, world!");

	mu_assert(strcmp((char *)b->data, "Hello, world!") == 0, 
		"Failed to assign cstr to bstring.");

	bdestroy(b);

	return NULL;
}

char *test_bassign()
{
	bstring b = bfromcstr("Hello, world!");
	bstring ba = bfromcstr("Goodbye, lorem ipsum!");

	bassign(ba, b);

	mu_assert(strcmp((char *)b->data, (char *)ba->data) == 0, 
		"Failed to assign one bstring to another.");

	bdestroy(b);

	return NULL;
}

char *test_bstrcpy()
{
	bstring b = bfromcstr("Hello, world!");
	bstring bc = NULL;

	bc = bstrcpy(b);

	mu_assert(strcmp((char *)b->data, (char *)bc->data) == 0, "Failed to copy bstring.");

	bdestroy(b);
	bdestroy(bc);

	return NULL;
}

char *test_blk2bstr()
{
	bstring b = blk2bstr("Hello, world! Goodbye, lorem ipsum!", 13);

	mu_assert(strcmp((char *)b->data, "Hello, world!") == 0, 
		"Failed to copy only part of string.");

	bdestroy(b);

	return NULL;
}

char *test_bfromcstr()
{
	bstring b = bfromcstr("Hello, world!");

	mu_assert(b != NULL, "Failed to make the bstring.");

	bdestroy(b);

	return NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_bfromcstr);
	mu_run_test(test_blk2bstr);
	mu_run_test(test_bstrcpy);
	mu_run_test(test_bassign);
	mu_run_test(test_bassigncstr);
	mu_run_test(test_bassignblk);
	mu_run_test(test_bdestroy);
	mu_run_test(test_bconcat);
	mu_run_test(test_bstricmp);
	mu_run_test(test_biseq);
	mu_run_test(test_binstr);
	mu_run_test(test_bfindreplace);
	mu_run_test(test_bsplit);
	mu_run_test(test_bformat);
	mu_run_test(test_blength);
	mu_run_test(test_bdata);
	mu_run_test(test_bchar);

	return NULL;
}

RUN_TESTS(all_tests)
