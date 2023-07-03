/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jul 3, 2023
 */

#include <ao/aopf.h>

extern int find_diff(const int a[3], const int b[3]);

typedef struct aocase {
	int a[3];
	int b[3];
	int expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	int a[3], b[3], actual;
	memcpy(a, aoc->a, 3 * sizeof(int));
	memcpy(b, aoc->b, 3 * sizeof(int));
	actual = find_diff(a, b);
	aov_assert_memv(aoc->a, a, 3, sizeof(int));
	aov_assert_memv(aoc->b, b, 3, sizeof(int));
    return aopf_int_eq(
		aoc->expected, actual,
		"  a: %i, %i, %i\n  b: %i, %i, %i",
		aoc->a[0], aoc->a[1], aoc->a[2], aoc->b[0], aoc->b[1], aoc->b[2]
	);
}
