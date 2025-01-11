/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jan 9, 2025
 */

#include <ao/aopf.h>
#include <inttypes.h>

#define ILEN	32

extern int32_t bvset(const uint8_t indices[], size_t len);

typedef struct aocase {
	size_t len;
	uint8_t indices[ILEN];
	int32_t expected;
	int32_t actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	int i;
	fstderr("Expected: %"PRId32"\n*Actual*: %"PRId32"\n  Indices: [", aoc->expected, aoc->actual);
	for (i = 0; i < aoc->len; ++i)
		fstderr("%s  %02"PRIu8, (!(i & 7) ? "\n  " : ""), aoc->indices[i]);
	fstderr("\n  ]\n");
}

aop_t assert_case(aocase_t *aoc)
{
	uint8_t indices[ILEN];
	memcpy(indices, aoc->indices, aoc->len);
	aoc->actual = bvset(indices, aoc->len);
	aov_assert_memv(aoc->indices, indices, aoc->len, sizeof(uint8_t));
    return aop_int_eq(aoc->expected, aoc->actual);
}
