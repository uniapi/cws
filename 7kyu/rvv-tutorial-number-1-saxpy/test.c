/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jun 11, 2023
 */

#include <ao/aopf.h>

extern float *saxpy(float *c, const float *x, const float *y, size_t len, float a);

#define NUMS_LIM	92

typedef struct aocase {
	size_t len;
	float a;
	float x[NUMS_LIM];
	float y[NUMS_LIM];
	float expected[NUMS_LIM];
	float actual[NUMS_LIM];
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	const char *fmt[] = { "Expected", "*Actual*", "x", "y" };
	const float *nums[] = { aoc->expected, aoc->actual, aoc->x, aoc->y };
	const size_t n = sizeof fmt / sizeof(char *);
	size_t i, ni = 0;
	if (aoc->actual[aoc->len]) {
		fstderr("Incorrect Behaviour: memory written behind the length!\n");
		return;
	}
	do {
		fstderr("%s: [", fmt[ni]);
		for (i = 0; i < aoc->len; ++i)
			fstderr("%s %6.2lf", (!(i & 7) ? "\n     " : ""), nums[ni][i]);
		fstderr("\n]\n");
	}
	while (++ni < n);
	fstderr("Length: %zu\na: %.2lf\n", aoc->len, aoc->a);
}

aop_t assert_case(aocase_t *aoc)
{
	float x[NUMS_LIM], y[NUMS_LIM];
	size_t i;
	memcpy(x, aoc->x, aoc->len * sizeof(float));
	memcpy(y, aoc->y, aoc->len * sizeof(float));
	aoc->expected[aoc->len] = aoc->actual[aoc->len] = 0;
	aov_assert_ptrv(aoc->actual, saxpy(aoc->actual, x, y, aoc->len, aoc->a));
	aov_assert_memv(aoc->x, x, aoc->len, sizeof(float));
	aov_assert_memv(aoc->y, y, aoc->len, sizeof(float));
	if (aoc->actual[aoc->len])
		return AOP_FAIL;
	for (i = 0; i < aoc->len; ++i)
		if (aop_flt_eq(aoc->expected[i], aoc->actual[i], 1e-6, 1e-50) == AOP_FAIL)
			return AOP_FAIL;
    return AOP_PASS;
}
