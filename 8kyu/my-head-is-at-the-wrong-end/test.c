/* \uFDFD
 *         Written by Ali Muhammed
 *            uniapi@outlook.com
 *               Jan 29, 2026
 */

#include <ao/aopf.h>

extern void *fix_the_meerkat(void *arr, size_t typesz);

#define ARRAY(type, ...)	(const type[]){__VA_ARGS__}
#define MLIM	32

typedef struct aocase {
	size_t typesz;
	const void *arr;
	const void *expected;
	void *actual[3];
} aocase_t;

static __thread void *_head[MLIM], *_body[MLIM], *_tail[MLIM];

static void fmt(const char *what, const void *v, size_t typesz)
{
	if (!typesz)
		fstderr("%s: [%s][%s][%s]\n", what, ((char **)v)[0], ((char **)v)[1], ((char **)v)[2]);
	else if (typesz == 1)
		fstderr("%s: [%c][%c][%c]\n", what, ((char *)v)[0], ((char *)v)[1], ((char *)v)[2]);
	else if (typesz == 2)
		fstderr("%s: [%hd][%hd][%hd]\n", what, ((short *)v)[0], ((short *)v)[1], ((short *)v)[2]);
	else if (typesz == 4)
		fstderr("%s: [%d][%d][%d]\n", what, ((int *)v)[0], ((int *)v)[1], ((int *)v)[2]);
	else
		fstderr("%s: [%ld][%ld][%ld]\n", what, ((long *)v)[0], ((long *)v)[1], ((long *)v)[2]);
}

void at_case_fail(const aocase_t *aoc)
{
	fmt("Expected", aoc->expected, aoc->typesz);
	fmt("*Actual*", aoc->actual, aoc->typesz);
	fmt("   Input", aoc->arr, aoc->typesz);
}

aop_t assert_case(aocase_t *aoc)
{
	void *expected[3];
	if (!aoc->typesz) {
		strcpy(aoc->actual[0] = _tail, ((const char **)aoc->arr)[0]);
		strcpy(aoc->actual[1] = _body, ((const char **)aoc->arr)[1]);
		strcpy(aoc->actual[2] = _head, ((const char **)aoc->arr)[2]);
		expected[0] = _head, expected[1] = _body, expected[2] = _tail;
	}
	else {
		memcpy(aoc->actual, aoc->arr, aoc->typesz * 3);
		memcpy(expected, aoc->expected, aoc->typesz * 3);
	}
	aov_assert_ptrv(aoc->actual, fix_the_meerkat(aoc->actual, aoc->typesz ? aoc->typesz : sizeof(void *)));
	if (!aoc->typesz) {
		int i;
		for (i = 0; i < 3; ++i)
			if (aop_str_eq(((const char **)aoc->expected)[i], aoc->actual[i]) == AOP_FAIL)
				return AOP_FAIL;
	}
    return aop_mem_eq(expected, aoc->actual, 3, aoc->typesz ? aoc->typesz : sizeof(void *));
}
