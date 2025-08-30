/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Aug 30, 2025
 */

#include <ao/aopf.h>

extern int jumps(int start, int finish);

typedef struct aocase {
	int start;
	int finish;
	int expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	int actual = jumps(aoc->start, aoc->finish);
	return aopf_int_eq(aoc->expected, actual, "    Start:  %i\n    Finish: %i\n", aoc->start, aoc->finish);
}
