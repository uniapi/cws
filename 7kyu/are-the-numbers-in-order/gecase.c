/*
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Sep 8, 2023
 */
#include <stdbool.h>
#include <ge.h>

extern bool in_asc_order(const unsigned *v, size_t cnt);

typedef enum {
	GE_SHRT_O,
	GE_SHRT_U,
	GE_LONG_O,
	GE_LONG_U
} ge_t;

aocase_t *ge_case(aocase_t *aoc)
{
	size_t cnt, i;
	unsigned x = 0;
	ge_t gt;
	switch (gt = ge_uint_of(GE_SHRT_O, GE_LONG_U)) {
	case GE_SHRT_O:
		cnt = ge_uint_of(0, NLIM >> 4);
		break;
	case GE_SHRT_U:
		cnt = ge_uint_of(2, NLIM >> 4);
		break;
	case GE_LONG_O:
	case GE_LONG_U:
		cnt = ge_uint_of(NLIM >> 4, NLIM);
		break;
	}
	aoc->cnt = cnt;
	for (i = 0; i < cnt; ++i)
		x = aoc->v[i] = ge_uint_of(x, 999);
	if (gt == GE_SHRT_O || gt == GE_LONG_O)
		aoc->expected = true;
	else {
		i = ge_uint_of(0, cnt - 1);
		cnt = ge_uint_of_ex(0, cnt - 1, i);
		if (i > cnt)
			x = i, i = cnt, cnt = x;
		x = aoc->v[cnt];
		if (x == aoc->v[i])
			++aoc->v[i];
		else
			aoc->v[cnt] = aoc->v[i], aoc->v[i] = x;
		aoc->expected = false;
	}
	return aoc;
}
