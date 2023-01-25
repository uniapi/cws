/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jan 25, 2023
 */

#include <inttypes.h>

extern uint64_t *powers_of_two(uint64_t *powers, size_t n);

#define NBITS		(sizeof(uint64_t) << 3)

typedef struct aocase {
	size_t n;
	uint64_t expected[NBITS];
	uint64_t actual[NBITS];
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	const char *descr[] = { "Expected", "*Actual*" };
	const uint64_t *pws[] = { aoc->expected, aoc->actual };
	size_t i, j;
	for (i = 0; i < 2; ++i) {
		fstderr("%s: [", descr[i]);
		for (j = 0; j <= aoc->n; ++j) {
			if (!(j & 7))
				fstderr("\n");
			fstderr(" %16"PRIx64, pws[i][j]);
		}
		fstderr("\n]\n");
	}
	fstderr("N: %zu\n", aoc->n);
}

aop_t assert_case(aocase_t *aoc)
{
	aov_assert(AOV_PTRV, aop_ptr_eq(aoc->actual, powers_of_two(aoc->actual, aoc->n)));
	return aop_mem_eq(aoc->expected, aoc->actual, aoc->n+1, sizeof(uint64_t));
}
