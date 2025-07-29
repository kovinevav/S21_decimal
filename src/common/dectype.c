#include "dectype.h"

longDec decimal_to_longDec(const s21_decimal *dec) {
  longDec ld = {0};
  for (size_t i = 0; i < LDCOUNT; i++) {
    ld.bits[i] = 0;
    if (i < 3) ld.bits[i] &= dec->bits[i];
  }
  ld.sign = dec->bits[3] & MINUS;
  ld.scale = (dec->bits[3] & SCALE) >> 16;
  return ld;
}

// переводит в decimal первые 3 блока без проверок
s21_decimal longDec_to_decimal(longDec *ld) {
  if (longDec_uint32(ld)) perror("error");
  s21_decimal dec = {0};
  for (size_t i = 0; i < 3; i++) {
    dec.bits[i] = 0;
    dec.bits[i] |= ld->bits[i];
  }
  dec.bits[3] = 0;
  dec.bits[3] |= (ld->scale << 16);
  dec.bits[3] |= ld->sign << 31;
  return dec;
}

// приводит к int32_t
int longDec_uint32(longDec *ld) {
  uint64_t x = 0;
  for (size_t i = 0; i < LDCOUNT; i++) {
    ld->bits[i] += x;
    x = ld->bits[i] >> 32;
  }
  return x != 0;  // 1 - error, 0 - ok
}

// void longDec_dropZero(longDec *ld) {
//   while (ld->scale > 0 && ld->bits[0] % 10 == 0) {

//   }

// }

// ======== оказалась не нужна
// сдвигает мантиссу вправо на 1, не трогая bits[3]
// не проверяет ничего - просто двигает!
// void decimal_hard_shift_right(s21_decimal *dec) {
//   for (char i = 0; i < 2; i++) {
//     uint32_t tmp = dec->bits[i];
//     dec->bits[i] = tmp >> 1;
//     uint32_t maskBitRight = 1u;
//     uint32_t maskBitLeft = 1u << 31;
//     if (dec->bits[i+1] & maskBitRight)
//       dec->bits[i] |= maskBitLeft;
//   }
//   uint32_t tmp = dec->bits[2];
//   dec->bits[2] = tmp >> 1;
// }
