/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 1, 2018
 */

#include <ao/aopf.h>

#define INPLIM		16

extern unsigned int getage(const char *inp);

typedef struct aocase {
	char inp[INPLIM];
	unsigned int expected;
	unsigned int actual;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char inp[INPLIM];
	strcpy(inp, aoc->inp);
	aoc->actual = getage(inp);
	aov_assert(AOV_MEMV, aop_str_eq(aoc->inp, inp));
    return aopf_uint_eq(aoc->expected, aoc->actual, "Input: \"%s\"", aoc->inp);
}
