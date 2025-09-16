#include <mathium/number-theory.h>
#include <stdlib.h>
#include <string.h>

bool is_prime(unsigned long long n){
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;

    long long i = 5;

    while (i * i <= n){
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
        i = i + 6;
    }

    return true;
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
    while (b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

unsigned long long lcm(unsigned long long a, unsigned long long b){
    if (a == 0 || b == 0) return 0;

    unsigned long long result = ((a / gcd(a, b)) * b);

    return result;
}

size_t prime_factors(unsigned long long n, unsigned long long factors[], size_t maxfactors){
    memset(factors, 0, maxfactors * sizeof(unsigned long long));
    size_t count = 0;

    while (n % 2 == 0){
        factors[count] = 2;
        n = n / 2;
        count++;
    }

    unsigned long long divisor = 3;

    while (divisor * divisor <= n){
        while (n % divisor == 0){
            if (count >= maxfactors) return count;
            factors[count] = divisor;
            n = n / divisor;
            count++;
        }
        divisor = divisor + 2;
    }

    if (n > 1 && count < maxfactors) factors[count] = n;
    return count;
}