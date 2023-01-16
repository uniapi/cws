#include <ao/aopf.h>

extern unsigned long long sumcubes(unsigned short n);

typedef struct aocase {
	unsigned short n;
	unsigned long long expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_ullong_eq(aoc->expected, sumcubes(aoc->n), "    n: %hu", aoc->n);
}
