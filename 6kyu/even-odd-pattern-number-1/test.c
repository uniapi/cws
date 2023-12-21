/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 21, 2023
 */

#include <ao/aopf.h>

extern unsigned evenodd(const unsigned *arr, size_t cnt);

#define ALIM	17

typedef struct aocase {
	size_t cnt;
	unsigned arr[ALIM];
	unsigned expected;
	unsigned actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %u\n*Actual*: %u\n  Array: [", aoc->expected, aoc->actual);
	for (i = 0; i < aoc->cnt; ++i) {
		if (!(i & 7))
			fstderr("\n  ");
		fstderr(" %4u", aoc->arr[i]);
	}
	fstderr("\n  ]\n  Count: %zu\n", aoc->cnt);
}

aop_t assert_case(aocase_t *aoc)
{
	int arr[ALIM];
	memcpy(arr, aoc->arr, sizeof(unsigned) * aoc->cnt);
	aoc->actual = evenodd(arr, aoc->cnt);
	aov_assert_memv(aoc->arr, arr, aoc->cnt, sizeof(unsigned));
    return aop_uint_eq(aoc->expected, aoc->actual);
}
