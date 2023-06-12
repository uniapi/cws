/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jun 1, 2023
 */

#include <ao/aopf.h>

extern bool alphanum(const char *s);

#define SLIM	256

typedef struct aocase {
	char s[SLIM];
	bool expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	bool actual;
	char s[SLIM];
	strcpy(s, aoc->s);
	actual = alphanum(s);
	aov_assert(AOV_MEMV, aop_str_eq(aoc->s, s));
    return aopf_bool_eq(aoc->expected, actual, "  String: \"%s\"", aoc->s);
}
