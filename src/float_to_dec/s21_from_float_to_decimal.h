#ifndef S21_FLOAT_TO_DEC_H
#define S21_FLOAT_TO_DEC_H

// #include "../s21_decimal.h"
#include "../common/dectype.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst);
uint32_t float_2_bits(float src);
int get_sign(float src);
int get_mantissa(float src);
s21_decimal create_decimal(int sign, int mantissa, int exponent);

#endif