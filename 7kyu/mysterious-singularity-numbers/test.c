/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 5, 2023
 */

#include <ao/aopf.h>

extern unsigned realnums(unsigned num);

typedef struct aocase {
	unsigned num;
	unsigned expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	return aopf_uint_eq(aoc->expected, realnums(aoc->num), "  Number: %u", aoc->num);
}
