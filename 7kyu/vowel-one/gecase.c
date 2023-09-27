/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Sep 19, 2023
 */
#include <ge.h>

aocase_t *ge_case(aocase_t *aoc)
{
	const char vwls[] = "aeiou";
	const char cnss[] = "bcdfghjklmnpqrstvwxyz";
	size_t n = ge_uint_of(1, NLIM - 2);
	aoc->expected[n] = aoc->inp[n] = '\0';
	while (n--)
		if (ge_uint_of(0, 3))
			aoc->expected[n] = '0', aoc->inp[n] = cnss[ge_uint_of(0, 20)];
		else
			aoc->expected[n] = '1', aoc->inp[n] = vwls[ge_uint_of(0, 4)];
	return aoc;
}
