/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Oct 12, 2023
 */

#include <ao/aopf.h>

extern const char *even_or_odd(int n);

typedef struct aocase {
	int n;
	const char *expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_str_eq(aoc->expected, even_or_odd(aoc->n), "  Number: %i", aoc->n);
}
