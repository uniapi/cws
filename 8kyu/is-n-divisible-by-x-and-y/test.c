/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               May 27, 2021
 */

#include <ao/aopf.h>

extern bool isdiv(int n, int x, int y);

typedef struct aocase {
	int n;
	int x;
	int y;
	bool expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_bool_eq(
		aoc->expected, isdiv(aoc->n, aoc->x, aoc->y),
		"  N: %i\n  X: %i\n  Y: %i",
		aoc->n, aoc->x, aoc->y
	);
}
