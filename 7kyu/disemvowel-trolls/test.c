/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Sep 28, 2023
 */

#include <ao/aopf.h>
#include <stdlib.h>

extern char *disemvowel(char *dest, const char *src);

#define SLIM	288

typedef struct aocase {
	char src[SLIM];
	char expected[SLIM];
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char src[SLIM], actual[SLIM];
	strcpy(src, aoc->src);
	aov_assert_ptrv(actual, disemvowel(actual, src));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->src, src));
    return aopf_str_eq(aoc->expected, actual, "  String: \"%s\"", aoc->src);
}
