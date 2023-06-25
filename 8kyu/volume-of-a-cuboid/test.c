/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Nov 24, 2018
 */

#include <ao/aopf.h>

extern double get_volume_of_cuboid(double length, double width, double height);

typedef struct aocase {
	double length;
	double width;
	double height;
	double expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_dbl_eq (
		aoc->expected, get_volume_of_cuboid(aoc->length, aoc->width, aoc->height), 1e-12, 1e-100,
		"\nLength: %g\nWidth:  %g\nHeight: %g",
		aoc->length, aoc->width, aoc->height
	);
}
