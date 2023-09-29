/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Sep 28, 2023
 */

#include <ge.h>

aocase_t *ge_case(aocase_t *aoc)
{
	const char cnss[] = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
	const char vwls[] = "AEIOUaeiou";
	const char payload2[] = "[\\]^_`{|}~";
	size_t len = ge_uint_of(0, SLIM - 2);
	char *s = aoc->src;
	char *e = aoc->expected;
	while (len--) {
		unsigned ge = ge_uint_of(0, 5);
		if (!ge)
			*e++ = *s++ = ' ';
		else if (ge < 2)
			*s++ = vwls[ge_uint_of(0, sizeof vwls - 2)];
		else if (ge < 5)
			*e++ = *s++ = cnss[ge_uint_of(0, sizeof cnss - 2)];
		else
			*e++ = *s++ = ge_uint_of(0, 1) ? payload2[ge_uint_of(0, sizeof payload2 - 2)] : ge_uint_of('!', '@');
	}
	*e = *s = '\0';
	return aoc;
}
