#include <mathplus/number-theory.h>
#include <stdlib.h>

bool is_prime(long long n){
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

unsigned long long gcd(long long a, long long b){
    a = llabs(a);
    b = llabs(b);

    while (b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

unsigned long long lcm(long long a, long long b){
    if (a == 0 || b == 0) return 0;

    a = llabs(a);
    b = llabs(b);

    unsigned long long result = ((a / gcd(a, b)) * b);

    return result;
}