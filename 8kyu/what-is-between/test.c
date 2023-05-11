/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jan 22, 2023
 */

extern int *between(int *integers, int a, int b);

#define LIM		0x1000

typedef struct aocase {
	size_t n;
    int a;
	int b;
	int expected[LIM];
	int actual[LIM];
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	const char *descr[] = { "Expected", "*Actual*" };
	const int *integers[] = { aoc->expected, aoc->actual };
	size_t i, j;
	for (i = 0; i < 2; ++i) {
		fstderr("%s: [", descr[i]);
		for (j = 0; j < aoc->n; ++j) {
			if (!(j & 7))
				fstderr("\n  ");
			fstderr(" %4i ", integers[i][j]);
		}
		fstderr("\n]\n");
	}
	fstderr("a: %i, b: %i\n", aoc->a, aoc->b);
}

aop_t assert_case(aocase_t *aoc)
{
	aov_assert_ptrv(aoc->actual, between(aoc->actual, aoc->a, aoc->b));
    return aop_mem_eq(aoc->expected, aoc->actual, aoc->n, sizeof(int));
}
