/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Aug 27, 2025
 */

#include <ao/aopf.h>

extern int nbdig(int n, int d);

typedef struct aocase {
	int n;
	int d;
	int expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	int actual = nbdig(aoc->n, aoc->d);
    return aopf_int_eq(aoc->expected, actual, "    n: %i\n    d: %i", aoc->n, aoc->d);
}
