#include "s21_from_float_to_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int unsver = 1;
    if (dst != NULL) {
        int scale = get_scale(src);
        int mantissa = get_mantissa(src);
        int sign = get_sign(src);
    }



    
return 0;
}