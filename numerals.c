#include "numerals.h"

const char numeral_l[NUM_LETTERS] = {'A', 'B', 'C', 'E', 'H', 'I', 'K',
                                     'L', 'N', 'O', 'P', 'R', 'S', 'T',
                                     'U', 'W', 'X', 'Y', 'Z'};
const char numeral_d[NUM_DIGITS] = {'1', '2', '3', '4', '5',
                                    '6', '7', '8', '9'};

int id_string_to_numeral(char *id_str, uint8_t *id_num) {
  int8_t radix = 0;
  uint8_t numeral[MAX_POS];
  char *num_chr[MAX_POS];
  // id_num = (uint8_t *)numeral;
  int i = 0;
  dbg("INPUT: %s \n", id_str);
  char *token;
  token = strtok(id_str, "-");

  while (token != NULL) {
    uint8_t digit = -1;
    uint8_t letter = -1;
    num_chr[radix] = token;
    dbg("_%s_", num_chr[radix]);
    if (!(isupper(num_chr[radix][0])) || !(isdigit(num_chr[radix][1])))
      return -2;
    dbg("parts: %c %c \n", num_chr[radix][0], num_chr[radix][1]);
    for (int l = 0; l < NUM_LETTERS; l++) {

      if (num_chr[radix][0] == numeral_l[l]) {
        dbg("1:%c ", num_chr[radix][0]);
        letter = l;
      }
    }
    for (int d = 0; d < NUM_DIGITS; d++) {
      if (num_chr[radix][1] == numeral_d[d]) {
        dbg("2:%c", num_chr[radix][1]);
        digit = d;
      }
    }
    if ((letter < 0) || (digit < 0))
      return -2;
    numeral[radix] = letter * NUM_DIGITS + digit;
    dbg("Numeral: %d\n", numeral[radix]);
    radix++;
    if (radix > MAX_POS)
      return -2;
    token = strtok(NULL, "-");
  }
  memcpy(id_num, numeral, MAX_POS);
  return radix;
}

__uint128_t numeral_to_uint(uint8_t *numeral, int8_t radix) {
  __uint128_t res0 = 0;
  __uint128_t res = 0;
  for (int i = 1; i <= radix; i++) {
    __uint128_t base = 1;
    for (int j = 0; j < radix - i; j++) {
      base *= BASE;
    }
    res0 = base * numeral[i - 1];
    dbg("I:%d ", i);
    dbg("BASER: %llu ", base);
    dbg("NUMERAL:%d ", numeral[i - 1]);
    dbg("RES: %llu \n", res0);
    res += res0;
  }
  dbg("RES: %llu \n", res);
  return res;
}

int uint_to_numeral(__uint128_t val, uint8_t *numeral, int8_t radix_in) {
  __uint128_t tmp = val;
  int8_t radix = 0;
  while (tmp != 0) {
    tmp /= BASE;
    radix++;
  }
  dbg("radix_out %d\n", radix);
  tmp = val;
  dbg("tmp:%llu\n", tmp);
  for (int i = 0; i < radix; i++) {
    dbg("i:%d", i);
    numeral[i] = (i == (radix - 1)) && (radix > radix_in) && ((tmp % BASE) == 1)
                     ? 0
                     : (tmp % BASE);
    dbg("NUM_OUT:%d \n", numeral[i]);
    tmp /= BASE;
  }
  if (radix_in > radix)
    radix = radix_in;
  return radix;
}

void numeral_to_id_string(char *str, uint8_t *numeral, int8_t radix) {
  int i = radix;
  dbg("NUMERALS_OUT:");
  char *p = str;
  for (int i = (radix - 1); i >= 0; i--) {

    int l = numeral[i] / NUM_DIGITS;
    int d = numeral[i] % NUM_DIGITS;
    dbg("DEC:%d CHAR %c%c\n", numeral[i], numeral_l[l], numeral_d[d]);
    p += sprintf(p, "%c%c", numeral_l[l], numeral_d[d]);
    if ((i - 1) >= 0)
      p += sprintf(p, "-");
  }
  dbg("\n");
}