#ifndef DECTYPE_H
#define DECTYPE_H

#include <stdint.h>
#include <stdio.h>

#define LDCOUNT 7
#define MINUS 0x80000000  // 10000000 00000000 00000000 00000000
#define SCALE 0x00ff0000  // 00000000 11111111 00000000 00000000

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  uint64_t bits[LDCOUNT];
  uint16_t scale;
  char sign;
} longDec;

longDec decimal_to_longDec(const s21_decimal *dec);
s21_decimal longDec_to_decimal(longDec *ld);
int longDec_uint32(longDec *ld);
void longDec_normalize(longDec *ld);

// int longDec_read_n_int(longDec *ld, int n);

// void decimal_hard_shift_right(s21_decimal *dec);

#endif