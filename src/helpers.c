#include "mathium/helpers.h"

unsigned long long sqrt_h(unsigned long long n) {
    if (n == 0 || n == 1) return n;

    long long x = n;
    long long next;

    while (1) {
        next = (x + n / x) / 2;
        if (next >= x)
            return x;
        x = next;
    }
}

long long pow_h(long long base, long long exp) {
    if (exp < 0) return -1;

    long long result = 1;

    while (exp > 0){
        if (exp % 2 == 1){
            result *= base;
        }
        base *= base;
        exp /= 2;
    }

    return result;
}