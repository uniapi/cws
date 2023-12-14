/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 14, 2023
 */
#include <ao/aopf.h>

extern char *fixedxor(char *outp, const char *x, const char *y);

#define SLIM	140

typedef struct aocase {
	char x[SLIM];
	char y[SLIM];
	char expected[SLIM];
	char actual[SLIM];
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char x[SLIM], y[SLIM];
	strcpy(x, aoc->x), strcpy(y, aoc->y);
	aov_assert_ptrv(aoc->actual, fixedxor(aoc->actual, x, y));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->x, x));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->y, y));
    return aopf_str_eq(aoc->expected, aoc->actual, "       X: \"%s\"\n       Y: \"%s\"", aoc->x, aoc->y);
}
