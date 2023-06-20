/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jun 20, 2023
 */

#include <ao/aopf.h>

extern int quarterof(int month);

typedef struct aocase {
	int month;
	int expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_int_eq(aoc->expected, quarterof(aoc->month), "  Month: %i", aoc->month);
}
