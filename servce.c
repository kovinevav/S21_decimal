#include "math.h"

int get_exponemt(float num) {
    int exp = 0;
    while (round(num) != num) {
        num *= 10;
        exp++;
    }

    return exp;   
}