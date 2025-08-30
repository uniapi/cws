/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Aug 30, 2025
 */

#include <ao/aopf.h>

extern char add_letters(const char *letters, size_t n);

#define LIM		288

typedef struct aocase {
	size_t n;
	const char *letters;
	char expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char letters[LIM];
	char actual;
	memcpy(letters, aoc->letters, aoc->n);
	actual = add_letters(letters, aoc->n);
	aov_assert_memv(aoc->letters, letters, aoc->n, sizeof(char));
    return aopf_char_eq(aoc->expected, actual, " Letters: \"%.*s\"", aoc->n, aoc->letters);
}
