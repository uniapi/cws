/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jul 5, 2023
 */

#include <ao/aopf.h>

#define N	10

extern bool validate_battlefield(const int field[N][N]);

#define BOOLFMT(b)	((b) ? "true" : "false")

typedef struct aocase {
	int field[N][N];
	bool expected;
	bool actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	int i, j;
	fstderr("Expected: %s\n*Actual*: %s\n  Field:\n", BOOLFMT(aoc->expected), BOOLFMT(aoc->actual));
	for (i = 0; i < N; ++i) {
		fstderr("\t[ ");
		for (j = 0; j < N; ++j)
			fstderr("%c ", aoc->field[i][j] ? '1' : '.');
		fstderr("]\n");
	}
	fstderr("\n");
}

aop_t assert_case(aocase_t *aoc)
{
	aoc->actual = validate_battlefield(aoc->field);
    return aop_bool_eq(aoc->expected, aoc->actual);
}
