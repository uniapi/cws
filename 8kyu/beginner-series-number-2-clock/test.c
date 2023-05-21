/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               May 21, 2023
 */

#include <ao/aopf.h>

extern int past(int h, int m, int s);

typedef struct aocase {
    int h;
	int m;
	int s;
	int expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_int_eq(
		aoc->expected, past(aoc->h, aoc->m, aoc->s),
		"    h: %i\n    m: %i\n    s: %i\n",
		aoc->h, aoc->m, aoc->s
	);
}
