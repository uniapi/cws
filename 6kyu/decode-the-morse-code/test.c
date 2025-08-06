/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jul 31, 2025
 */

#include <ao/aopf.h>

extern char *demorse(char *outp, const char *morse);

#define DELIM	128
#define MOLIM	(DELIM<<3)

typedef struct aocase {
	const char *morse;
	const char *expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char morse[MOLIM];
	char actual[DELIM];
	strcpy(morse, aoc->morse);
	aov_assert_ptrv(actual, demorse(actual, morse));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->morse, morse));
    return aopf_str_eq(aoc->expected, actual, "   Morse: \"%s\"", aoc->morse);
}
