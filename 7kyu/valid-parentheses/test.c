/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jan 26, 2026
 */

#include <ao/aopf.h>

#define SLIM	257

extern bool valid_parentheses(const char *s);

typedef struct aocase {
    const char *s;
	bool expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char s[SLIM];
	bool actual = valid_parentheses(strcpy(s, aoc->s));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->s, s));
    return aopf_bool_eq(aoc->expected, actual, "  String: %s", aoc->s);
}
