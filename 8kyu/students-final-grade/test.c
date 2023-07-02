/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jan 22, 2019
 */

#include <ao/aopf.h>

extern unsigned final_grade(unsigned exam, unsigned nproj);

typedef struct aocase {
	unsigned exam;
	unsigned nproj;
	unsigned expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	return aopf_uint_eq(
		aoc->expected, final_grade(aoc->exam, aoc->nproj),
		"  Exam Grade: %u\n  Projects: %u",
		aoc->exam, aoc->nproj
	);
}
