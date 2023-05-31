/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               May 30, 2023
 */

#include <ao/aopf.h>

extern bool small_enough(const int *arr, size_t len, int lim);

#define ARR_LIM		1024

#define BOOL_FMT(b)		((b) ? "true" : "false")

typedef struct aocase {
	size_t len;
	int arr[ARR_LIM];
	int lim;
	bool expected;
	bool actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %s\n*Actual*: %s\n   Array: [", BOOL_FMT(aoc->expected), BOOL_FMT(aoc->actual));
	for (i = 0; i < aoc->len; ++i)
		fstderr("%s %4i", (!(i & 7) ? "\n     " : ""), aoc->arr[i]);
	fstderr("\n   ]\n   Length: %zu\n   Limit:  %i\n", aoc->len, aoc->lim);
}

aop_t assert_case(aocase_t *aoc)
{
	int arr[ARR_LIM];
	memcpy(arr, aoc->arr, aoc->len * sizeof(int));
	aoc->actual = small_enough(aoc->arr, aoc->len, aoc->lim);
	aov_assert_memv(aoc->arr, arr, aoc->len, sizeof(int));
    return aop_bool_eq(aoc->expected, aoc->actual);
}
