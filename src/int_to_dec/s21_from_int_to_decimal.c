#include "s21_from_int_to_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = 1;

  if (dst != NULL) {
    for (size_t i = 0; i < 4; i++) dst->bits[i] = 0;
    if (src < 0) {
      src = -src;
      dst->bits[3] |= MINUS;
    }
    dst->bits[0] = src;
    result = 0;
  }

  return result;
}
