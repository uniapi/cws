/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               May 31, 2024
 */

#include <ao/aopf.h>

extern bool eleven(const char *num);

#define LIM		1000

typedef struct aocase {
	const char *num;
	bool expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char num[LIM+1];
	bool actual = eleven(strcpy(num, aoc->num));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->num, num));
    return aopf_bool_eq(aoc->expected, actual, "  Number: \"%s\"", aoc->num);
}
