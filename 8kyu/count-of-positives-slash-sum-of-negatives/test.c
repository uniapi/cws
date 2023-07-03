/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jul 3, 2023
 */

#include <ao/aopf.h>

extern void cntpos_sumneg(const int *v, size_t cnt, size_t *poscnt, int *negsum);

#define MAXCNT	67

typedef struct {
	size_t poscnt;
	int negsum;
} assertion;

typedef struct aocase {
	size_t cnt;
	int v[MAXCNT];
	assertion expected;
	assertion actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("[Expected]\n    poscnt: %zu\n    negsum: %i\n", aoc->expected.poscnt, aoc->expected.negsum);
	fstderr("[*Actual*]\n    poscnt: %zu\n    negsum: %i\n", aoc->actual.poscnt, aoc->actual.negsum);
	fstderr("\nVector: [");
	for (i = 0; i < aoc->cnt; ++i)
		fstderr("%s  %4i", (!(i & 7) ? "\n    " : ""), aoc->v[i]);
	fstderr("\n]\nCount: %zu\n", aoc->cnt);

}

aop_t assert_case(aocase_t *aoc)
{
	int v[MAXCNT];
	memcpy(v, aoc->v, sizeof(int) * aoc->cnt);
	cntpos_sumneg(aoc->v, aoc->cnt, &aoc->actual.poscnt, &aoc->actual.negsum);
	aov_assert_memv(aoc->v, v, aoc->cnt, sizeof(int));
    return aop_expr(aoc->expected.poscnt == aoc->actual.poscnt && aoc->expected.negsum == aoc->actual.negsum);
}
