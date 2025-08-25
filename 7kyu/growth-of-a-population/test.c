/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Aug 25, 2025
 */

#include <ao/aopf.h>

extern int nb_year(int p0, double percent, int aug, int p);

typedef struct aocase {
	int p0;
	double percent;
	int aug;
	int p;
	int expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	int actual = nb_year(aoc->p0, aoc->percent, aoc->aug, aoc->p);
    return aopf_int_eq
	(
		aoc->expected, actual,
		"  p0 : %i\n  %%  : %.17g\n  aug: %i\n  p  : %d",
		aoc->p0, aoc->percent, aoc->aug, aoc->p
	);
}
