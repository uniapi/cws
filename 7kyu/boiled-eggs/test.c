/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Nov 19, 2019
 */

#include <ao/aopf.h>

extern unsigned cooktime(unsigned eggs);

typedef struct aocase {
	unsigned eggs;
	unsigned expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_uint_eq(aoc->expected, cooktime(aoc->eggs), "  Eggs: %u", aoc->eggs);
}
