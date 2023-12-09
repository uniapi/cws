/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 9, 2023
 */

#include <ao/aopf.h>

extern bool is_leap_year(unsigned year);

typedef struct aocase {
	unsigned year;
	bool expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	bool actual = is_leap_year(aoc->year);
    return aopf_bool_eq(aoc->expected, actual, "  Year: %u", aoc->year);
}
