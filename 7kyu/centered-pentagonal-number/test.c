/*
 *        Written by Ali Muhammed
 *          uniapi@outlook.com
 *             Jan 18, 2022
 */

#include <ao/fmt.h>

extern long long pentagonal(long long n);

typedef struct aocase {
	long long n;
	long long expected;
	long long actual;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	aoc->actual = pentagonal(aoc->n);
	return aop_fmt_llong_eq
	(
		aoc->actual, aoc->expected,
		"*Actual*: %lld\nExpected: %lld\n  Number: %lld",
		aoc->actual, aoc->expected, aoc->n
	);
}
