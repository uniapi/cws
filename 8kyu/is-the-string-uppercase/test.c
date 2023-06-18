/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jun 18, 2023
 */

#include <ao/aopf.h>

extern bool is_upper(const char *s);

#define SLIM	280

typedef struct aocase {
	const char s[SLIM];
	bool expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char s[SLIM];
	bool actual = is_upper(strcpy(s, aoc->s));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->s, s));
	return aopf_bool_eq(aoc->expected, actual, "  String: \"%s\"", aoc->s);
}
