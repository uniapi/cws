/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 22, 2018
 */

#include <ao/aopf.h>

extern unsigned long bin2dec(const char *bin);

#define BINLEN		0x41

typedef struct aocase {
	char bin[BINLEN];
	unsigned long expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	unsigned long actual;
	char bin[BINLEN];
	strcpy(bin, aoc->bin);
	actual = bin2dec(bin);
	aov_assert(AOV_MEMV, aop_str_eq(aoc->bin, bin));
    return aopf_ulong_eq(aoc->expected, actual, "  Binary: \"%s\"", aoc->bin);
}
