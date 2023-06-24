/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Nov 25, 2018
 */

#include <ao/aopf.h>

extern int find_smallest_int(const int *v, size_t cnt);

#define VLIM	69

typedef struct aocase {
	size_t cnt;
	int v[VLIM];
	int expected;
	int actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %i\n*Actual*: %i\nVector: [", aoc->expected, aoc->actual);
	for (i = 0; i < aoc->cnt; ++i)
		fstderr("%s  %4i", (!(i & 7) ? "\n    " : ""), aoc->v[i]);
	fstderr("\n]\nN: %zu\n", aoc->cnt);
}

aop_t assert_case(aocase_t *aoc)
{
	int v[VLIM];
	memcpy(v, aoc->v, aoc->cnt * sizeof(int));
	aoc->actual = find_smallest_int(aoc->v, aoc->cnt);
	aov_assert_memv(aoc->v, v, aoc->cnt, sizeof(int));
    return aop_int_eq(aoc->expected, aoc->actual);
}
