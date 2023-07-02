/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Sep 14, 2019
 */

#include <ao/aopf.h>

extern float divnums(int x, int y);

typedef struct aocase {
	int x;
	int y;
	float expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	return aopf_flt_eq(
		aoc->expected, divnums(aoc->x, aoc->y), 1e6, 1e50,
		"    x: %i\n    y: %i",
		aoc->x, aoc->y
	);
}
