#include <mathplus/number-theory/prime.h>

bool is_prime(unsigned long long n){
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;

    unsigned long long i = 5;

    while (i * i <= n){
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
        i = i + 6;
    }

    return true;
}