/*
 *        Written by Ali Muhammed
 *           uniapi@outlook.com
 *              Nov 27, 2022
 */
#include <ao/aopf.h>
#include <stdbool.h>
#include <ctype.h>

extern bool allunique(const char *s);

#define STRLIM		264
#define BOOL_FMT(b)		((b) ? "true" : "false")

typedef struct aocase {
	char s[STRLIM];
	bool expected;
	bool actual;
} aocase_t;

void at_case_fail(const aocase_t *aoc)
{
	const char *asciitab[] = {
		"NULL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
		  "BS",  "HT",  "LF",  "VT",  "FF",  "CR",  "SO",  "SI",
		 "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
		 "CAN",  "EM", "SUB", "ESC",  "FS",  "GS",  "RS",  "US",
		  "SP",   "!",  "\"",   "#",   "$",   "%",   "&",   "'",
		   "(",   ")",   "*",   "+",   ",",   "-",   ".",   "/",
		   "0",   "1",   "2",   "3",   "4",   "5",   "6",   "7",
		   "8",   "9",   "':'",   ";",   "<",   "=",   ">",   "?",
		   "@",   "A",   "B",   "C",   "D",   "E",   "F",   "G",
		   "H",   "I",   "J",   "K",   "L",   "M",   "N",   "O",
		   "P",   "Q",   "R",   "S",   "T",   "U",   "V",   "W",
		   "X",   "Y",   "Z",   "[",  "\\",   "]",   "^",   "_",
		   "`",   "a",   "b",   "c",   "d",   "e",   "f",   "g",
		   "h",   "i",   "j",   "k",   "l",   "m",   "n",   "o",
		   "p",   "q",   "r",   "s",   "t",   "u",   "v",   "w",
		   "x",   "y",   "z",   "{",   "|",   "}",   "~", "DEL"
	};
	size_t i = 0;
	char c;
	fstderr("Expected: %s\n*Actual*: %s\n  Chars (Sym : Hex):", BOOL_FMT(aoc->expected), BOOL_FMT(aoc->actual));
	while (c = aoc->s[i]) {
		if (!(i++ & 7))
			fstderr("\n    ");
		fstderr("  %3s : %02X", asciitab[c], c);
	}
	fstderr("\n");
}

aop_t assert_case(aocase_t *aoc)
{
	char s[STRLIM];
	strcpy(s, aoc->s);
	aoc->actual = allunique(aoc->s);
	aov_assert(AOV_MEMV, aop_str_eq(aoc->s, s));
    return aop_bool_eq(aoc->expected, aoc->actual);
}
