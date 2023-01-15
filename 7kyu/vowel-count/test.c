/*
 *        Written by Ali Muhammed
 *           uniapi@outlook.com
 *              Dec 16, 2018
 */

#include <ao/aopf.h>
#include <string.h>
#include <limits.h>

extern size_t vowelcnt(const char *s);

#define STRLEN (SCHAR_MAX * CHAR_BIT)

typedef struct aocase {
	char s[STRLEN];
	size_t expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char s[STRLEN];
	size_t actual = vowelcnt(strcpy(s, aoc->s));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->s, s));
    return aopf_ulong_eq(aoc->expected, actual, "  String: \"%s\"", aoc->s);
}
