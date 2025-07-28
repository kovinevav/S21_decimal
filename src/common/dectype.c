#include "dectype.h"

longDec decimal_to_longDec(const s21_decimal *dec) {
  longDec ld;
  uint64_t tmp;
  for (size_t i = 0; i < LDcount; i++) ld.bits[i] = 0;
  ld.bits[0] = dec->bits[0];
  tmp = dec->bits[1];
  ld.bits[0] &= tmp << 36;
  ld.bits[1] = dec->bits[2];
  ld.sign = dec->bits[3] & MINUS;
  ld.scale = (dec->bits[3] & SCALE) >> 16;
  return ld;
}
