/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Sep 9, 2021
 */

#include <ao/aopf.h>
#include "defs.h"

extern loc_t mineloc(const unsigned *field, size_t n);

#define NMAX	9

typedef struct aocase {
	size_t n;
	const unsigned *field;
	loc_t expected;
	loc_t actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	fstderr("Expected: [%zu, %zu]\n*Actual*: [%zu, %zu]\n   Field: %zux%zu\n",
		aoc->expected.i, aoc->expected.j, aoc->actual.i, aoc->actual.j, aoc->n, aoc->n
	);
}

aop_t assert_case(aocase_t *aoc)
{
	unsigned field[NMAX * NMAX];
	memcpy(field, aoc->field, aoc->n * aoc->n * sizeof(unsigned));
	aoc->actual = mineloc(field, aoc->n);
	aov_assert_memv(aoc->field, field, aoc->n * aoc->n, sizeof(unsigned));
    return aop_expr(aoc->expected.i == aoc->actual.i && aoc->expected.j == aoc->actual.j);
}
