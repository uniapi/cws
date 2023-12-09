/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 8, 2023
 */

#include <ao/aopf.h>
#include <limits.h>

extern unsigned flipbit(unsigned x, unsigned i);

typedef struct aocase {
	unsigned x;
	unsigned i;
	unsigned expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	unsigned actual = flipbit(aoc->x, aoc->i);
	return aopf_uint_eq(aoc->expected, actual, "   Value: %u\n   Index: %u", aoc->x, aoc->i);
}
