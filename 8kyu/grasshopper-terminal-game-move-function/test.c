/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jul 4, 2023
 */

#include <ao/aopf.h>

extern unsigned short move(unsigned short pos, unsigned short roll);

typedef struct aocase {
	unsigned short pos;
	unsigned short roll;
	unsigned short expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_ushrt_eq(
		aoc->expected, move(aoc->pos, aoc->roll),
		"    pos: %hu\n    roll: %hu",
		aoc->pos, aoc->roll
	);
}
