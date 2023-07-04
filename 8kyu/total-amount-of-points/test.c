/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jan 2, 2019
 */

#include <ao/aopf.h>

extern int points(const char games[][4]);

typedef struct aocase {
	char games[10][4];
	int expected;
	int actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %i\n*Actual*: %i\n  Games:", aoc->expected, aoc->actual);
	for (i = 0; i < 10; ++i)
		fstderr("\n      { %s }", aoc->games[i]);
	fstderr("\n");
}

aop_t assert_case(aocase_t *aoc)
{
	char games[10][4];
	memcpy(games, aoc->games, 40);
	aoc->actual = points(games);
	aov_assert_memv(aoc->games, games, 4, 10);
    return aop_int_eq(aoc->expected, aoc->actual);
}
