#pragma once

#include <stdbool.h>
#include <stdlib.h>

unsigned long long gcd(unsigned long long a, unsigned long long b);
unsigned long long lcm(unsigned long long a, unsigned long long b);
bool is_prime(unsigned long long n);
size_t prime_factors(unsigned long long n, unsigned long long factors[], size_t maxfactors);
unsigned long long totient(unsigned long long n);