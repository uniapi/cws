/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jun 17, 2023
 */

#include <ao/aopf.h>

extern int psum(const int *nums, size_t cnt);

typedef struct aocase {
	size_t cnt;
	const int *nums;
	int expected;
	int actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %i\n*Actual*: %i\nNumbers: [", aoc->expected, aoc->actual);
	for (i = 0; i < aoc->cnt; ++i)
		fstderr("%s %4i", (!(i & 7) ? "\n    " : ""), aoc->nums[i]);
	fstderr("\n]\nCount: %zu\n", aoc->cnt);
}

aop_t assert_case(aocase_t *aoc)
{
	aoc->actual = psum(aoc->nums, aoc->cnt);
	return aop_int_eq(aoc->expected, aoc->actual);
}
