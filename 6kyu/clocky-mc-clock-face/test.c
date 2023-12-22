/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 22, 2023
 */

#include <ao/aopf.h>

extern char *whatstime(char outp[6], double angle);

#define FMT_TM		6

typedef struct aocase {
	double angle;
	char expected[FMT_TM];
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char actual[FMT_TM];
	aov_assert_ptrv(actual, whatstime(actual, aoc->angle));
    return aopf_str_eq(aoc->expected, actual, "   Angle: %.2lf", aoc->angle);
}
