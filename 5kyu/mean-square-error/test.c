/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Aug 8, 2025
 */

#include <ao/aopf.h>

extern double msqerr(const int a[], const int b[], size_t n);

#define ARRAY(...)		(const int[]){ __VA_ARGS__ }
#define NMAX			65

typedef struct aocase {
	size_t n;
	const int *a;
	const int *b;
	double expected;
	double actual;
} aocase_t;

void at_case_fail(aocase_t *aoc)
{
	const char *descr[] = { "A", "B" };
	const int *p[] = { aoc->a, aoc->b };
	int i, j;
	fstderr("Expected: %lf\n*Actual*: %lf\n", aoc->expected, aoc->actual);
	for (i = 0; i < 2; ++i) {
		printf("    %s: [", descr[i]);
		for (j = 0; j < aoc->n; ++j)
			printf("%s%4i", (!(j&7) ? "\n    " : "  "), p[i][j]);
		printf("\n    ]\n");
	}
	printf("    N: %zu\n", aoc->n);
}

aop_t assert_case(aocase_t *aoc)
{
	int a[NMAX], b[NMAX];
	memcpy(a, aoc->a, sizeof(int)*aoc->n);
	memcpy(b, aoc->b, sizeof(int)*aoc->n);
	aov_assert_memv(aoc->a, a, aoc->n, sizeof(int));
	aov_assert_memv(aoc->b, b, aoc->n, sizeof(int));
	aoc->actual = msqerr(a, b, aoc->n);
    return aop_dbl_eq(aoc->expected, aoc->actual, 1e-12, 1e-100);
}
