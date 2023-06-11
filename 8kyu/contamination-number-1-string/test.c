/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jun 11, 2023
 */

#include <ao/aopf.h>

extern char *contamination(char *outp, const char *text, char mutation);

#define TEXT_LIM	512

typedef struct aocase {
	char text[TEXT_LIM];
	char mutation;
	char expected[TEXT_LIM];
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char text[TEXT_LIM];
	char actual[TEXT_LIM];
	strcpy(text, aoc->text);
	aov_assert_ptrv(actual, contamination(actual, text, aoc->mutation));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->text, text));
    return aopf_str_eq(aoc->expected, actual, "  Text: \"%s\"\n  Mutation: \'%c\'\n", aoc->text, aoc->mutation);
}
