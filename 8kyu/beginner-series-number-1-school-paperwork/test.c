/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               May 21, 2023
 */

#include <ao/aopf.h>

extern int paperwork(int n, int m);

typedef struct aocase {
    int n;
	int m;
	int expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_int_eq
	(
		aoc->expected, paperwork(aoc->n, aoc->m),
		"    n: %i\n    m: %i\n\n",
		aoc->n, aoc->m
	);
}
