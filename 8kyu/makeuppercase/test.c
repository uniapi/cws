/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jun 19, 2023
 */

#include <ao/aopf.h>
#include <alloca.h>

extern char *makeupper(char *outp, const char *s);

typedef struct aocase {
	const char *s;
	const char *expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	size_t len = strlen(aoc->s) + 1;
	char *actual = alloca(len);
	char *s = alloca(len);
	if (!actual || !s)
		return AOP_SKIP;
	strcpy(s, aoc->s);
	aov_assert_ptrv(actual, makeupper(actual, s));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->s, s));
    return aopf_str_eq(aoc->expected, actual, "  String: \"%s\"", aoc->s);
}
