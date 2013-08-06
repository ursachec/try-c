#include "minunit.h"
#include <lcthw/stats.h>
#include <math.h>

const int NUM_SAMPLES = 10;
double samples[] = {
	0.1002282, 4.9284442, 2.4069888, 0.4142882, 6.4001290, 7.5881631, 1.8376392,
 	6.5779590, 9.1181472, 8.5101032
};

Stats expect = {
	.sum = 47.88209,
	.sumsq = 331.0156,
	.n = 10,
	.min = 0.1002,
	.max = 9.1180
};

double expect_mean = 4.7880;
double expect_stddev = 3.36231;

#define EQ(X,Y,N) (round((X) * pow(10, N)) == round((Y) * pow(10, N)))

char *test_operations()
{
	int i = 0;
	Stats *st = Stats_create();
	mu_assert(st != NULL, "Failed to create stats.");

	for(i = 0; i < NUM_SAMPLES; i++) {
		Stats_sample(st, samples[i]);
	}

	Stats_dump(st);

	mu_assert(EQ(st->sumsq, expect.sumsq, 3), "sumsq not valid.");
	mu_assert(EQ(st->sum, expect.sum, 3), "sum not valid.");
	mu_assert(EQ(st->min, expect.min, 3), "min not valid.");
	mu_assert(EQ(st->max, expect.max, 3), "max not valid.");
	mu_assert(EQ(st->n, expect.n, 3), "n not valid.");
	mu_assert(EQ(expect_mean, Stats_mean(st), 3), "mean not valid.");
	mu_assert(EQ(expect_stddev, Stats_stddev(st), 3), "stddev not valid.");

	return NULL;
}

char *test_recreate()
{
	Stats *st = Stats_recreate(expect.sum, expect.sumsq, expect.n, expect.min, expect.max);
	mu_assert(st != NULL, "Error, Stats object cannot be NULL.");

	mu_assert(st->sumsq == expect.sumsq, "sumsq not valid.");
	mu_assert(st->sum == expect.sum, "sum not valid.");
	mu_assert(st->min == expect.min, "min not valid.");
	mu_assert(st->max == expect.max, "max not valid.");
	mu_assert(st->n == expect.n, "n not valid.");

	mu_assert(EQ(expect_mean, Stats_mean(st), 3), "mean not valid.");
	mu_assert(EQ(expect_stddev, Stats_stddev(st), 3), "stddev not valid.");

	return NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_operations);
	mu_run_test(test_recreate);

	return NULL;
}

RUN_TESTS(all_tests);
