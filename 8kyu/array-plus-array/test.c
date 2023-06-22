/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Aug 31, 2019
 */

#include <ao/aopf.h>
#include <limits.h>

#define NLIM	69

extern long arr_plus_arr(const int *a, const int *b, size_t na, size_t nb);

typedef struct aocase {
	size_t na;
	int a[NLIM];
	size_t nb;
	int b[NLIM];
	long expected;
	long actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	const char *descr[] = { "A", "B" };
	const int *nums[] = { aoc->a, aoc->b };
	const size_t ns[] = { aoc->na, aoc->nb };
	const int n = sizeof descr / sizeof (char *);
	size_t ni, i;
	fstderr("Expected: %ld\n*Actual*: %ld\n\n", aoc->expected, aoc->actual);
	for (ni = 0; ni < n; ++ni) {
		fstderr("Array %s: [", descr[ni]);
		for (i = 0; i < ns[ni]; ++i)
			fstderr("%s  %8i", (!(i & 7) ? "\n    " : ""), nums[ni][i]);
		fstderr("\n]\n");
	}
	fstderr("na: %zu\nnb: %zu\n", aoc->na, aoc->nb);
}

aop_t assert_case(aocase_t *aoc)
{
	aop_t aop;
	int a[NLIM], b[NLIM];
	memcpy(a, aoc->a, aoc->na * sizeof(int));
	memcpy(b, aoc->b, aoc->nb * sizeof(int));
	aoc->actual = arr_plus_arr(a, b, aoc->na, aoc->nb);
    aop = aop_long_eq(aoc->expected, aoc->actual);
	aov_assert_memv(aoc->a, a, aoc->na, sizeof(int));
	aov_assert_memv(aoc->b, b, aoc->nb, sizeof(int));
	return aop;
}
