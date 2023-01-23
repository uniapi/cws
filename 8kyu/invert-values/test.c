/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jan 23, 2023
 */

#include <ao/aopf.h>

extern int *invert(int *outp, const int *nums, size_t cnt);

#define NLIM	0x100

typedef struct aocase {
	size_t cnt;
    int nums[NLIM];
	int expected[NLIM];
	int actual[NLIM];
} aocase_t;


void at_case_fail(const aocase_t *aoc)
{
	size_t n, k = 2;
	int *nums;
	while (k--) {
		size_t i = 0;
		if (k) {
			nums = (int *)aoc->expected;
			fstderr("Expected: [");
		}
		else {
			nums = (int *)aoc->actual;
			fstderr("*Actual*: [");
		}
		n = aoc->cnt;
		while (i < n) {
			if (!(i & 7))
				fstderr("\n  ");
			fstderr(" %3i", *(nums+i++));
		}
		fstderr("\n]\n");
	}
	fstderr("Count: %zu\n", aoc->cnt);
}

aop_t assert_case(aocase_t *aoc)
{
	int nums[NLIM];
	memcpy(nums, aoc->nums, aoc->cnt * sizeof(int));
	aov_assert(AOV_PTRV, aop_ptr_eq(aoc->actual, invert(aoc->actual, nums, aoc->cnt)));
	aov_assert(AOV_MEMV, aop_mem_eq(aoc->nums, nums, aoc->cnt, sizeof(int)));
    return aop_mem_eq(aoc->expected, aoc->actual, aoc->cnt, sizeof(int));
}
