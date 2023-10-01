/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Oct 1, 2023
 */

#include <ge.h>
#include <stdlib.h>

aocase_t *ge_case(aocase_t *aoc)
{
	size_t n = ge_uint_of(0, NLIM);
	size_t i, j;
	int x;
	aoc->n = n;
	aoc->nums[0] = ge_int_of(-100, 100);
	aoc->expected = 0;
	for (i = 1; i < n; ++i) {
		x = aoc->nums[i - 1];
		aoc->nums[i] = x + ge_int_of(1, 5);
		aoc->expected += abs(aoc->nums[i] - x - 1);
	}
	n = ge_uint_of(0, n >> 1);
	while (n-- > 1) {
		i = ge_uint_of(0, n);
		j = ge_uint_of_ex(0, n , i);
		x = aoc->nums[i];
		aoc->nums[i] = aoc->nums[j];
		aoc->nums[j] = x;
	}
	return aoc;
}
