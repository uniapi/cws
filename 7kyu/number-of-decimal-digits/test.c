/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Sep 27, 2023
 */

#include <ao/aopf.h>

extern size_t ndigits(unsigned long num);

typedef struct aocase {
	unsigned long num;
	size_t expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_ulong_eq(aoc->expected, ndigits(aoc->num), "  Number: %lu", aoc->num);
}
