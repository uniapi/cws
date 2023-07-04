/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jul 4, 2023
 */

#include <ao/aopf.h>

#define VMAX	69

extern const char *odd_or_even(const int *v, size_t cnt);

typedef struct aocase {
	size_t cnt;
	int v[VMAX];
	const char *expected;
	const char *actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %s\n*Actual*: %s\nVector: [", aoc->expected, aoc->actual);
	for (i = 0; i < aoc->cnt; ++i)
		fstderr("%s  %4i", (!(i & 7) ? "\n    " : ""), aoc->v[i]);
	fstderr("\n]\nCount: %zu\n", aoc->cnt);
}

aop_t assert_case(aocase_t *aoc)
{
	int v[VMAX];
	memcpy(v, aoc->v, aoc->cnt * sizeof(int));
	aoc->actual = odd_or_even(aoc->v, aoc->cnt);
	aov_assert_memv(aoc->v, v, aoc->cnt, sizeof(int));
    return aop_str_eq(aoc->expected, aoc->actual);
}
