/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Sep 27, 2023
 */

#include <ao/aopf.h>

extern int square_sum(const int *values, size_t cnt);

#define NLIM	96

typedef struct aocase {
	size_t cnt;
	int values[NLIM];
	int expected;
	int actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %i\n*Actual*: %i\n  Values: [", aoc->expected, aoc->actual);
	for (i = 0; i < aoc->cnt; ++i) {
		if (!(i & 7))
			fstderr("\n  ");
		fstderr("  %4i", aoc->values[i]);
	}
	fstderr("\n  ]\n  Count:  %zu\n", aoc->cnt);
}

aop_t assert_case(aocase_t *aoc)
{
	int values[NLIM];
	aoc->actual = square_sum(memcpy(values, aoc->values, sizeof(int) * aoc->cnt), aoc->cnt);
	aov_assert_memv(aoc->values, values, aoc->cnt, sizeof(int));
    return aop_int_eq(aoc->expected, aoc->actual);
}
