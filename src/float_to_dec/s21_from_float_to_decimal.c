#include "s21_from_float_to_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int status = 1;
    if (dst != NULL) { //Изменить на функцию проверок:NaN, Infinity, денормализованным числом, слишком большой или слишком мал для представления в decimal
        int scale = get_scale(src);
        int mantissa = get_mantissa(src);
        int sign = get_sign(src);
        status = 0;
    }
    return status;
}

uint32_t float_2_bits(float src) {
    uint32_t result = 0;
    memcpy(&result, &src, sizeof(result));
    return result;
}

int get_sign(float src) {
    uint32_t bits = float_2_bits(src);
    int result = (bits >> 31) & 1;
}

int get_mantissa(float src) {
    uint32_t bits = float_2_bits(src);
    int mantissa = bits & 0x007FFFFF;     
    mantissa |= 0x00800000;           
    return mantissa;
}

int get_scale(float src) {
    uint32_t bits = float_2_bits(src);
    int scale = (bits >> 23) & 0xFF;
    return scale;
}

s21_decimal create_decimal(int sign, int mantissa, int exponent) {
    s21_decimal d_num = {0};
    d_num.bits[3] = (d_num.bits[3] >> 31) | sign;

   

    return d_num;



}