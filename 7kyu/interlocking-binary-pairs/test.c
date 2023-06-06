/*
 *        Written by Ali Muhammed
 *           uniapi@outlook.com
 *              Nov 30, 2022
 */

#include <ao/aopf.h>

extern bool interlockable(unsigned long long a, unsigned long long b);

typedef struct aocase {
    unsigned long long a;
	unsigned long long b;
	bool expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	return aopf_bool_eq(aoc->expected, interlockable(aoc->a, aoc->b), "  a: %llu\n  b: %llu", aoc->a, aoc->b);
}
