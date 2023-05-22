/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               May 21, 2023
 */

#include <ao/aopf.h>

extern int cockroach_speed(double s);

typedef struct aocase {
	double speed;
	int expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_int_eq(
		aoc->expected, cockroach_speed(aoc->speed), "   Speed: %.2lf\n", aoc->speed
	);
}
