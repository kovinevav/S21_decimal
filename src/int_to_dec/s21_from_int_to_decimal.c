#include "s21_from_int_to_decimal.h"

// int s21_from_int_to_decimal(int src, s21_decimal *dst) {
//   int unsver = 1;

//   if (dst != NULL) {
//     memset(dst, 0, sizeof(dst));
//     int bit = 31;
//     if (src < 0) {
//       src = -src;
//       dst->bits[3] |= 1 << bit;
//     }
//     dst->bits[0] = src;
//     unsver = 0;
//   }

//   return unsver;
// }