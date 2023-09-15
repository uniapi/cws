/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Sep 8, 2023
 */

#include <ao/aopf.h>
#include <stdbool.h>
#include <string.h>

extern bool in_asc_order(const unsigned *v, size_t cnt);

#define NLIM			288
#define BOOL_FMT(b)		(b ? "true" : "false")


typedef struct aocase {
	unsigned v[NLIM];
	size_t cnt;
	bool expected;
	bool actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %s\n*Actual*: %s\n    Nums: [", BOOL_FMT(aoc->expected), BOOL_FMT(aoc->actual));
	for (i = 0; i < aoc->cnt; ++i)
		fstderr("%s  %4u", (!(i & 7) ? "\n    " : ""), aoc->v[i]);
	fstderr("\n%s]\n    Count: %zu", (i ? "    " : ""), aoc->cnt);
}

aop_t assert_case(aocase_t *aoc)
{
	unsigned v[NLIM];
	aoc->actual = in_asc_order(memcpy(v, aoc->v, sizeof(unsigned) * aoc->cnt), aoc->cnt);
	aov_assert_memv(aoc->v, v, aoc->cnt, sizeof(int));
    return aop_bool_eq(aoc->expected, aoc->actual);
}
