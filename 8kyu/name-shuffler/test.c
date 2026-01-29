/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jan 27, 2026
 */

#include <ao/aopf.h>

extern const char *name_shuffler(char *shuffled, const char *name);

#define NLIM	257

typedef struct aocase {
	const char *name;
	const char *expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	char name[NLIM], actual[NLIM];
	aov_assert_ptrv(actual, name_shuffler(actual, strcpy(name, aoc->name)));
    return aopf_str_eq(aoc->expected, actual, "    Name: \"%s\"", aoc->name);
}
