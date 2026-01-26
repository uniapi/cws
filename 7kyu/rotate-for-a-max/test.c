/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Aug 31, 2025
 */

#include <ao/aopf.h>

extern int maxrot(int n);

typedef struct aocase {
	int n;
	int expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	int actual = maxrot(aoc->n);
    return aopf_int_eq(aoc->expected, actual, "  Number: %i", aoc->n);
}
