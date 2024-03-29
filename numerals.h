#ifndef __NUMERALS_H__
#define __NUMERALS_H__

#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...)
#endif

#define NUM_LETTERS 19
#define NUM_DIGITS 9
#define MAX_POS 10
#define BASE (NUM_LETTERS * NUM_DIGITS)

int id_string_to_numeral(char *id_str, uint8_t *id_num);
__uint128_t numeral_to_uint(uint8_t *numeral, int8_t radix);
int uint_to_numeral(__uint128_t val, uint8_t *numeral, int8_t radix_in);
void numeral_to_id_string(char *str, uint8_t *numeral, int8_t radix);

#endif