/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Aug 4, 2024
 */

#include <ao/aopf.h>

extern int find_missing(const int *nums, size_t n);

#define NUMLIM		0x48

typedef struct aocase {
	const int *nums;
	size_t n;
	int expected;
	int actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %i\n*Actual*: %i\n  Numbers: [", aoc->expected, aoc->actual);
	for (i = 0; i < aoc->n; ++i)
		fstderr("%s%i", (!(i & 7) ? "\n     " : ", "), aoc->nums[i]);
	fstderr("\n  ]\n");
}

aop_t assert_case(aocase_t *aoc)
{
	int nums[NUMLIM];
	aoc->actual = find_missing(memcpy(nums, aoc->nums, sizeof(int)*aoc->n), aoc->n);
	aov_assert_memv(aoc->nums, nums, aoc->n, sizeof(int));
    return aop_int_eq(aoc->expected, aoc->actual);
}
