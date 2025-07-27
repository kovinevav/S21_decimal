#ifndef DECTYPE_H
#define DECTYPE_H

#include <stdint.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  uint64_t bits[7];
  uint16_t scale;
  char sign;
} longDec;

#endif