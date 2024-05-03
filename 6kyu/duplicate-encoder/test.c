/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               May 3, 2024
 */

#include <ao/aopf.h>

extern char *dupenc(char *outp, const char *src);

#define SLIM	260

typedef struct aocase {
	const char *src;
	const char *expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char src[SLIM], actual[SLIM];
	*actual = '\0';
	strcpy(src, aoc->src);
	aov_assert_ptrv(actual, dupenc(actual, src));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->src, src));
    return aopf_str_eq(aoc->expected, actual, "  String: \"%s\"", aoc->src);
}
