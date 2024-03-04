#include "numerals.h"

#include <stdio.h>

uint8_t numeral_in[MAX_POS];
uint8_t numeral_out[MAX_POS];

void main(int argc, char **argv) {
  int8_t radix = 0;
  if (argc < 2) {
    dbg("USAGE: %s <ID>\n", argv[0]);
    return;
  }

  radix = id_string_to_numeral(argv[1], (uint8_t *)numeral_in);

  if (radix < 0) {
    dbg("Invalid input!\n");
    return;
  }
  __uint128_t id = numeral_to_uint((uint8_t *)numeral_in, radix) + 1;

  dbg("ID:%llu\n", id);
  dbg("RADIX:%d NUMERALS:", radix);
  for (size_t i = 0; i < MAX_POS; i++) {
    dbg("%d:%d ", i, numeral_in[i]);
  }
  dbg("\n");

  dbg("DEC: %llu\n", id);

  int8_t radix_out = uint_to_numeral(id, (uint8_t *)numeral_out, radix);

  char ans[50] = {0};

  numeral_to_id_string(ans, (uint8_t *)numeral_out, radix_out);

  printf("OUTPUT: %s\n", ans);
  return;
}