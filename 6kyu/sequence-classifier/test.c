/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Feb 18, 2024
 */

#include <ao/aopf.h>

typedef enum {
	UNORDERED,
	STRICTLY_INCREASING,
	NOT_DECREASING,
	STRICTLY_DECREASING,
	NOT_INCREASING,
	CONSTANT
} seq_t;

extern seq_t seqclass(const unsigned *seq, size_t cnt);

#define CNTMAX		256

#define SEQ2STR(seq)	\
	(seq == CONSTANT ? "Constant" : \
		seq & 1 ? seq >> 1 ? "Strictly Decreasing" : "Striclty Increasing" : \
		seq == UNORDERED ? "Unordered" : seq >> 2 ? "Not Increasing" : "Not Decreasing" \
	) \

typedef struct aocase {
	size_t cnt;
	const unsigned *seq;
	seq_t expected;
	seq_t actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	size_t i;
	fstderr("Expected: %s\n*Actual*: %s\n  Sequence: [", SEQ2STR(aoc->expected), SEQ2STR(aoc->actual));
	for (i = 0; i < aoc->cnt; ++i) {
		if (!(i & 7))
			fstderr("\n    ");
		fstderr(" %8i", aoc->seq[i]);
	}
	fstderr("\n  ]\n  Count: %zu\n", aoc->cnt);
}

aop_t assert_case(aocase_t *aoc)
{
	unsigned seq[CNTMAX];
	memcpy(seq, aoc->seq, sizeof(unsigned) * aoc->cnt);
	aoc->actual = seqclass(seq, aoc->cnt);
	aov_assert_memv(aoc->seq, seq, aoc->cnt, sizeof(unsigned));
    return aop_expr(aoc->expected == aoc->actual);
}
