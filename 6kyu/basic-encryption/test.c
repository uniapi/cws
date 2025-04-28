/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Apr 28, 2025
 */

#include <ao/aopf.h>

extern char *encrypt(char *dest, const char *src, unsigned rule);

#define SLIM	512

typedef struct aocase {
    const char *src;
	unsigned rule;
	const char *expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char src[SLIM], actual[SLIM] = "";
	aov_assert_ptrv(actual, encrypt(actual, strcpy(src, aoc->src), aoc->rule));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->src, src));
    return aopf_str_eq(aoc->expected, actual, "  Source: \"%s\"\n  Rule: %u", aoc->src, aoc->rule);
}
