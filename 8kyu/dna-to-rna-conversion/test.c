/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jan 6, 2019
 */

#include <ao/aopf.h>

extern char *dna2rna(char *rna, const char *dna);

#define STRLIM	259

typedef struct aocase {
	char dna[STRLIM];
	char expected[STRLIM];
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char dna[STRLIM], actual[STRLIM];
	strcpy(dna, aoc->dna);
	aov_assert_ptrv(actual, dna2rna(actual, aoc->dna));
	aov_assert(AOV_MEMV, aop_str_eq(aoc->dna, dna));
    return aopf_str_eq(aoc->expected, actual, "     DNA: \"%s\"", aoc->dna);
}
