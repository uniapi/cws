/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jul 31, 2025
 */

#include <ao/aopf.h>
#include <inttypes.h>

extern uint32_t ipcnt(const char *ipstart, const char *ipend);

typedef struct aocase {
    const char *ipstart;
	const char *ipend;
	uint32_t expected;
	uint32_t actual;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
	aoc->actual = ipcnt(aoc->ipstart, aoc->ipend);
    return aopf_ulong_eq(aoc->expected, aoc->actual, "  IP start: \"%s\"\n  IP end:  \"%s\"", aoc->ipstart, aoc->ipend);
}
