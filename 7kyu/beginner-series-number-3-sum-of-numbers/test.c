/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 3, 2018
 */

#include <ao/aopf.h>

extern long long get_sum(int a, int b);

typedef struct aocase {
	int a;
	int b;
	long long expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	long long actual = get_sum(aoc->a, aoc->b);
    return aopf_llong_eq(aoc->expected, actual, "    a: %i\n    b: %i", aoc->a, aoc->b);
}
