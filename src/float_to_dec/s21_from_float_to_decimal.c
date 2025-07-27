#include "s21_from_float_to_decimal.h"

// int s21_from_float_to_decimal(float src, s21_decimal *dst) {
//   uint32_t bits = *(uint32_t *)&src;

//   // Извлекаем знак (1 для отрицательных)
//   int sign = (bits >> 31) & 1;

//   // Извлекаем экспоненту (смещение 127)
//   int exponent = ((bits >> 23) & 0xFF) - 127;

//   // Извлекаем мантиссу (добавляем ведущую 1)
//   uint32_t mantissa = (bits & 0x7FFFFF) | 0x800000;

//   // Пример: для числа 1.23 (мантисса = 1.23, экспонента = 0)
//   uint64_t decimal_mantissa = mantissa;
//   int scale = 23 - exponent;  // Корректируем масштаб

//   // Заполняем s21_decimal
//   dst->bits[0] = (uint32_t)(decimal_mantissa & 0xFFFFFFFF);
//   dst->bits[1] = (uint32_t)((decimal_mantissa >> 32) & 0xFFFFFFFF);
//   dst->bits[2] = 0;  // Старшие биты (если нужно)
//   dst->bits[3] = (sign << 31) | (scale << 16);  // Знак + масштаб

//   return 0;
// }