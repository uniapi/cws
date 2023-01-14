#include <ao/aopf.h>
#include <limits.h>

extern unsigned long long sqrdigs(unsigned n);

typedef struct aocase {
	unsigned num;
	unsigned long long expected;
} aocase_t;

aop_t assert_case(aocase_t *aoc)
{
    return aopf_ullong_eq(aoc->expected, sqrdigs(aoc->num), "  Number: %u\n", aoc->num);
}
