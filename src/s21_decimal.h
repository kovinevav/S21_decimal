#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#include <string.h>
#include <stdio.h>
#include <stdint.h>


/* bits[0], bits[1], и bits[2] содержат младшие, средние и старшие 32 бита 96-разрядного целого числа соответственно.
bits[3] содержит коэффициент масштабирования и знак и состоит из следующих частей:
    Биты от 0 до 15, младшее слово, не используются и должны быть равны нулю.
    Биты с 16 по 23 должны содержать показатель степени от 0 до 28, который указывает степень 10 для разделения целого числа.
    Биты с 24 по 30 не используются и должны быть равны нулю.
    Бит 31 содержит знак; 0 означает положительный, а 1 означает отрицательный. */

typedef struct {
    int bits[4];
} s21_decimal;

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);



#endif  // S21_DECIMAL_H

