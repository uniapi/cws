/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Nov 11, 2019
 */

#include <ao/aopf.h>

extern int diffsum(const int *arr, size_t cnt);

#define ARRLIM		71

typedef struct aocase {
	size_t cnt;
	const int arr[ARRLIM];
	int expected;
	int actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %i\n*Actual*: %i\n\nArray: [", aoc->expected, aoc->actual);
	for (i = 0; i < aoc->cnt; ++i)
		fstderr("%s  %4i", (!(i & 7) ? "\n    " : ""), aoc->arr[i]);
	fstderr("\n]\nCount: %zu\n", aoc->cnt);
}

aop_t assert_case(aocase_t *aoc)
{
	int arr[ARRLIM];
	memcpy(arr, aoc->arr, aoc->cnt * sizeof(int));
	aoc->actual = diffsum(arr, aoc->cnt);
	aov_assert_memv(aoc->arr, arr, aoc->cnt, sizeof(int));
    return aop_int_eq(aoc->expected, aoc->actual);
}
