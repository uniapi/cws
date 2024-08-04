/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Aug 4, 2024
 */

#include <ao/aopf.h>

extern unsigned short missing_elem(const unsigned short elems[9]);

#define NELEM		9

typedef struct aocase {
	unsigned short elems[NELEM];
	unsigned short expected;
	unsigned short actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i = 0;
	fstderr("Expected: %hu\n*Actual*: %hu\n  Elements: [", aoc->expected, aoc->actual);
	fstderr(" %hu", aoc->elems[0]);
	while (++i < NELEM)
		fstderr(", %hu", aoc->elems[i]);
	fstderr(" ]\n");
}

aop_t assert_case(aocase_t *aoc)
{
	unsigned short elems[NELEM];
	aoc->actual = missing_elem(memcpy(elems, aoc->elems, sizeof(aoc->elems)));
	aov_assert_memv(aoc->elems, elems, NELEM, sizeof(unsigned short));
    return aop_ushrt_eq(aoc->expected, aoc->actual);
}
