/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Oct 1, 2023
 */

#include <ao/aopf.h>

extern size_t consecutive(const int *nums, size_t n);

#define NLIM 260

typedef struct aocase {
	size_t n;
	int nums[NLIM];
	size_t expected;
	size_t actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %zu\n*Actual*: %zu\n  Numbers: [", aoc->expected, aoc->actual);
	for (i = 0; i < aoc->n; ++i)
		fstderr("%s  %2i", (!(i & 7) ? "\n  " : ""), aoc->nums[i]);
	fstderr("\n  ]\n  Count: %zu\n", aoc->n);
}

aop_t assert_case(aocase_t *aoc)
{
	int nums[NLIM];
	memcpy(nums, aoc->nums, sizeof(int) * aoc->n);
	aoc->actual = consecutive(nums, aoc->n);
	aov_assert_memv(aoc->nums, nums, aoc->n, sizeof(int));
    return aop_ulong_eq(aoc->expected, aoc->actual);
}
