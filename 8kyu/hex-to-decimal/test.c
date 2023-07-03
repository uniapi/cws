/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Dec 22, 2018
 */

#include <ao/aopf.h>

extern unsigned long hex2dec(const char *hex);

#define HEXLEN		17

typedef struct aocase {
	char hex[HEXLEN];
	unsigned long expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	unsigned long actual;
	char hex[HEXLEN];
	strcpy(hex, aoc->hex);
	actual = hex2dec(hex);
	aov_assert(AOV_MEMV, aop_str_eq(hex, aoc->hex));
    return aopf_ulong_eq(aoc->expected, actual, "    Hex: \"%s\"", aoc->hex);
}
