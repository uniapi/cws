/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Sep 19, 2023
 */
#include <ao/aopf.h>
#include <string.h>

#define NLIM		288

extern char *vowelone(char *outp, const char *inp);

typedef struct aocase {
	char inp[NLIM];
	char expected[NLIM];
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char inp[NLIM], actual[NLIM];
	strcpy(inp, aoc->inp);
	aov_assert_ptrv(actual, vowelone(actual, inp));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->inp, inp));
    return aopf_str_eq(aoc->expected, actual, "   Input: \"%s\"", aoc->inp);
}
