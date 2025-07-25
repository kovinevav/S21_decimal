#include "../s21_decimal.h"
int get_exponent(s21_decimal value) {
    // Биты с 16 по 23 должны содержать показатель степени от 0 до 28
    return (value.bits[3] >> 16) & 0xFF;
}

void reducton_exponent(s21_decimal* value_1, s21_decimal* value_2) {
    //Приводим экспоненты к одинаковому значению
    uint8_t exponent_1 = (value_1->bits[3]) >> 16 & 0xFF;
    uint8_t exponent_2 = (value_2->bits[3]) >> 16 & 0xFF;

    int8_t diff  = exponent_1 - exponent_2;

}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (get_exponent(value_1) != get_exponent(value_2)){

        //Экспоненты могут ыть разными, нужно привести  к одной

    };

    int carry = 0;
    for (int i = 0; i < 3; i++) {
        uint64_t sum = value_1.bits[i] + value_2.bits[i] + carry;
        result->bits[i] = sum & 0xFFFFFFFF;
        carry = sum >> 32;
    }
    if (carry != 0) {
        // Возможно переполнение? Что делать???
    }


    return 0;
}