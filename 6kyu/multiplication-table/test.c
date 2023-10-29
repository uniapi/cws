
/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               May 19, 2023
 */
#include <ao/aopf.h>

extern unsigned int *multab(unsigned int *tab, unsigned int n);

#define NLIM	0x50

typedef struct aocase {
	unsigned n;
	unsigned expected[NLIM][NLIM];
	unsigned actual[NLIM][NLIM];
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	const char *descr[] = { "Expected", "*Actual*" };
	const unsigned (*tab[2])[NLIM] = { (const unsigned (*)[NLIM])aoc->expected, aoc->actual };
	size_t i, j, n;
	for (n = 0; n < 2; ++n) {
		fstderr("%s: [\n", descr[n]);
		for (i = 0; i < aoc->n; ++i) {
			fprintf(stderr, "    [ ");
			for (j = 0; j < aoc->n; ++j)
				fprintf(stderr, "%s%u", (j ? ", " : ""), tab[n][i][j]);
			fprintf(stderr, " ]\n");
		}
	}
	fprintf(stderr, "]\nn: %u\n", aoc->n);
}

#undef NLIM

aop_t assert_case(aocase_t *aoc)
{
	aov_assert_ptrv(aoc->actual, multab((unsigned *)aoc->actual, aoc->n));
    return aop_mem_eq(aoc->actual, aoc->expected, aoc->n, sizeof(unsigned));
}
