/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 26, 2023
 */

#include <ao/aopf.h>

extern unsigned mul3or5(int num);

typedef struct aocase {
	int num;
	unsigned expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	unsigned actual = mul3or5(aoc->num);
    return aopf_uint_eq(aoc->expected, actual, "  Number: %i", aoc->num);
}
