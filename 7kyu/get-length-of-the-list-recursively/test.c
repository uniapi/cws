/*
 *        Written by Ali Muhammed
 *           uniapi@outlook.com
 *              Dec 19, 2018
 */

#include <ao/aopf.h>
#include <stdlib.h>
#include <alloca.h>
#include <ge.h>
#include "defs.h"

extern size_t len_r(const struct node *list);

#define DATALEN		1000

typedef struct aocase {
	int data[DATALEN];
	size_t expected;
	size_t actual;
	struct node *list;
} aocase_t;

struct node *listctr(const int data[], size_t n)
{
	size_t *ndx, i;
	struct node *list, *head;
	if (!n)
		return NULL;
	ndx = alloca(sizeof(size_t) * n);
	list = calloc(n, sizeof(struct node));
	if (!ndx || !list)
		return NULL;
	for (i = 0; i < n; ++i)
		ndx[i] = i;
	head = list;
	while (n--) {
		head->data = data[i];
		if (n) {
			i = ge_ullong_of(1, n);
			head->next = list + ndx[i];
			head = head->next;
			ndx[i] = ndx[n];
		}
	}
	head->next = NULL;
	return list;
}

void at_case_fail(const aocase_t *aoc)
{
	size_t i, n = aoc->expected;
	fstderr("Expected: %zu\n*Actual*: %zu\n    List: ", aoc->expected, aoc->actual);
	for (i = 0; i < n; ++i)
		fstderr("%s%i", (i ? " -> " : ""), aoc->data[i]);
	fstderr("\n");
}

void at_case_exit(aocase_t *aoc)
{
	if (aoc->list)
		free(aoc->list);
}

aop_t assert_case(aocase_t *aoc)
{
	aoc->list = listctr(aoc->data, aoc->expected);
	if (!aoc->list && aoc->expected)
	    return AOP_SKIP;
	aoc->actual = len_r(aoc->list);
	return aop_size_eq(aoc->expected, aoc->actual);
}
