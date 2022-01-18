/*
 *        Written by Ali Muhammed
 *          uniapi@outlook.com
 *             Jan 18, 2022
 */

#include <ao/aopf.h>

extern long long pentagonal(long long n);

typedef struct aocase {
	long long n;
	long long expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	return aopf_llong_eq(aoc->expected, pentagonal(aoc->n), "  Number: %lld", aoc->n);
}
